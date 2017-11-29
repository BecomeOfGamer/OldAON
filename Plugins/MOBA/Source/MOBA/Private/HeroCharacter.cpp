// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "HeroCharacter.h"
#include "GameFramework/Character.h"
// for GEngine
#include "Engine.h"

#include "MOBAGameState.h"
#include "MHUD.h"
#include "Equipment.h"
#include "UnrealNetwork.h"
#include "BulletActor.h"
#include "cmath"
#include "PaperFlipbook.h"
#include "SceneObject.h"


AHeroCharacter::AHeroCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	//SetRemoteRoleForBackwardsCompat(ROLE_AutonomousProxy);
	HeroBullet = NULL;
	bReplicates = true;
	PrimaryActorTick.bCanEverTick = true;
	SelectionDecal = ObjectInitializer.CreateDefaultSubobject<UDecalComponent>(this, TEXT("SelectionDecal0"));
	PositionOnHead = ObjectInitializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("PositionOnHead0"));
	PositionUnderFoot = ObjectInitializer.CreateDefaultSubobject<UArrowComponent>(this, TEXT("PositionUnderFoot0"));

	PositionOnHead->SetupAttachment(GetCapsuleComponent());
	PositionUnderFoot->SetupAttachment(GetCapsuleComponent());

	SelectionDecal->SetWorldLocation(FVector(0, 0, -90));
	// FRotator = rotation Y Z X
	SelectionDecal->SetWorldRotation(FQuat(FRotator(90, 0, 0)));
	SelectionDecal->SetWorldScale3D(FVector(10, 50, 50));
	SelectionDecal->DecalSize = FVector(2, 1, 1);
	SelectionDecal->SetupAttachment(GetCapsuleComponent());

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	BodyStatus = EHeroBodyStatus::Standing;
	GetMesh()->SetWorldRotation(FQuat(FRotator(0, -90, 0)));

	// 目前攻擊動畫時間長度
	CurrentAttackingAnimationTimeLength = 0.5;
	// 基礎血量
	BaseHP = 450;
	// 基礎魔力
	BaseMP = 100;
	// 基礎撿物品距離
	PickupObjectDistance = 500;
	// 基礎等級
	CurrentLevel = 1;
	// 基礎攻速
	BaseAttackSpeedSecond = 1.8;
	IsAttacked = false;
	IsDead = false;
	LastMoveTarget = FVector::ZeroVector;
	AttackingCounting = 0;
	FollowActorUpdateCounting = 0;
	SpellingCounting = 0;
	DazzingLeftCounting = 0;

	// 基礎攻擊前搖時間長度
	BaseAttackingBeginingTimeLength = 0.5;
	// 基礎攻擊後搖時間長度
	BaseAttackingEndingTimeLength = 0.3;
	// 基礎攻擊動畫時間長度
	BaseAttackingAnimationTimeLength = 0.5;

	// 基礎施法前等待時間長度
	BaseSpellingWatingTimeLength = 0;
	// 基礎施法動畫時間長度
	BaseSpellingAnimationTimeLength = 1;
	// 基礎施法前搖時間長度
	BaseSpellingBeginingTimeLength = 0.5;
	// 基礎施法後搖時間長度
	BaseSpellingEndingTimeLength = 0.5;


	// 每隔一段時間更新移動
	FollowActorUpdateTimeGap = 0.3;

	// set for mouse click
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);

	for (int i = 0; i < (int)EHeroBuffKind::EndBuffKind; ++i)
	{
		BuffKindMap.Add(i, false);
	}
	for (int i = 0; i < (int)EHeroBuffProperty::EndBuffProperty; ++i)
	{
		BuffPropertyMap.Add(i, false);
	}
}

void AHeroCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();	
	GetCapsuleComponent()->OnClicked.AddDynamic(this, &AHeroCharacter::OnMouseClicked);

	SelectionDecal->SetVisibility(false);
	isSelection = false;
	CheckSelf(Skill_MaxCD.Num() == Skill_Amount, TEXT("Skill_MaxCD is invalid"));
	CheckSelf(Skill_Description.Num() == Skill_Amount, TEXT("Skill_Description is invalid"));
	CheckSelf(Skill_Texture.Num() == Skill_Amount, TEXT("Skill_Texture is invalid"));
	CheckSelf(Skill_LevelCDs.Num() == Skill_Amount, TEXT("Skill_LevelCDs is invalid"));
	CheckSelf(Skill_CDing.Num() == Skill_Amount, TEXT("Skill_CDing is invalid"));
	CheckSelf(Skill_CurrentCD.Num() == Skill_Amount, TEXT("Skill_CurrentCD is invalid"));
	CheckSelf(Skill_BaseCD.Num() == Skill_Amount, TEXT("Skill_BaseCD is invalid"));
	CheckSelf(Skill_Level.Num() == Skill_Amount, TEXT("Skill_Level is invalid"));

	for(int32 i = 0; i < Skill_MaxCD.Num(); ++i)
	{
		if(Skill_MaxCD.Num() > 0)
		{
			Skill_MaxCD[i] = Skill_BaseCD[i];
			Skill_CurrentCD[i] = Skill_BaseCD[i];
		}
	}

	Equipments.SetNum(6);
	for(int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		Equipments[idx] = NULL;
	}
	CurrentSkillHint = NULL;
	CurrentSkillIndex = -1;
	

	CurrentAttackingBeginingTimeLength = BaseAttackingBeginingTimeLength;
	CurrentAttackingEndingTimeLength = BaseAttackingEndingTimeLength;
	CurrentAttackingAnimationTimeLength = BaseAttackingAnimationTimeLength;
	CurrentSpellingWatingTimeLength = BaseSpellingWatingTimeLength;
	CurrentSpellingAnimationTimeLength = BaseSpellingAnimationTimeLength;
	CurrentSpellingBeginingTimeLength = BaseSpellingBeginingTimeLength;
	CurrentSpellingEndingTimeLength = BaseSpellingEndingTimeLength;
	// 依等級更新力敏智
	UpdateSAI();
	// 依等級更新血魔攻速
	UpdateHPMPAS();
	CurrentHP = CurrentMaxHP;
	CurrentMP = CurrentMaxMP;
	CurrentAttackRadius = BaseAttackRadius;
	CurrentAttack = BaseAttack;
	CurrentArmor = BaseArmor;
		

	MinimumDontMoveDistance = GetCapsuleComponent()->GetScaledCapsuleHalfHeight() + 30;
}

// Called every frame
void AHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentSkillHint)
	{
		AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		if (hud)
		{
			// 如果有插旗移動，以最後一根移動旗為準來顯示技能提示
			int32 lastMoveIndex = -1;
			for (int32 i = 0; i < ActionQueue.Num(); ++i)
			{
				if (ActionQueue[i].ActionStatus == EHeroActionStatus::MoveToPosition)
				{
					lastMoveIndex = i;
				}
			}
			// 如果有按左shift的話顯示插旗後的技能位置
			if (hud->bLeftShiftDown && lastMoveIndex >= 0)
			{
				FVector pos = ActionQueue[lastMoveIndex].TargetVec1;
				pos.Z += 50;
				CurrentSkillHint->UpdatePos(pos, hud->CurrentMouseHit);
				CurrentSkillDirection = hud->CurrentMouseHit - pos;
				CurrentSkillDirection.Z = 0;
			}
			else
			{
				CurrentSkillDirection = hud->CurrentMouseHit - GetActorLocation();
				CurrentSkillHint->UpdatePos(GetActorLocation(), hud->CurrentMouseHit);
			}
		}
	}
	// 死了
	if(CurrentHP <= 0)
	{
		// 死了還想跑，給我停下
		if (GetVelocity().Size() > 5)
		{
			//AMOBAPlayerController* acontrol =
			//    Cast<AMOBAPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
			//acontrol->CharacterStopMove(this);
		}
		IsDead = true;
		CurrentHP = 0;
	}
	else
	{
		IsDead = false;
	}
	AttackingCounting += DeltaTime;
	FollowActorUpdateCounting += DeltaTime;
	SpellingCounting += DeltaTime;
	// 更新 Buff 持續時間
	bool isLastFrameDazzing = (0 == DazzingLeftCounting);
	DazzingLeftCounting = 0;
	for (int32 i = 0; i < BuffQueue.Num(); ++i)
	{	
		// 移除時間到的Buff
		if (BuffQueue[i]->Duration <= 0)
		{
			// 釋放記憶體
			if (!BuffQueue[i]->IsPendingKillPending())
			{
				BuffQueue[i]->Destroy();
			}
			BuffQueue.RemoveAt(i);
			i--;
		}
	}
	if (EHeroBodyStatus::Dazzing == BodyStatus)
	{
	}
	// 如果醒了
	if (!isLastFrameDazzing && DazzingLeftCounting == 0)
	{
	
		LastMoveTarget = FVector::ZeroVector;
		BodyStatus = EHeroBodyStatus::Standing;
	}
	// 算CD
	for(int32 i = 0; i < Skill_CDing.Num(); ++i)
	{
		if(Skill_CDing[i])
		{
			Skill_CurrentCD[i] += DeltaTime;
			if(Skill_CurrentCD[i] > Skill_MaxCD[i])
			{
				Skill_CurrentCD[i] = Skill_MaxCD[i];
				Skill_CDing[i] = false;
			}
		}
	}
	// 是否有動作？
	if (ActionQueue.Num() > 0 && !IsDead)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Magenta, 
			FString::Printf(L"ActionQueue %d", ActionQueue.Num()));
		// 動作駐列最上層動作是否為當前動作
		if (ActionQueue[0] != CurrentAction)
		{
			// 拿出動作
			CurrentAction = ActionQueue[0];
			// 進入此狀態的有限狀態機來做事
			DoAction(CurrentAction);
		}
		// 查看當前動作是否做完？
		else if (!CheckCurrentActionFinish())
		{
			// 進入此狀態的有限狀態機來做事
			DoAction(CurrentAction);
		}
		else
		{
			// 推出事件
			PopAction();
			// 檢查動作駐列是否為空？
			if (ActionQueue.Num() == 0)
			{
				// 站立不動
				DoNothing();
			}
			else
			{
				// 進入此狀態的有限狀態機來做事
				DoAction(CurrentAction);
			}
		}
	}
	else
	{
		// 站立不動
		DoNothing();
	}
}

