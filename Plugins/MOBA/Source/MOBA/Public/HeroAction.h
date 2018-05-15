// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "MobaEnum.h"
#include "HeroAction.generated.h"


class AHeroCharacter;
class AEquipment;

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

	// for MoveToPosition, MovingAttackToPosition, SpellToPosition, SpellToDirection, MoveToThrowEqu
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
