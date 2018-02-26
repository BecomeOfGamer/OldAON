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
}

// Called every frame
void AMqttRoomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (IsConnected() != err_success)
		return;

	if (!m_listCMD.empty())
	{
		std::string sAction;
		for (auto &iter : m_listCMD)
		{
			if (iter.first == eRoomCMD::Create)
				sAction = "create";
			else if (iter.first == eRoomCMD::NewPlayer)
				sAction = "newplayer";
			else if (iter.first == eRoomCMD::Game)
				sAction = "movecmd";
			else if (iter.first == eRoomCMD::Delete)
				sAction = "delete";
			else
				sAction = "join";

			//Subscribe
			std::stringstream ss;
			ss << sAction<< "/" << TCHAR_TO_UTF8(*iter.second);
			Subscribe(ss.str().c_str());

			if (iter.first == eRoomCMD::Create || iter.first == eRoomCMD::Join)
			{
				//Publish - JSON
				TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
				RootObject->SetStringField("action", sAction.c_str());
				RootObject->SetStringField("key", iter.second);

				FString OutputString;
				TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
				FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);
				Publish("room", OutputString);
			}
		}
		m_listCMD.clear();
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

		std::stringstream ss;
		ss << "gamedata/" << TCHAR_TO_UTF8(*m_sRoomID);;

		Publish(ss.str().c_str(), OutputString);
	}//end if (!list_newHero.empty())
	
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
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::NewPlayer, In_RoomID));
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Game, In_RoomID));
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Create, In_RoomID));
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Delete, In_RoomID));
	m_sRoomID = In_RoomID;
}

void AMqttRoomActor::JoinRoom(FString In_RoomID)
{
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::NewPlayer, In_RoomID));
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Join, In_RoomID));
	m_sRoomID = In_RoomID;
}

void AMqttRoomActor::HandleMQTTMsg(const FString &In_sTopic, const FString &In_sPayload)
{
	if (In_sTopic.Find(m_sRoomID) < 0)
		return;

	if (In_sTopic.Find("newplayer") >= 0)
		NewHero(In_sPayload);
	else if (In_sTopic.Find("movecmd") >= 0)
		HeroMove(In_sPayload);
	else if (In_sTopic.Find("delete") >= 0)
		DeleteHero(In_sPayload);

}

TSharedPtr<FJsonObject> AMqttRoomActor::ParseJSON(const FString &In_sPayload)
{
	TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
	TSharedRef< TJsonReader<TCHAR> > JsonReader = TJsonReaderFactory<TCHAR>::Create(In_sPayload);
	FJsonSerializer::Deserialize(JsonReader, RootObject);
	return RootObject;
}

void AMqttRoomActor::NewHero(const FString &In_sPayload)
{
	auto RootObject = ParseJSON(In_sPayload);

	FVector loc;
	loc.X = RootObject->GetNumberField("x");
	loc.Y = RootObject->GetNumberField("y");
	loc.Z = 0;

	AHeroCharacter *pAHeroCharacter = GetWorld()->SpawnActor<AHeroCharacter>(SubHeroActor);
	if (IsValid(pAHeroCharacter))
	{
		pAHeroCharacter->SetActorLocation(loc);
		pAHeroCharacter->ClientID = RootObject->GetStringField("id");
		pAHeroCharacter->CustomName = RootObject->GetStringField("name");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("pAHeroCharacter is null")));
	}
}

void AMqttRoomActor::HeroMove(const FString &In_sPayload)
{
	auto RootObject = ParseJSON(In_sPayload);
	auto HeroArray = RootObject->GetArrayField("hero");
	
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

void AMqttRoomActor::DeleteHero(const FString &In_sPayload)
{
	auto RootObject = ParseJSON(In_sPayload);
	auto ppiter = m_mapHeroActor.Find(RootObject->GetStringField("id"));
	if (ppiter && IsValid(*ppiter))
	{
		(*ppiter)->Destroy();
		m_mapHeroActor.Remove(RootObject->GetStringField("id"));
	}
}