// Called to bind functionality to input
void AHeroCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
#if WITH_EDITOR

void AHeroCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	//Get the name of the property that was changed
	FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if((PropertyName == GET_MEMBER_NAME_CHECKED(AHeroCharacter, Skill_LevelCDs)))
	{
		Skill_BaseCD.SetNum(Skill_LevelCDs.Num());
		Skill_MaxCD.SetNum(Skill_LevelCDs.Num());
		Skill_CDing.SetNum(Skill_LevelCDs.Num());
		Skill_CurrentCD.SetNum(Skill_LevelCDs.Num());
		Skill_Level.SetNum(Skill_LevelCDs.Num());
		Skill_FaceSkill.SetNum(Skill_LevelCDs.Num());
		for(int32 i = 0; i < Skill_LevelCDs.Num(); ++i)
		{
			if(Skill_LevelCDs[i].CDs.Num() > 0)
			{
				Skill_BaseCD[i] = Skill_LevelCDs[i][0];
				Skill_MaxCD[i] = Skill_BaseCD[i];
			}
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AHeroCharacter::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
	const FName TailPropName = PropertyChangedEvent.PropertyChain.GetTail()->GetValue()->GetFName();
	static FName Mobility_NAME(TEXT("CDs"));
	if(TailPropName == Mobility_NAME)
	{
		for(int32 i = 0; i < Skill_LevelCDs.Num(); ++i)
		{
			if(Skill_LevelCDs[i].CDs.Num() > 0)
			{
				Skill_BaseCD[i] = Skill_LevelCDs[i][0];
				Skill_MaxCD[i] = Skill_BaseCD[i];
			}
		}
	}
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif // WITH_EDITOR

bool AHeroCharacter::Pickup(AEquipment* equ)
{
	if (HasEquipment(equ))
	{
		return false;
	}

	for(int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if(Equipments[idx] == NULL)
		{
			Equipments[idx] = equ;
			if(idx == 0)
			{
				Equipments[0]->AttachRootComponentTo(GetMesh(), TEXT("hand_rSocket"), EAttachLocation::SnapToTarget);
				return true;
			}
			equ->ServerSetLocation(FVector(FMath::Rand(), 99999, 99999));
			return true;
		}
	}
	return false;
}

bool AHeroCharacter::ThrowEquipment(AEquipment* equ, FVector pos)
{
	FVector origin, extent;
	equ->GetActorBounds(true, origin, extent);
	pos.Z += extent.Z;
	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if (Equipments[idx] == equ)
		{
			if (idx == 0)
			{
				Equipments[0]->DetachRootComponentFromParent();
			}
			Equipments[idx] = NULL;
		}
	}
	equ->ServerSetLocation(pos);
	equ = NULL;
	return true;
}

bool AHeroCharacter::HasEquipment(AEquipment* equ)
{
	for (int32 idx = 0; idx < Equipments.Num(); ++idx)
	{
		if (Equipments[idx] == equ)
		{
			return true;
		}
	}
	return false;
}

bool AHeroCharacter::AttackCompute_Validate(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage)
{
	return true;
}

void AHeroCharacter::AttackCompute_Implementation(AHeroCharacter* attacker, AHeroCharacter* victim, EDamageType dtype, float damage)
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	float Injury = ags->ArmorConvertToInjuryPersent(victim->CurrentArmor);
	float RDamage = damage * Injury;
	// 顯示傷害文字
	ServerShowDamageEffect(victim->GetActorLocation(),
		victim->GetActorLocation() - attacker->GetActorLocation(), RDamage);
	victim->CurrentHP -= RDamage;
	for (int32 i = 0; i < attacker->BuffQueue.Num(); ++i)
	{
		attacker->BuffQueue[i]->CreateDamage(attacker, victim, dtype, damage, RDamage);
		attacker->BuffQueue[i]->OnAttackLanded(attacker, victim, dtype, damage, RDamage);
	}
	for (int32 i = 0; i < victim->BuffQueue.Num(); ++i)
	{
		victim->BuffQueue[i]->BeDamage(attacker, victim, dtype, damage, RDamage);
	}
}

