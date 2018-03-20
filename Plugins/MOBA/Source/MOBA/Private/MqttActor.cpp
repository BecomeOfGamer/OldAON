// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "MqttActor.h"


// Sets default values
AMqttActor::AMqttActor()
	:m_bInit(false), m_bDoReconnect(false),
	m_iConnectTimeout(20),
	m_bCleanSession(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.1;
	Mqtt_async_Win32_Init();//假定Actor的Create是單執行緒, 一定要呼叫此函數 mqtt static lib才會正常
}

// Called when the game starts or when spawned
void AMqttActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMqttActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//自動重連....
	if (m_bInit && IsConnected() != err_success)
	{
		//防止頻繁重連與誤判, 取跟timeout一樣的時間差值
		auto &&tpDiffSecs = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - m_tpConnect);
		if (tpDiffSecs > std::chrono::seconds(m_iConnectTimeout))
		{
			Stop_Consuming();
			Connect(m_iConnectTimeout, m_bCleanSession);
			m_bDoReconnect = true;
		}
	}

	if ( (!m_bInit || m_bDoReconnect) && IsConnected() == err_success)
	{
		m_bInit = true;
		m_bDoReconnect = false;
		Start_Consuming();
	}

	if (m_bInit)
	{
		FString sTopic, sMsg;
		while(Try_consume_message(sTopic, sMsg) ==  err_success)
			OnReceive(sTopic, sMsg);
	}
}

int32 AMqttActor::CreateClient(FString In_sClientID, FString In_sTcpAddress, int32 In_iPort)
{
	err_code err(err_success);

	if (m_async_client_ptr)
		err = err_fail;
	else
	{
		std::stringstream ss;
		std::string sTemp;
		ss << "tcp://" << TCHAR_TO_UTF8(*In_sTcpAddress) << ":" << In_iPort;
		ss >> sTemp;
		m_async_client_ptr = std::make_shared<mqtt::async_client>(sTemp, TCHAR_TO_UTF8(*In_sClientID));
	}
	return err;
}

int32 AMqttActor::DestroyClient()
{
	if (m_async_client_ptr)
		m_async_client_ptr.reset();
	m_bInit = false;

	return err_success;
}


int32 AMqttActor::Connect(int32 In_iTimeoutSec, bool In_bClean)
{
	err_code err((err_code)IsConnected());
	if (err == err_disconnecting)
	{
		mqtt::connect_options connOpts;
		connOpts.set_keep_alive_interval(In_iTimeoutSec);
		connOpts.set_clean_session(In_bClean);
		m_async_client_ptr->connect(connOpts);
		m_tpConnect = std::chrono::system_clock::now();
	}
	return err;
}

int32 AMqttActor::DisConnect()
{
	err_code err(err_success);

	if (m_async_client_ptr == nullptr)
		err = err_noncreate;
	else
		m_async_client_ptr->disconnect();

	m_bInit = false;

	return err;
}

int32 AMqttActor::IsConnected()
{
	err_code err(err_disconnecting);

	if (m_async_client_ptr == nullptr)
		err = err_noncreate;
	else if (m_async_client_ptr->is_connected())
		err = err_success;

	return err;
}

int32 AMqttActor::Start_Consuming()
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
		m_async_client_ptr->start_consuming();

	return err;
}

int32 AMqttActor::Stop_Consuming()
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
		m_async_client_ptr->stop_consuming();

	return err;
}

int32 AMqttActor::Try_consume_message(FString &Out_sTopic, FString &Out_sMsg)
{
	err_code err((err_code)IsConnected());
	bool bGotMsg(false);

	if (err == err_success)
	{
		err = err_fail;

		mqtt::const_message_ptr msgptr;
		if (m_async_client_ptr->try_consume_message(&msgptr))
		{
			auto bufref = msgptr->get_payload_ref();
			//Check Packet....
			if (bufref.length() > Packet::CompressPacketSize 
				&& ((Packet::CompressPacket *)bufref.data())->u32_StartCode == Packet::PACKET_START_CODE)
			{
				auto pPacket = *(Packet::CompressPacket *)bufref.data();
				if (pPacket.u16_CompressType == Packet::RAW)
				{
					Out_sTopic = msgptr->get_topic().c_str();
					Out_sMsg = (bufref.data() + Packet::CompressPacketSize);
					err = err_success;
					bGotMsg = true;
				}
				else
				{
					std::shared_ptr<char> Out_Buffer;
					if (Packet::DeCompressFromPacket(pPacket, bufref.data() + Packet::CompressPacketSize, Out_Buffer))
					{
						Out_sTopic = msgptr->get_topic().c_str();
						Out_sMsg = &(*Out_Buffer);
						err = err_success;
						bGotMsg = true;
					}
				}
			}

			if (!bGotMsg)
			{
				Out_sTopic = msgptr->get_topic().c_str();
				Out_sMsg = msgptr->to_string().c_str();
				err = err_success;
			}
		}
	}
	return err;
}

int32 AMqttActor::Subscribe(FString In_sTopic, int32 In_iQOS)
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
		m_async_client_ptr->subscribe(TCHAR_TO_UTF8(*In_sTopic), In_iQOS);

	return err;
}

int32 AMqttActor::UnSubscribe(FString In_sTopic)
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
		m_async_client_ptr->unsubscribe(TCHAR_TO_UTF8(*In_sTopic));

	return err;
}

int32 AMqttActor::Publish(FString In_sTopic, FString In_sMsg, int32 In_iQOS)
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
	{
		mqtt::message_ptr pubmsg = mqtt::make_message(TCHAR_TO_UTF8(*In_sTopic), TCHAR_TO_UTF8(*In_sMsg));
		pubmsg->set_qos(In_iQOS);
		m_async_client_ptr->publish(pubmsg);
	}
	return err;
}

int32 AMqttActor::Publish(FString In_sTopic, char *In_pBuf, size_t In_BufSize, int32 In_iQOS)
{
	err_code err((err_code)IsConnected());

	if (err == err_success)
	{
		mqtt::message_ptr pubmsg = mqtt::make_message(TCHAR_TO_UTF8(*In_sTopic), In_pBuf, In_BufSize);
		pubmsg->set_qos(In_iQOS);
		m_async_client_ptr->publish(pubmsg);
	}
	return err;
}