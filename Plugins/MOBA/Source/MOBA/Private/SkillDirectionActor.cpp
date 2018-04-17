// Fill out your copyright notice in the Description page of Project Settings.
#include "MOBAPrivatePCH.h"
#include "SkillDirectionActor.h"
#include "HeroCharacter.h"
#include "MOBAPlayerController.h"
#include "UnrealNetwork.h"


// Sets default values
ASkillDirectionActor::ASkillDirectionActor(const FObjectInitializer& ObjectInitializer)
	: Super(FObjectInitializer::Get())
{
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	CapsuleComponent->InitCapsuleSize(100.0f, 500.0f);
	CapsuleComponent->SetCollisionProfileName(TEXT("CollisionCylinder"));

	CapsuleComponent->CanCharacterStepUpOn = ECB_No;
	CapsuleComponent->bShouldUpdatePhysicsVolume = true;
	CapsuleComponent->bCheckAsyncSceneOnMove = false;
	CapsuleComponent->SetCanEverAffectNavigation(false);
	CapsuleComponent->bDynamicObstacle = true;
	

	CapsuleComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);
	CapsuleComponent->SetIsReplicated(true);

	RootComponent = CapsuleComponent;

	BulletParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BulletParticle0"));
	BulletParticle->SetupAttachment(CapsuleComponent);
	FlyParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FlyParticle0"));
	FlyParticle->SetupAttachment(CapsuleComponent);
	BulletParticle->SetIsReplicated(true);
	FlyParticle->SetIsReplicated(true);
	
	FlyDistance = 1000;
	MoveSpeed = 500;
	DestroyDelay = 2;
	PrepareDestory = false;
	ActiveFlyParticleDied = false;
	ActiveBulletParticleDied = true;
	DestoryCount = 0;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ASkillDirectionActor::BeginPlay()
{
	Super::BeginPlay();
	Direction.Normalize();
	Direction.Z = 0;
	SetActorRelativeRotation(Attacker->GetActorRotation());
	if (CollisionByCapsule)
	{
		CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASkillDirectionActor::OnBeginOverlap);
	}
	else
	{
		CapsuleComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	}
	StartPos = GetActorLocation();
}

// Called every frame
void ASkillDirectionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsValid(Attacker))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
			FString::Printf(TEXT("ASkillDirectionActor attacker Error")));
		Destroy();
		return;
	}
	float move = DeltaTime * MoveSpeed;
	ElapsedFlyDistance += move;
	ElapsedTime += DeltaTime;
	FVector fpos = StartPos + Direction * ElapsedFlyDistance;
	if (IsValid(MoveCurve))
	{
		fpos += GetActorRotation().RotateVector(MoveCurve->GetVectorValue(ElapsedFlyDistance));
	}
	SetActorLocation(fpos);
	float scale = 1;
	if (IsValid(ScaleSize))
	{
		scale = ScaleSize->GetFloatValue(ElapsedTime);
		SetActorScale3D(FVector(1,1,1) * scale);
	}
	if (debugflag)
	{
		DrawDebugSphere(GetWorld(), this->GetActorLocation(), Radius*scale, 8, FColor::Cyan);
	}

	if (ElapsedFlyDistance < FlyDistance && !PrepareDestory)
	{
		// TODO: 使用內建碰撞優化
		if (!CollisionByCapsule)
		{
			float dis2 = Radius*Radius;
			for (TActorIterator<AHeroCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
				AHeroCharacter* hero = *ActorItr;
				if (hero->TeamId != Attacker->TeamId && !TargetActors.Contains(hero))
				{
					if (FVector::DistSquaredXY(this->GetActorLocation(), hero->GetActorLocation()) < dis2)
					{
						AHeroCharacter::localPC->ServerAttackCompute(
							Attacker, hero, DamageType, Damage, false);
						TargetActors.Add(hero);
					}
				}
			}
		}
	}
	else
	{
		PrepareDestory = true;
		if (!ActiveFlyParticleDied)
		{
			FlyParticle->SetActive(false);
		}
		if (!ActiveBulletParticleDied)
		{
			BulletParticle->SetActive(false);
		}
	}
	if (PrepareDestory)
	{
		DestoryCount += DeltaTime;
		if (DestoryCount > DestroyDelay)
		{
			Destroy();
		}
	}
}

void ASkillDirectionActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHeroCharacter* hero = Cast<AHeroCharacter>(OtherActor);
	if (IsValid(hero) && IsValid(Attacker) && hero->TeamId != Attacker->TeamId && !TargetActors.Contains(hero))
	{
		AHeroCharacter::localPC->ServerAttackCompute(
			Attacker, hero, DamageType, Damage, false);
		TargetActors.Add(hero);
	}
}

void ASkillDirectionActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASkillDirectionActor, Direction);
	DOREPLIFETIME(ASkillDirectionActor, Skill);
	DOREPLIFETIME(ASkillDirectionActor, Attacker);
	DOREPLIFETIME(ASkillDirectionActor, TargetActors);
}