bool AHeroCharacter::HealCompute_Validate(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
{
	return true;
}

void AHeroCharacter::HealCompute_Implementation(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
{
	target->CurrentHP += heal_mount;
	for (int32 i = 0; i < caster->BuffQueue.Num(); ++i)
	{
		caster->BuffQueue[i]->OnHealLanded(caster, target, heal_mount);
	}
	for (int32 i = 0; i < target->BuffQueue.Num(); ++i)
	{
		target->BuffQueue[i]->BeHeal(caster, target, heal_mount);
	}
}

void AHeroCharacter::OnMouseClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (hud)
	{
		// 按下左鍵
		if (hud->bMouseLButton)
		{
			if (hud->CurrentSelection.Num() == 1)
			{
				if (hud->CurrentSelection[0] == this)
				{
					return;
				}
				if (hud->CurrentSelection[0]->CurrentSkillHint)
				{
					return;
				}
			}
			hud->ClickedSelected = true;
			hud->ClearAllSelection();
			SelectionOn();
		}
		// 按下右鍵
		else if (hud->bMouseRButton)
		{
			if (hud->CurrentSelection.Num() > 0)
			{
				hud->HeroAttackHero(this);
			}
		}
	}
}

void AHeroCharacter::SelectionOn()
{
	isSelection = true;
	SelectionDecal->SetVisibility(true);
	
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if(hud)
	{
		hud->CurrentSelection.Add(this);
	}
	
}

void AHeroCharacter::SelectionOff()
{
	isSelection = false;
	SelectionDecal->SetVisibility(false);
	
	AMHUD* hud = Cast<AMHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if(hud)
	{
		hud->RemoveSelection.Add(this);
	}
	
	HideSkillHint();
}

void AHeroCharacter::CheckSelf(bool res, FString msg)
{
	if(!res)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, HeroName + TEXT(" ") + msg);
	}
}

float AHeroCharacter::GetSkillCDPercent(int32 n)
{
	if(n > 0 && n < Skill_Amount)
	{
		if(Skill_CDing[n])
		{
			return Skill_CurrentCD[n] / Skill_MaxCD[n];
		}
	}
	return 1.f;
}

float AHeroCharacter::GetHPPercent()
{
	return CurrentHP / CurrentMaxHP;
}

float AHeroCharacter::GetMPPercent()
{
	return CurrentMP / CurrentMaxMP;
}

void AHeroCharacter::UpdateHPMPAS()
{
	AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
	if (ags) 
	{
		CurrentMaxHP = BaseHP + BaseStrength * ags->StrengthToHP;
		CurrentHealingHP = BaseHealingHP + BaseStrength * ags->StrengthToHealingHP;
		CurrentMaxMP = BaseMP + BaseIntelligence * ags->IntelligenceToMP;
		CurrentHealingMP = BaseHealingMP + BaseIntelligence * ags->IntelligenceToHealingMP;

		CurrentAttackSpeed = BaseMP + BaseAgility * ags->AgilityToAttackSpeed;
		CurrentAttackSpeedSecond = BaseAttackSpeedSecond / (1 + CurrentAttackSpeed * 0.01);
		CurrentArmor = BaseArmor + BaseAgility * ags->AgilityToDefense;
		CurrentAttackingAnimationTimeLength = BaseAttackingAnimationTimeLength / CurrentAttackSpeedSecond;
		CurrentAttackingAnimationRate = BaseAttackingAnimationTimeLength / CurrentAttackSpeedSecond;
	}
}

