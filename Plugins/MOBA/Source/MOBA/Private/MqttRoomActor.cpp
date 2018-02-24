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
	
	if (IsConnected() != err_success)
		return;

	if (!m_listCMD.empty())
	{
		std::stringstream ss;
		std::string sAction;
		
		for (auto &iter : m_listCMD)
		{
			if (iter.first == eRoomCMD::Create)
				sAction = "create";
			else if (iter.first == eRoomCMD::NewPlayer)
				sAction = "newplayer";
			else
				sAction = "join";

			//Subscribe
			ss.clear();
			ss << sAction<< "/" << TCHAR_TO_UTF8(*iter.second);
			Subscribe(ss.str().c_str());

			ss.clear();

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


	//開始判斷 new/delete HeroActor....
	std::list<AHeroCharacter*> list_newHero;
	std::set<FString> set_deleteHero(m_setHeroActor);//先將所有ActorName 覆製一份
	
	for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AHeroCharacter* hero = *ActorItr;
		auto &&HeroActorName = hero->GetName();
		if (m_setHeroActor.find(HeroActorName) == m_setHeroActor.end())//New Hero...
		{
			m_setHeroActor.emplace(HeroActorName);
			list_newHero.push_back(hero);
		}
		else //Exist....
		{
			//原本存在的HeroActor就從刪除名單中移除
			set_deleteHero.erase(HeroActorName);
		}
	}

	//送出新增的HeroList
	if (!list_newHero.empty())
	{
		TArray< TSharedPtr<FJsonValue> > ObjArray;
		
		for (auto &iter : list_newHero)
		{
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
			
			RootObject->SetNumberField("team", 0);

			RootObject->SetStringField("id", iter->GetName());
			RootObject->SetNumberField("hp", iter->CurrentHP);

			FVector &&pos = iter->GetActorLocation();
			RootObject->SetNumberField("x", pos.X);
			RootObject->SetNumberField("y", pos.Y);

			ObjArray.Add(MakeShareable(new FJsonValueObject(RootObject)));
		}

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
	
	//處理已經移除的Hero
	if (!set_deleteHero.empty())
	{
		TArray< TSharedPtr<FJsonValue> > ObjArray;

		//Sync MemberSet and Build JSON...
		for (auto &iter : set_deleteHero)
		{
			//Sync...
			m_setHeroActor.erase(iter);

			//Build...
			TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);

			RootObject->SetStringField("id", iter);
			ObjArray.Add(MakeShareable(new FJsonValueObject(RootObject)));
		}

		TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
		RootObject->SetArrayField("hero", ObjArray);
		ObjArray.Empty();
		RootObject->SetArrayField("creep", ObjArray);
		FString OutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
		FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);

		std::stringstream ss;
		ss << "delete/" << TCHAR_TO_UTF8(*m_sRoomID);;
		Publish(ss.str().c_str(), OutputString);
	}//end if (!set_deleteHero.empty())
}


void AMqttRoomActor::CreateRoom(FString In_RoomID)
{
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Create, In_RoomID));
}

void AMqttRoomActor::JoinRoom(FString In_RoomID)
{
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::NewPlayer, In_RoomID));
	m_listCMD.emplace_back(std::make_pair(eRoomCMD::Join, In_RoomID));
	m_sRoomID = In_RoomID;
}
