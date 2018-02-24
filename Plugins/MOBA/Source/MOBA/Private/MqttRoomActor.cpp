// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "MqttRoomActor.h"
#include <Json.h>

AMqttRoomActor::AMqttRoomActor()
{
	PrimaryActorTick.TickInterval = 0.1;
}

// Called every frame
void AMqttRoomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!m_listCMD.empty() && IsConnected() == err_success)
	{
		std::stringstream ss;
		std::string sTemp;
		std::string sAction;
		

		for (auto &iter : m_listCMD)
		{
			if (iter.first == eRoomCMD::Create)
				sAction = "create";
			else
				sAction = "join";

			//Subscribe
			ss.clear();
			sTemp.clear();
			ss << sAction<< "/" << TCHAR_TO_UTF8(*iter.second);
			ss >> sTemp;
			Subscribe(sTemp.c_str());

			//Publish - JSON
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
			RootObject->SetStringField("action", sAction.c_str());
			RootObject->SetStringField("key", iter.second);

			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
			Publish("room", OutputString);
		}

		m_listCMD.clear();
	}
}


void AMqttRoomActor::CreateRoom(FString In_RoomID)
{
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Create, In_RoomID));
}

void AMqttRoomActor::JoinRoom(FString In_RoomID)
{
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Join, In_RoomID));
}