void AHeroCharacter::UpdateSAI()
{
	if(CurrentLevel <= LevelProperty_Strength.Num())
	{
		Strength = BaseStrength + LevelProperty_Strength[CurrentLevel - 1];
	}
	else if(LevelProperty_Strength.Num() > 0)
	{
		Strength = BaseStrength + LevelProperty_Strength.Last();
	}
	if(CurrentLevel <= LevelProperty_Agility.Num())
	{
		Agility = BaseAgility + LevelProperty_Agility[CurrentLevel - 1];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Agility = BaseAgility + LevelProperty_Agility.Last();
	}
	if(CurrentLevel <= LevelProperty_Intelligence.Num())
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence[CurrentLevel - 1];
	}
	else if(LevelProperty_Intelligence.Num() > 0)
	{
		Intelligence = BaseIntelligence + LevelProperty_Intelligence.Last();
	}
}

bool AHeroCharacter::ShowSkillHint(int32 index)
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	if(index < Skill_HintActor.Num())
	{
		CurrentSkillHint = GetWorld()->SpawnActor<ASkillHintActor>(Skill_HintActor[index]);
		CurrentSkillIndex = index;
		return true;
	}
	return false;
}

void AHeroCharacter::HideSkillHint()
{
	if (CurrentSkillHint)
	{
		CurrentSkillHint->Destroy();
	}
	CurrentSkillHint = NULL;
}


bool AHeroCharacter::ServerPlayAttack_Validate(float duraction, float rate)
{
	return true;
}

void AHeroCharacter::ServerPlayAttack_Implementation(float duraction, float rate)
{
	BP_PlayAttack(duraction, rate);
}

bool AHeroCharacter::UseSkill(int32 index, FVector VFaceTo, FVector Pos)
{
	if (index < 0)
	{
		index = CurrentSkillIndex;
	}
	// 設定面對施法的位置
	if (Skill_FaceSkill.Num() > index)
	{
		if (Skill_FaceSkill[index])
		{
			FVector dir = Pos - GetActorLocation();
			dir.Z = 0;
			dir.Normalize();
			SetActorRotation(dir.Rotation());
		}
	}
	VFaceTo.Z = 0;
	VFaceTo.Normalize();
	BP_ImplementSkill(index, VFaceTo, Pos);
	return true;
}

int32 AHeroCharacter::GetCurrentSkillIndex()
{
	return CurrentSkillIndex;
}


