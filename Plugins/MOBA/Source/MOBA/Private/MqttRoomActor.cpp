// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "MOBAPlayerController.h"
#include "MqttRoomActor.h"
#include <Json.h>

AMqttRoomActor::AMqttRoomActor()
	:m_SequenceNumber(0)
{
	LocalController = nullptr;
	PrimaryActorTick.TickInterval = 1.0;

	//Being Command Function Map.....
	m_mapCmdFunc.Emplace("newplayer", std::bind(&AMqttRoomActor::NewHero, this, std::placeholders::_1));
	m_mapCmdFunc.Emplace("movecmd", std::bind(&AMqttRoomActor::HeroMove, this, std::placeholders::_1));
	m_mapCmdFunc.Emplace("delete", std::bind(&AMqttRoomActor::DeleteHero, this, std::placeholders::_1));
	//End Command Function Map.....
}

// Called every frame
void AMqttRoomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (IsConnected() != err_success)
		return;

	if (m_spRoomCmdPair.Get())
	{
		FString sAction;
		m_sRoomID = (*m_spRoomCmdPair).second;

		if ((*m_spRoomCmdPair).first == eRoomCMD::Create)
			sAction = "create";
		else
			sAction = "join";
		
		//Subscribe
		for (auto &iter : m_mapCmdFunc)
			Subscribe(iter.Key + "/" + m_sRoomID);
		Subscribe(sAction + "/" + m_sRoomID);

		//Publish - JSON
		TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
		RootObject->SetStringField("action", sAction);
		RootObject->SetStringField("key", m_sRoomID);

		FString OutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
		FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
		Publish("room", OutputString);

		m_spRoomCmdPair.Reset();
	}


	//開始判斷 new/delete HeroActor....
	TMap<FString, AHeroCharacter*> set_deleteHero(m_mapHeroActor);//先將所有ActorName 覆製一份
	TArray< TSharedPtr<FJsonValue> > ObjArray;

	for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AHeroCharacter* hero = *ActorItr;
		if (m_mapHeroActor.Contains(hero->ClientID))//原本存在的HeroActor就從刪除名單中移除
			set_deleteHero.Remove(hero->ClientID);
		else //New Hero...
			m_mapHeroActor.Emplace(hero->ClientID, hero);

		TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);

		RootObject->SetNumberField("team", 0);
		RootObject->SetStringField("id", hero->ClientID);
		RootObject->SetNumberField("hp", hero->CurrentHP);

		FVector &&pos = hero->GetActorLocation();
		RootObject->SetNumberField("x", pos.X);
		RootObject->SetNumberField("y", pos.Y);

		ObjArray.Add(MakeShareable(new FJsonValueObject(RootObject)));
	}

	//送出目前的HeroList
	if (ObjArray.Num() > 0)
	{
		TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
		RootObject->SetArrayField("hero", ObjArray);
		ObjArray.Empty();
		RootObject->SetArrayField("creep", ObjArray);
		FString OutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
		FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
		Publish("gamedata/" + m_sRoomID, OutputString);
	}
	

	////處理已經移除的Hero
	//if (set_deleteHero.Num() > 0)
	//{
	//	ObjArray.Empty();
	//
	//	//Sync MemberSet and Build JSON...
	//	for (auto &iter : set_deleteHero)
	//	{
	//		//Sync...
	//		m_mapHeroActor.Remove(iter.Key);
	//
	//		//Build...
	//		TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
	//
	//		RootObject->SetStringField("id", iter.Key);
	//		ObjArray.Add(MakeShareable(new FJsonValueObject(RootObject)));
	//	}
	//
	//	TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
	//	RootObject->SetArrayField("hero", ObjArray);
	//	FString OutputString;
	//	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	//	FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
	//
	//	std::stringstream ss;
	//	ss << "delete/" << TCHAR_TO_UTF8(*m_sRoomID);;
	//	Publish(ss.str().c_str(), OutputString);
	//}//end if (!set_deleteHero.empty())
}


void AMqttRoomActor::CreateRoom(FString In_RoomID)
{
	m_spRoomCmdPair = MakeShareable(new CmdPair(eRoomCMD::Create, In_RoomID));
}

void AMqttRoomActor::JoinRoom(FString In_RoomID)
{
	m_spRoomCmdPair = MakeShareable(new CmdPair(eRoomCMD::Join, In_RoomID));
}

void AMqttRoomActor::HandleMQTTMsg(const FString &In_sTopic, const FString &In_sPayload)
{
	FString cmd, roomid;
	if (In_sTopic.Split("/", &cmd, &roomid))
	{
		auto &&pFunc = m_mapCmdFunc.Find(cmd);
		if (pFunc)
		{
			auto &&pJsonObj = ParseJSON(In_sPayload);
			auto &&DoFunc = (*pFunc);
			DoFunc(pJsonObj);
		}
	}
}

TSharedPtr<FJsonObject> AMqttRoomActor::ParseJSON(const FString &In_sPayload)
{
	TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<TCHAR> > JsonReader = TJsonReaderFactory<TCHAR>::Create(In_sPayload);
	FJsonSerializer::Deserialize(JsonReader, RootObject);
	return RootObject;
}

void AMqttRoomActor::NewHero(TSharedPtr<FJsonObject> In_JsonObj)
{
	FVector loc;
	loc.X = In_JsonObj->GetNumberField("x");
	loc.Y = In_JsonObj->GetNumberField("y");
	loc.Z = 0;

	AHeroCharacter *pAHeroCharacter = GetWorld()->SpawnActor<AHeroCharacter>(SubHeroActor);
	if (IsValid(pAHeroCharacter))
	{
		pAHeroCharacter->SetActorLocation(loc);
		pAHeroCharacter->ClientID = In_JsonObj->GetStringField("id");
		pAHeroCharacter->CustomName = In_JsonObj->GetStringField("name");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("pAHeroCharacter is null")));
	}
}

void AMqttRoomActor::HeroMove(TSharedPtr<FJsonObject> In_JsonObj)
{
	auto HeroArray = In_JsonObj->GetArrayField("hero");
	
	for (auto &iter : HeroArray)
	{
		const TSharedPtr<FJsonObject> *cpJsonObject;
		if (iter->TryGetObject(cpJsonObject))
		{
			auto RealObject = *cpJsonObject;
			auto ppiter = m_mapHeroActor.Find(RealObject->GetStringField("id"));
			if (ppiter && IsValid(LocalController) && IsValid(*ppiter))
			{
				AHeroCharacter* pHero = *ppiter;

				FHeroAction act;
				act.ActionStatus = EHeroActionStatus::MoveToPosition;
				act.TargetVec1.X = RealObject->GetNumberField("x");
				act.TargetVec1.Y = RealObject->GetNumberField("y");
				act.TargetVec1.Z = 0;
				act.SequenceNumber = m_SequenceNumber++;

				LocalController->ServerSetHeroAction(pHero, act);
			}
		}
	}
}

void AMqttRoomActor::DeleteHero(TSharedPtr<FJsonObject> In_JsonObj)
{
	auto ppiter = m_mapHeroActor.Find(In_JsonObj->GetStringField("id"));
	if (ppiter && IsValid(*ppiter))
	{
		(*ppiter)->Destroy();
		m_mapHeroActor.Remove(In_JsonObj->GetStringField("id"));
	}
}