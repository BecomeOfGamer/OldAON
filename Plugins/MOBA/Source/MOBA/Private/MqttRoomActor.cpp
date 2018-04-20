// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "MOBA.h"
#include "MOBAPlayerController.h"
#include "MqttRoomActor.h"
#include "MOBAGameMode.h"
#include <Json.h>

AMqttRoomActor::AMqttRoomActor()
	:m_SequenceNumber(0), m_bCreated(false), m_pAMOBAGameMode(nullptr)
{
	if (Role == ROLE_Authority)
	{
		LocalController = nullptr;
		m_pAMHUD = nullptr;
		PrimaryActorTick.TickInterval = 1.0;

		//Being Command Function Map.....
		m_mapCmdFunc.Emplace("newplayer", std::bind(&AMqttRoomActor::NewHero, this, std::placeholders::_1));
		m_mapCmdFunc.Emplace("movecmd", std::bind(&AMqttRoomActor::HeroMove, this, std::placeholders::_1));
		m_mapCmdFunc.Emplace("delete", std::bind(&AMqttRoomActor::DeleteHero, this, std::placeholders::_1));
		//m_mapCmdFunc.Emplace("test", std::bind(&AMqttRoomActor::Reset, this, std::placeholders::_1));
		//End Command Function Map.....
	}
}

// Called every frame
void AMqttRoomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Role == ROLE_Authority)
	{
		if (IsConnected() != err_success)
		{
			//Reset(nullptr);
			return;
		}

		if (m_spRoomCmdPair.Get() && !m_bCreated)
		{
			FString sAction;
			m_sRoomID = (*m_spRoomCmdPair).second;

			if ((*m_spRoomCmdPair).first == eRoomCMD::Create)
				sAction = "create";
			else
				sAction = "join";

			//Subscribe
			for (auto &iter : m_mapCmdFunc)
			{
				if (iter.Key == "delete")
					Subscribe(iter.Key + "/" + m_sRoomID, 1);
				else
					Subscribe(iter.Key + "/" + m_sRoomID);
			}

			Subscribe("test");
			Subscribe(sAction + "/" + m_sRoomID);

			//Publish - JSON
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
			RootObject->SetStringField("action", sAction);
			RootObject->SetStringField("key", m_sRoomID);

			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
			Publish("room", OutputString);
			m_bCreated = true;
		}


		//Update Hero Position....
		TArray< TSharedPtr<FJsonValue> > ObjArray;
		for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			AHeroCharacter* hero = *ActorItr;
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);

			RootObject->SetNumberField("team", 0);
			RootObject->SetStringField("id", hero->ClientID);
			RootObject->SetNumberField("hp", hero->CurrentHP);

			FVector &&pos = hero->GetActorLocation();
			RootObject->SetNumberField("x", pos.X);
			RootObject->SetNumberField("y", pos.Y);

			ObjArray.Add(MakeShareable(new FJsonValueObject(RootObject)));
		}

		if (ObjArray.Num() > 0)
		{
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
			RootObject->SetArrayField("hero", ObjArray);
			ObjArray.Empty();
			RootObject->SetArrayField("creep", ObjArray);
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);

			std::shared_ptr<char> shared_buf, shared_buf2;
			Packet::CompressPacket CompressPacket;
			std::string UTF8Str = TCHAR_TO_UTF8(*OutputString);
			CompressPacket.u32_DecompressSize = UTF8Str.size() + 1;
			if(Packet::CreateCompressPacket(CompressPacket, UTF8Str.c_str(), shared_buf))
				Publish("gamedata/" + m_sRoomID, &(*shared_buf), CompressPacket.u32_CompressSize + sizeof(Packet::CompressPacket));

			//Packet::DeCompressFromPacket(CompressPacket, &(*shared_buf) + sizeof(Packet::CompressPacket), shared_buf2);
			//FString OutputString2(&(*shared_buf2));
			//Publish("gamedata/" + m_sRoomID, OutputString);
		}
	}
}


void AMqttRoomActor::CreateRoom(FString In_RoomID)
{
	if (Role == ROLE_Authority)
	{
		m_spRoomCmdPair = MakeShareable(new CmdPair(eRoomCMD::Create, In_RoomID));
		m_bCreated = false;
	}
}

