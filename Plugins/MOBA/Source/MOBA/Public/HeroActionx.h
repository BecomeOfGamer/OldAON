// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "HeroActionx.generated.h"


class AHeroCharacter;
class AEquipment;

UENUM(BlueprintType)
enum class EHeroActionStatus : uint8
{
	//站著休息
	Default,
	//移動攻擊到指定位置
	MovingAttackToPosition,
	//移動到指定位置
	MoveToPosition,
	//移動到指定的人身邊
	MoveToActor,
	//跟著人走
	FollowActor,
	//打指定的人
	AttackActor,
	//邊移動邊攻擊指定敵人
	MovingAttackActor,
	//A點地板 移動中遇到敵人停下來攻擊
	MoveAndAttack,
	//直接施放技能
	SpellNow,
	//指定地點的技能
	SpellToPosition,
	//指向技
	SpellToDirection,
	//指定技
	SpellToActor,
	//撿裝
	MoveToPickup,
	//丟裝
	MoveToThrowEqu,
	//丟裝給人
	ThrowEquToActor,
	// 破壞場景物件
	AttackSceneObject
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FHeroAction
{
	GENERATED_USTRUCT_BODY()

	FHeroAction() :ActionStatus(EHeroActionStatus::Default), TargetActor(NULL), TargetEquipment(NULL),
		TargetVec1(FVector::ZeroVector), TargetVec2(FVector::ZeroVector), TargetIndex1(0), 
		SequenceNumber(0){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHeroActionStatus ActionStatus;

	// for MoveToActor, FollowActor, AttackActor, MovingAttackActor, SpellToActor, ThrowEquToActor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AHeroCharacter* TargetActor;

	// for MoveToPickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEquipment* TargetEquipment;

	// for MoveToPosition, MoveAndAttack, SpellToPosition, SpellToDirection, MoveToThrowEqu
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector		TargetVec1;

	// for SpellToPosition, SpellToDirection
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector		TargetVec2;

	// for SpellToPosition, SpellToDirection, MoveToThrowEqu
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32		TargetIndex1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32	SequenceNumber;

	// for time start point
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float	TimePoint;
	
	bool operator==(const FHeroAction& rhs)
	{
		return rhs.ActionStatus == ActionStatus &&
			rhs.SequenceNumber == SequenceNumber;
	}
	bool operator!=(const FHeroAction& rhs)
	{
		return !(*this == rhs);
	}
};

UCLASS()
class MOBA_API UHeroActionx : public UObject
{
	GENERATED_BODY()

};