bool AHeroCharacter::CheckCurrentActionFinish()
{
	AEquipment* TargetEquipment = Cast<AEquipment>(CurrentAction.TargetEquipment);
	AHeroCharacter* TargetActor = Cast<AHeroCharacter>(CurrentAction.TargetActor);
	ASceneObject* TargetSceneActor = Cast<ASceneObject>(CurrentAction.TargetActor);
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		switch (CurrentAction.ActionStatus)
		{
		case EHeroActionStatus::Default:
			break;
		case EHeroActionStatus::MoveToPosition:
			break;
		case EHeroActionStatus::MoveToActor:
			break;
		case EHeroActionStatus::FollowActor:
			break;
		case EHeroActionStatus::AttackActor:
			break;
		case EHeroActionStatus::MovingAttackActor:
			break;
		case EHeroActionStatus::MoveAndAttack:
			break;
		case EHeroActionStatus::SpellToPosition:
			break;
		case EHeroActionStatus::SpellToActor:
			break;
		case EHeroActionStatus::SpellToDirection:
			return true;
			break;
		case EHeroActionStatus::SpellToSelf:
			break;
		case EHeroActionStatus::MoveToPickup:
		{
			if (HasEquipment(TargetEquipment))
			{
				return true;
			}
		}
		break;
		case EHeroActionStatus::MoveToThrowEqu:
		{
			if (Equipments[CurrentAction.TargetIndex1] == NULL)
			{
				return true;
			}
		}
		break;
		case EHeroActionStatus::ThrowEquToActor:
			break;
		default:
			break;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		// 移動到夠接近就 Pop 掉
		float Distance = FVector::Dist(CurrentAction.TargetVec1, this->GetActorLocation());
		if (Distance < MinimumDontMoveDistance/* && this->GetVelocity().Size() < 5*/)
		{
			return true;
		}
		else
		{
			FVector dir = CurrentAction.TargetVec1 - this->GetActorLocation();
			dir.Z = 0;
			dir.Normalize();
			// AddMovementInput will move actor with no rotation, no nav
			//this->AddMovementInput(dir);
			GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Magenta, GetFullName() +
				FString::Printf(TEXT("%s Dis %f"), *dir.ToString(), Distance));
		}
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
	case EHeroBodyStatus::AttackBegining:
	case EHeroBodyStatus::AttackEnding:
	{
		if (TargetActor && TargetActor->CurrentHP <= 0)
		{
			return true;
		}
		if (TargetSceneActor && TargetSceneActor->CurrentHP <= 0)
		{
			return true;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
	return false;
}

bool AHeroCharacter::DoAction_Validate(const FHeroAction& CurrentAction)
{
	return true;
}

void AHeroCharacter::DoAction_Implementation(const FHeroAction& CurrentAction)
{
	switch (CurrentAction.ActionStatus)
	{
	case EHeroActionStatus::Default:
		PopAction();
		break;
	case EHeroActionStatus::MoveToPosition:
		DoAction_MoveToPosition(CurrentAction);
		break;
	case EHeroActionStatus::MoveToActor:
		break;
	case EHeroActionStatus::FollowActor:
		break;
	case EHeroActionStatus::AttackActor:
		DoAction_AttackActor(CurrentAction);
		break;
	case EHeroActionStatus::MovingAttackActor:
		break;
	case EHeroActionStatus::MoveAndAttack:
		break;
	case EHeroActionStatus::SpellToPosition:
		break;
	case EHeroActionStatus::SpellToActor:
		break;
	case EHeroActionStatus::SpellToDirection:
		DoAction_SpellToDirection(CurrentAction);
		break;
	case EHeroActionStatus::SpellToSelf:
		break;
	case EHeroActionStatus::MoveToPickup:
		DoAction_MoveToPickup(CurrentAction);
		break;
	case EHeroActionStatus::MoveToThrowEqu:
		DoAction_MoveToThrowEqu(CurrentAction);
		break;
	case EHeroActionStatus::ThrowEquToActor:
		break;
	case EHeroActionStatus::AttackSceneObject:
		DoAction_AttackSceneObject(CurrentAction);
		break;
	default:
		break;
	}
}

void AHeroCharacter::DoNothing()
{
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
		break;
	case EHeroBodyStatus::Moving:
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->CharacterStopMove(this);
		}
		
		BodyStatus = EHeroBodyStatus::Standing;
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
}

void AHeroCharacter::DoAction_MoveToPosition(const FHeroAction& CurrentAction)
{
	if (BodyStatus == EHeroBodyStatus::Dazzing && GetVelocity().Size() > 5)
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->CharacterStopMove(this);
		}
	}
	else if (LastMoveTarget != CurrentAction.TargetVec1)
	{
		DoAction_MoveToPositionImpl(CurrentAction);
	}
}

void AHeroCharacter::DoAction_MoveToPositionImpl(const FHeroAction& CurrentAction)
{

	switch (BodyStatus)
	{
	case EHeroBodyStatus::AttackWating:
	case EHeroBodyStatus::AttackBegining:
	case EHeroBodyStatus::AttackEnding:
	case EHeroBodyStatus::Standing:
	{
		BodyStatus = EHeroBodyStatus::Moving;
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && this->GetController())
		{
			NavSys->SimpleMoveToLocation(this->GetController(), CurrentAction.TargetVec1);
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		if (NavSys && this->GetController())
		{
			NavSys->SimpleMoveToLocation(this->GetController(), CurrentAction.TargetVec1);
		}
	}
		break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::SpellBegining:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	case EHeroBodyStatus::SpellEnding:
		BodyStatus = EHeroBodyStatus::Standing;
		break;
	default:
		break;
	}
}

void AHeroCharacter::PopAction()
{
	if (ActionQueue.Num() > 0)
	{
		ActionQueue.RemoveAt(0);
		if (ActionQueue.Num() > 0)
		{
			CurrentAction = ActionQueue[0];
		}
		else
		{
			CurrentAction.ActionStatus = EHeroActionStatus::Default;
		}
	}
}