void AMqttRoomActor::JoinRoom(FString In_RoomID)
{
	if (Role == ROLE_Authority)
	{
		m_spRoomCmdPair = MakeShareable(new CmdPair(eRoomCMD::Join, In_RoomID));
		m_bCreated = false;
	}
}

void AMqttRoomActor::HandleMQTTMsg(const FString &In_sTopic, const FString &In_sPayload)
{
	if (Role == ROLE_Authority)
	{
		FString cmd, roomid;

		if (In_sTopic == "test")
			Reset(nullptr);
		else if (In_sTopic.Split("/", &cmd, &roomid))
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
	if (Role == ROLE_Authority)
	{
		FVector loc;
		loc.X = In_JsonObj->GetNumberField("x");
		loc.Y = In_JsonObj->GetNumberField("y");
		loc.Z = 0;

		FActorSpawnParameters fsp;
		fsp.Owner = this;//enable rpc

		//AHeroCharacter *pAHeroCharacter = GetWorld()->SpawnActor<AHeroCharacter>(SubHeroActor, loc, FRotator(0.0f, 0.0f, 0.0f), fsp);
		AHeroCharacter *pAHeroCharacter = GetWorld()->SpawnActor<AHeroCharacter>(SubHeroActor, loc, FRotator(0.0f, 0.0f, 0.0f), fsp);
		if (IsValid(pAHeroCharacter))
		{
			pAHeroCharacter->ClientID = In_JsonObj->GetStringField("id");
			pAHeroCharacter->CustomName = In_JsonObj->GetStringField("name");
			pAHeroCharacter->HeroName = In_JsonObj->GetStringField("id");
			pAHeroCharacter->CurrentHP = In_JsonObj->GetNumberField("hp");
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "NewHero:" + In_JsonObj->GetStringField("id"));
			//if (IsValid(m_pAMHUD))
			//	m_pAMHUD->HeroCanSelection.Add(pAHeroCharacter);
			m_mapHeroActor.Emplace(pAHeroCharacter->ClientID, pAHeroCharacter);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
				FString::Printf(TEXT("pAHeroCharacter is null")));
		}
	}
}

void AMqttRoomActor::HeroMove(TSharedPtr<FJsonObject> In_JsonObj)
{
	if (Role == ROLE_Authority)
	{
		auto HeroArray = In_JsonObj->GetArrayField("hero");

		for (auto &iter : HeroArray)
		{
			const TSharedPtr<FJsonObject> *cpJsonObject;
			if (iter->TryGetObject(cpJsonObject))
			{
				auto RealObject = *cpJsonObject;
				auto ppiter = m_mapHeroActor.Find(RealObject->GetStringField("id"));
				if (ppiter && IsValid(m_pAMOBAGameMode) && IsValid(*ppiter))
				{
					AHeroCharacter* pHero = *ppiter;

					FHeroAction act;
					act.ActionStatus = EHeroActionStatus::MoveToPosition;
					act.TargetVec1.X = RealObject->GetNumberField("x");
					act.TargetVec1.Y = RealObject->GetNumberField("y");
					act.TargetVec1.Z = 0;
					act.SequenceNumber = m_SequenceNumber++;

					m_pAMOBAGameMode->ServerSetHeroAction(pHero, act);
				}
			}
		}
	}
}

void AMqttRoomActor::DeleteHero(TSharedPtr<FJsonObject> In_JsonObj)
{
	auto ppiter = m_mapHeroActor.Find(In_JsonObj->GetStringField("id"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "DeleteHero:" + In_JsonObj->GetStringField("id"));
	if (ppiter && IsValid(*ppiter))
	{
		//if (IsValid(m_pAMHUD))
		//	m_pAMHUD->HeroCanSelection.Remove((*ppiter));
		(*ppiter)->Destroy();
		m_mapHeroActor.Remove(In_JsonObj->GetStringField("id"));
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Delete Found");
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Delete Fail");
}

void AMqttRoomActor::Reset(TSharedPtr<FJsonObject> In_JsonObj)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Reset");

	for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		(*ActorItr)->Destroy();
	m_bCreated = false;

	m_mapHeroActor.Empty();

	//if (IsValid(m_pAMHUD))
	//	m_pAMHUD->HeroCanSelection.Empty();
}