void AHeroCharacter::DoAction_AttackActor(const FHeroAction& CurrentAction)
{
	AHeroCharacter* TargetActor = Cast<AHeroCharacter>(CurrentAction.TargetActor);
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRadius > DistanceToTargetActor)
		{
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterMove(this, TargetActor->GetActorLocation());
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRadius > DistanceToTargetActor)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterStopMove(this);
			}
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else if (FollowActorUpdateCounting > FollowActorUpdateTimeGap)
		{
			FollowActorUpdateCounting = 0;
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterMove(this, TargetActor->GetActorLocation());
			}
		}
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
	{
		if (AttackingCounting > CurrentAttackSpeedSecond)
		{
			AttackingCounting = 0;
			BodyStatus = EHeroBodyStatus::AttackBegining;
			ServerPlayAttack(CurrentSpellingAnimationTimeLength, CurrentAttackingAnimationRate);
			PlayAttack = true;
		}
		// 播放攻擊動畫
		// ...
	}
	break;
	case EHeroBodyStatus::AttackBegining:
	{
		if (!IsAttacked && AttackingCounting > CurrentAttackingBeginingTimeLength)
		{
			IsAttacked = true;

			// 遠攻
			if (HeroBullet)
			{
				FVector pos = GetActorLocation();
				ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(HeroBullet);
				if (bullet)
				{
					bullet->SetActorLocation(pos);
					bullet->SetTartgetActor(TargetActor);
					bullet->Damage = this->CurrentAttack;
				}
			}
			else
			{
				// 近戰
				
				AttackCompute(this, TargetActor, EDamageType::DAMAGE_PHYSICAL, this->CurrentAttack);
			}
			BodyStatus = EHeroBodyStatus::AttackEnding;
		}
	}
	break;
	case EHeroBodyStatus::AttackEnding:
	{
		if (AttackingCounting > CurrentAttackingBeginingTimeLength + CurrentAttackingEndingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
}

void AHeroCharacter::AddBuff(AHeroBuff* buff)
{
	BuffQueue.Add(buff);
	buff->BuffTarget.Add(this);
}

void AHeroCharacter::ServerShowDamageEffect(FVector pos, FVector dir, float Damage)
{
	ADamageEffect* TempDamageText = GetWorld()->SpawnActor<ADamageEffect>(ShowDamageEffect);
	if (TempDamageText)
	{
		TempDamageText->OriginPosition = pos;
		TempDamageText->SetString(FString::FromInt((int32)Damage));
		FVector scaleSize(TempDamageText->ScaleSize, TempDamageText->ScaleSize, TempDamageText->ScaleSize);
		TempDamageText->SetActorScale3D(scaleSize);
		dir.Normalize();
		TempDamageText->FlyDirection = dir;
	}
}

void AHeroCharacter::DoAction_SpellToDirection(const FHeroAction& CurrentAction)
{
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Moving:
	{
		AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
		if (ags)
		{
			ags->CharacterStopMove(this);
		}
	}
	// no break;
	case EHeroBodyStatus::Standing:
	{
		BodyStatus = EHeroBodyStatus::SpellWating;
		SpellingCounting = 0;
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellWating:
	{
		if (SpellingCounting > CurrentSpellingWatingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::SpellBegining;
			SpellingCounting = 0;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
	{
		if (Role == ROLE_Authority)
		{
			if (SpellingCounting > CurrentSpellingBeginingTimeLength)
			{
				if (LastUseSkill != CurrentAction)
				{
					BodyStatus = EHeroBodyStatus::SpellEnding;
					SpellingCounting = 0;
					AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
					if (ags)
					{
						ags->HeroUseSkill(this, CurrentAction.TargetIndex1, CurrentAction.TargetVec1, CurrentAction.TargetVec2);
					}
				}
				LastUseSkill = CurrentAction;
			}
		}
	}
	break;
	case EHeroBodyStatus::SpellEnding:
	{
		if (SpellingCounting > CurrentSpellingBeginingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	default:
		break;
	}
}

void AHeroCharacter::DoAction_AttackSceneObject(const FHeroAction& CurrentAction)
{
	ASceneObject* TargetActor = Cast<ASceneObject>(CurrentAction.TargetActor);
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRadius > DistanceToTargetActor)
		{
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterMove(this, TargetActor->GetActorLocation());
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
		if (CurrentAttackRadius > DistanceToTargetActor)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterStopMove(this);
			}
			BodyStatus = EHeroBodyStatus::AttackWating;
			IsAttacked = false;
		}
		else if (FollowActorUpdateCounting > FollowActorUpdateTimeGap)
		{
			FollowActorUpdateCounting = 0;
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterMove(this, TargetActor->GetActorLocation());
			}
		}
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
	{
		if (AttackingCounting > CurrentAttackSpeedSecond)
		{
			AttackingCounting = 0;
			BodyStatus = EHeroBodyStatus::AttackBegining;
			PlayAttack = true;
		}
		// 播放攻擊動畫
		// ...
	}
	break;
	case EHeroBodyStatus::AttackBegining:
	{
		if (!IsAttacked && AttackingCounting > CurrentAttackingBeginingTimeLength)
		{
			IsAttacked = true;
			float Damage = this->CurrentAttack;

			if (HeroBullet)
			{
				FVector pos = GetActorLocation();
				ABulletActor* bullet = GetWorld()->SpawnActor<ABulletActor>(HeroBullet);
				if (bullet)
				{
					bullet->SetActorLocation(pos);
					bullet->SetTartgetActor(TargetActor);
					bullet->Damage = Damage;
				}
			}
			else
			{
				TargetActor->CurrentHP -= Damage;
			}
			BodyStatus = EHeroBodyStatus::AttackEnding;
		}
	}
	break;
	case EHeroBodyStatus::AttackEnding:
	{
		if (AttackingCounting > CurrentAttackingBeginingTimeLength + CurrentAttackingEndingTimeLength)
		{
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
}

void AHeroCharacter::DoAction_MoveToPickup(const FHeroAction& CurrentAction)
{
	AEquipment* TargetActor = CurrentAction.TargetEquipment;
	FVector dir = TargetActor->GetActorLocation() - GetActorLocation();
	dir.Z = 0;
	dir.Normalize();
	SetActorRotation(dir.Rotation());
	float DistanceToTargetActor = FVector::Dist(TargetActor->GetActorLocation(), this->GetActorLocation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			if (Pickup(TargetActor))
			{
			}
		}
		else
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterMove(this, TargetActor->GetActorLocation());
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			if (Pickup(TargetActor))
			{
				AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
				if (ags)
				{
					ags->CharacterStopMove(this);
				}
				BodyStatus = EHeroBodyStatus::Standing;
			}
		}
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
}

void AHeroCharacter::DoAction_MoveToThrowEqu(const FHeroAction& CurrentAction)
{
	AEquipment* TargetActor = Equipments[CurrentAction.TargetIndex1];
	float DistanceToTargetActor = FVector::Dist(CurrentAction.TargetVec1,  GetActorLocation());
	switch (BodyStatus)
	{
	case EHeroBodyStatus::Standing:
	{
		if (PickupObjectDistance > DistanceToTargetActor)
		{
			ThrowEquipment(TargetActor, CurrentAction.TargetVec1);
		}
		else
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				LastMoveTarget = CurrentAction.TargetVec1;
				ags->CharacterMove(this, CurrentAction.TargetVec1);
			}
			BodyStatus = EHeroBodyStatus::Moving;
		}
	}
	break;
	case EHeroBodyStatus::Moving:
	{
		if (LastMoveTarget != CurrentAction.TargetVec1)
		{
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				LastMoveTarget = CurrentAction.TargetVec1;
				ags->CharacterMove(this, CurrentAction.TargetVec1);
			}
		}
		if (PickupObjectDistance > DistanceToTargetActor && LastMoveTarget == CurrentAction.TargetVec1)
		{
			ThrowEquipment(TargetActor, CurrentAction.TargetVec1);
			AMOBAGameState* ags = Cast<AMOBAGameState>(UGameplayStatics::GetGameState(GetWorld()));
			if (ags)
			{
				ags->CharacterStopMove(this);
			}
			BodyStatus = EHeroBodyStatus::Standing;
		}
	}
	break;
	case EHeroBodyStatus::Dazzing:
		break;
	case EHeroBodyStatus::AttackWating:
		break;
	case EHeroBodyStatus::AttackBegining:
		break;
	case EHeroBodyStatus::AttackEnding:
		break;
	case EHeroBodyStatus::SpellBegining:
		break;
	case EHeroBodyStatus::SpellEnding:
		break;
	default:
		break;
	}
}

void AHeroCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AHeroCharacter, Equipments);
	DOREPLIFETIME(AHeroCharacter, CurrentHP);
	DOREPLIFETIME(AHeroCharacter, BodyStatus);
	DOREPLIFETIME(AHeroCharacter, ActionQueue);
	DOREPLIFETIME(AHeroCharacter, CurrentAction);
	DOREPLIFETIME(AHeroCharacter, AttackingCounting);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackSpeedSecond);
	DOREPLIFETIME(AHeroCharacter, CurrentAttackingAnimationRate);
}
