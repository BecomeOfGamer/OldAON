// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/MOBAPrivatePCH.h"
#include "Public/HeroBuff.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHeroBuff() {}
// Cross Module References
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EHeroBuffProperty();
	UPackage* Z_Construct_UPackage__Script_MOBA();
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EHeroBuffState();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_BeDamage();
	MOBA_API UClass* Z_Construct_UClass_AHeroBuff();
	MOBA_API UEnum* Z_Construct_UEnum_MOBA_EDamageType();
	MOBA_API UClass* Z_Construct_UClass_AHeroCharacter_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_BeHeal();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_BeStealLife();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_BeStuned();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_Clone();
	MOBA_API UClass* Z_Construct_UClass_AHeroBuff_NoRegister();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_CloneArray();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_CreateDamage();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_NewHeroBuff();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnAbilityExecuted();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnAbilityStart();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackLanded();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackMiss();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackStart();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnDeath();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnHealLanded();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnHeroKilled();
	MOBA_API UFunction* Z_Construct_UFunction_AHeroBuff_OnStealLife();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
static UEnum* EHeroBuffProperty_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_EHeroBuffProperty, Z_Construct_UPackage__Script_MOBA(), TEXT("EHeroBuffProperty"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EHeroBuffProperty(EHeroBuffProperty_StaticEnum, TEXT("/Script/MOBA"), TEXT("EHeroBuffProperty"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_EHeroBuffProperty()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffProperty_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EHeroBuffProperty"), 0, Get_Z_Construct_UEnum_MOBA_EHeroBuffProperty_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EHeroBuffProperty"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EHeroBuffProperty::PhysicalDamageOutputPercentage"), 0);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MagicalDamageOutputPercentage"), 1);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::PureDamageOutputPercentage"), 2);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::PhysicalDamageInputPercentage"), 3);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MagicDamageInputPercentage"), 4);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::PureDamageInputPercentage"), 5);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MoveSpeedRatio"), 6);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MoveSpeedConstant"), 7);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MoveSpeedUnique"), 8);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MoveSpeedFixed"), 9);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AttackSpeedRatio"), 10);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AttackSpeedConstant"), 11);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MinHealth"), 12);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MaxHealth"), 13);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MinMana"), 14);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::MaxMana"), 15);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::BaseAttackSpeedFixed"), 16);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AbsorbPhysicalDamagePercentage"), 17);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AbsorbMagicalDamagePercentage"), 18);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AbsorbPureDamagePercentage"), 19);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::HealPercentage"), 20);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::ManaRegenConstant"), 21);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::ManaRegenPercentage"), 22);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::ManaRegenRatio"), 23);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::HealthRegenConstant"), 24);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::HealthRegenPercentage"), 25);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::HealthRegenRatio"), 26);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AttackBounsConstantWhite"), 27);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AttackBounsConstantGreen"), 28);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::AttackBounsPercentage"), 29);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::ArmorBounsConstant"), 30);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::ArmorBounsPercentage"), 31);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::EndBuffProperty"), 32);
			EnumNames.Emplace(TEXT("EHeroBuffProperty::EHeroBuffProperty_MAX"), 33);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EHeroBuffProperty");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("AbsorbMagicalDamagePercentage.ToolTip"), TEXT("\x5438\x6536\x7269\x7406\x50b7\x5bb3(\x767e\x5206\x6bd4) EX. 0.1 \x5438\x6536\x53d7\x5230\x7684")TEXT("10%\x7269\x7406\x50b7\x5bb3"));
			MetaData->SetValue(ReturnEnum, TEXT("AbsorbPhysicalDamagePercentage.ToolTip"), TEXT("\x6539\x8b8a\x57fa\x790e\x653b\x901f(\x767e\x5206\x6bd4) EX. 0.9 \x57fa\x790e\x653b\x901f\x5f9e")TEXT("1.8\x8b8a\x70ba")TEXT("0.9"));
			MetaData->SetValue(ReturnEnum, TEXT("AbsorbPureDamagePercentage.ToolTip"), TEXT("\x5438\x6536\x9b54\x6cd5\x50b7\x5bb3(\x767e\x5206\x6bd4) EX. 0.1 \x5438\x6536\x53d7\x5230\x7684")TEXT("10%\x9b54\x6cd5\x50b7\x5bb3"));
			MetaData->SetValue(ReturnEnum, TEXT("ArmorBounsConstant.ToolTip"), TEXT("\x653b\x64ca\x52a0\x6210(\x767e\x5206\x6bd4) EX. 2 \x653b\x64ca\x767d\x5b57\x4e58")TEXT("2\x52a0\x5230\x7da0\x5b57 \x4e0d\x88ab\x5176\x5b83\x653b\x64ca\x52a0\x6210\x5f71\x97ff"));
			MetaData->SetValue(ReturnEnum, TEXT("ArmorBounsPercentage.ToolTip"), TEXT("\x9632\x79a6\x52a0\x6210(\x56fa\x5b9a\x503c) EX. 5 \x9632\x79a6\x767d\x5b57+5"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackBounsConstantGreen.ToolTip"), TEXT("\x653b\x64ca\x52a0\x6210(\x56fa\x5b9a\x503c) EX. 30 \x653b\x64ca\x767d\x5b57+30 \x53ef\x4ee5\x88ab\x5176\x5b83\x653b\x64ca\x52a0\x6210\x5f71\x97ff"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackBounsConstantWhite.ToolTip"), TEXT("\x56de\x8840(\x6bd4\x4f8b\x52a0\x6210) EX. 2 \x56de\x5fa9\x8840\x91cf+200%=300% \x5982\x679c\x7576\x524d\x56de\x8840")TEXT("50\x5c31\x8b8a\x6210")TEXT("150"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackBounsPercentage.ToolTip"), TEXT("\x653b\x64ca\x52a0\x6210(\x56fa\x5b9a\x503c) EX. 30 \x653b\x64ca\x7da0\x5b57+30 \x4e0d\x6703\x88ab\x5176\x5b83\x653b\x64ca\x52a0\x6210\x5f71\x97ff"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackSpeedConstant.ToolTip"), TEXT("\x653b\x901f\x52a0\x6210(\x767e\x5206\x6bd4) EX. 2 2\x500d\x653b\x901f\x7a81\x7834\x57fa\x790e\x653b\x901f\x9650\x5236"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackSpeedRatio.ToolTip"), TEXT("\x56fa\x5b9a\x79fb\x52d5\x901f\x5ea6 EX. 700 \x56fa\x5b9a")TEXT("700\x8dd1\x901f"));
			MetaData->SetValue(ReturnEnum, TEXT("BaseAttackSpeedFixed.ToolTip"), TEXT("\x9396\x6700\x9ad8\x9b54 EX. 400 \x9b54\x529b\x4e0d\x6703\x9ad8\x65bc")TEXT("400"));
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("EndBuffProperty.ToolTip"), TEXT("\x9632\x79a6\x52a0\x6210(\x767e\x5206\x6bd4) EX. 1 \x7576\x524d\x9632\x79a6\x4e58\x4e0a")TEXT("1\x52a0\x5230\x7da0\x5b57"));
			MetaData->SetValue(ReturnEnum, TEXT("HealPercentage.ToolTip"), TEXT("\x5438\x6536\x9b54\x6cd5\x50b7\x5bb3(\x767e\x5206\x6bd4) EX. 0.1 \x5438\x6536\x53d7\x5230\x7684")TEXT("10%\x9b54\x6cd5\x50b7\x5bb3"));
			MetaData->SetValue(ReturnEnum, TEXT("HealthRegenConstant.ToolTip"), TEXT("\x56de\x9b54(\x6bd4\x4f8b\x52a0\x6210) EX. 2 \x56de\x5fa9\x9b54\x529b+200%=300% \x5982\x679c\x7576\x524d\x56de\x9b54")TEXT("20\x5c31\x8b8a\x6210")TEXT("60"));
			MetaData->SetValue(ReturnEnum, TEXT("HealthRegenPercentage.ToolTip"), TEXT("\x56de\x8840(\x56fa\x5b9a\x503c) EX. 10 \x6bcf\x79d2\x56de\x8840\x589e\x52a0")TEXT("10"));
			MetaData->SetValue(ReturnEnum, TEXT("HealthRegenRatio.ToolTip"), TEXT("\x56de\x8840(\x767e\x5206\x6bd4) EX. 0.01 \x6bcf\x79d2\x56de\x9b54\x589e\x52a0\x7e3d\x751f\x547d\x7684")TEXT("1%"));
			MetaData->SetValue(ReturnEnum, TEXT("MagicalDamageOutputPercentage.ToolTip"), TEXT("\x7269\x7406\x50b7\x5bb3\x8f38\x51fa\x52a0\x6210(\x767e\x5206\x6bd4) EX. 0.1 \x52a0\x6210")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("MagicDamageInputPercentage.ToolTip"), TEXT("\x53d7\x5230\x7269\x7406\x50b7\x5bb3\x52a0\x6210(\x767e\x5206\x6bd4) EX. -0.1 \x6e1b\x50b7")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("ManaRegenConstant.ToolTip"), TEXT("\x6cbb\x7652\x52a0\x6210(\x767e\x5206\x6bd4) EX. 0.2 \x6cbb\x7642\x751f\x547d\x63d0\x5347")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("ManaRegenPercentage.ToolTip"), TEXT("\x56de\x9b54(\x56fa\x5b9a\x503c) EX. 3 \x6bcf\x79d2\x56de\x9b54\x589e\x52a0")TEXT("3"));
			MetaData->SetValue(ReturnEnum, TEXT("ManaRegenRatio.ToolTip"), TEXT("\x56de\x9b54(\x767e\x5206\x6bd4) EX. 0.03 \x6bcf\x79d2\x56de\x9b54\x589e\x52a0\x7e3d\x9b54\x529b\x7684")TEXT("3%"));
			MetaData->SetValue(ReturnEnum, TEXT("MaxHealth.ToolTip"), TEXT("\x9396\x6700\x4f4e\x8840 EX. 100 \x8840\x91cf\x4e0d\x6703\x5c11\x65bc")TEXT("100"));
			MetaData->SetValue(ReturnEnum, TEXT("MaxMana.ToolTip"), TEXT("\x9396\x6700\x4f4e\x9b54 EX. 200 \x9b54\x529b\x4e0d\x6703\x4f4e\x65bc")TEXT("200"));
			MetaData->SetValue(ReturnEnum, TEXT("MinHealth.ToolTip"), TEXT("\x653b\x901f\x52a0\x6210(\x56fa\x5b9a\x503c) EX. 200 \x589e\x52a0")TEXT("200%\x653b\x901f \x6700\x9ad8")TEXT("500% \x52a0\x57fa\x790e\x503c")TEXT("100\x6700\x9ad8")TEXT("600"));
			MetaData->SetValue(ReturnEnum, TEXT("MinMana.ToolTip"), TEXT("\x9396\x6700\x9ad8\x8840 EX. 2000 \x8840\x91cf\x4e0d\x6703\x9ad8\x65bc")TEXT("2000"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnEnum, TEXT("MoveSpeedConstant.ToolTip"), TEXT("\x79fb\x52d5\x901f\x5ea6\x52a0\x6210(\x767e\x5206\x6bd4) EX. 2 2\x500d\x8dd1\x901f"));
			MetaData->SetValue(ReturnEnum, TEXT("MoveSpeedFixed.ToolTip"), TEXT("\x79fb\x52d5\x901f\x5ea6\x52a0\x6210(\x552f\x4e00) EX. 80 \x591a\x500b\x88dd\x5099\x4e5f\x662f\x56fa\x5b9a\x52a0")TEXT("80\x8dd1\x901f"));
			MetaData->SetValue(ReturnEnum, TEXT("MoveSpeedRatio.ToolTip"), TEXT("\x53d7\x5230\x771f\x50b7\x50b7\x5bb3\x52a0\x6210(\x767e\x5206\x6bd4) EX. -0.1 \x6e1b\x50b7")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("MoveSpeedUnique.ToolTip"), TEXT("\x79fb\x52d5\x901f\x5ea6\x52a0\x6210(\x56fa\x5b9a\x503c) EX. 100 \x589e\x52a0")TEXT("100\x8dd1\x901f"));
			MetaData->SetValue(ReturnEnum, TEXT("PhysicalDamageInputPercentage.ToolTip"), TEXT("\x771f\x50b7\x50b7\x5bb3\x8f38\x51fa\x52a0\x6210(\x767e\x5206\x6bd4) EX. 0.1 \x52a0\x6210")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("PureDamageInputPercentage.ToolTip"), TEXT("\x53d7\x5230\x9b54\x6cd5\x50b7\x5bb3\x52a0\x6210(\x767e\x5206\x6bd4) EX. -0.1 \x6e1b\x50b7")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("PureDamageOutputPercentage.ToolTip"), TEXT("\x9b54\x6cd5\x50b7\x5bb3\x8f38\x51fa\x52a0\x6210(\x767e\x5206\x6bd4) EX. 0.1 \x52a0\x6210")TEXT("10%"));
			MetaData->SetValue(ReturnEnum, TEXT("ToolTip"), TEXT("BaseAttack\x662f\x539f\x59cb\x653b\x64ca\x529b\n\x7269\x7406\x8f38\x51fa = (((BaseAttack+AttackBounsConstantWhite)*AttackBounsPercentage+AttackBounsConstantGreen)**PhysicalDamageOutputPercentage)\nBaseManaRegen\x662f\x539f\x59cb\x56de\x9b54\x901f\x5ea6\n\x56de\x9b54\x901f\x5ea6 = (BaseManaRegen*ManaRegenPercentage+ManaRegenConstant)*HealthRegenRatio\nBaseAttackSpeed \x662f\x539f\x59cb\x653b\x901f\xff0c")TEXT("BaseAttackSpeedFixed \x662f\x8b8a\x8eab\x7cfb\x7684\x57fa\x790e\x653b\x901f\n\x653b\x64ca\x901f\x5ea6 = (BaseAttackSpeed*AttackSpeedConstant)*AttackSpeedRatio\n\x653b\x64ca\x901f\x5ea6 = (BaseAttackSpeedFixed*AttackSpeedConstant)*AttackSpeedRatio"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffProperty_CRC() { return 982011080U; }
static UEnum* EHeroBuffState_StaticEnum()
{
	static UEnum* Singleton = nullptr;
	if (!Singleton)
	{
		Singleton = GetStaticEnum(Z_Construct_UEnum_MOBA_EHeroBuffState, Z_Construct_UPackage__Script_MOBA(), TEXT("EHeroBuffState"));
	}
	return Singleton;
}
static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EHeroBuffState(EHeroBuffState_StaticEnum, TEXT("/Script/MOBA"), TEXT("EHeroBuffState"), false, nullptr, nullptr);
	UEnum* Z_Construct_UEnum_MOBA_EHeroBuffState()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_MOBA();
		extern uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffState_CRC();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EHeroBuffState"), 0, Get_Z_Construct_UEnum_MOBA_EHeroBuffState_CRC(), false);
		if (!ReturnEnum)
		{
			ReturnEnum = new(EC_InternalUseOnlyConstructor, Outer, TEXT("EHeroBuffState"), RF_Public|RF_Transient|RF_MarkAsNative) UEnum(FObjectInitializer());
			TArray<TPair<FName, int64>> EnumNames;
			EnumNames.Emplace(TEXT("EHeroBuffState::Dazzing"), 0);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanMove"), 1);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanAttack"), 2);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanSkill"), 3);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanEquipment"), 4);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanBeSkillSight"), 5);
			EnumNames.Emplace(TEXT("EHeroBuffState::BanBeAttackSight"), 6);
			EnumNames.Emplace(TEXT("EHeroBuffState::MagicImmune"), 7);
			EnumNames.Emplace(TEXT("EHeroBuffState::Invulnerable"), 8);
			EnumNames.Emplace(TEXT("EHeroBuffState::AttackUseMagic"), 9);
			EnumNames.Emplace(TEXT("EHeroBuffState::AttackUsePure"), 10);
			EnumNames.Emplace(TEXT("EHeroBuffState::EndBuffKind"), 11);
			EnumNames.Emplace(TEXT("EHeroBuffState::EHeroBuffState_MAX"), 12);
			ReturnEnum->SetEnums(EnumNames, UEnum::ECppForm::EnumClass);
			ReturnEnum->CppType = TEXT("EHeroBuffState");
#if WITH_METADATA
			UMetaData* MetaData = ReturnEnum->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnEnum, TEXT("AttackUseMagic.ToolTip"), TEXT("\x7121\x6575"));
			MetaData->SetValue(ReturnEnum, TEXT("AttackUsePure.ToolTip"), TEXT("\x666e\x653b\x8f49\x63db\x70ba\x9b54\x6cd5\x50b7\x5bb3"));
			MetaData->SetValue(ReturnEnum, TEXT("BanAttack.ToolTip"), TEXT("\x7981\x79fb\x52d5"));
			MetaData->SetValue(ReturnEnum, TEXT("BanBeAttackSight.ToolTip"), TEXT("\x4e0d\x80fd\x88ab\x6cd5\x8853\x6307\x5b9a"));
			MetaData->SetValue(ReturnEnum, TEXT("BanBeSkillSight.ToolTip"), TEXT("\x7981\x9053\x5177"));
			MetaData->SetValue(ReturnEnum, TEXT("BanEquipment.ToolTip"), TEXT("\x7981\x6280\x80fd"));
			MetaData->SetValue(ReturnEnum, TEXT("BanMove.ToolTip"), TEXT("\x6688\x70ab"));
			MetaData->SetValue(ReturnEnum, TEXT("BanSkill.ToolTip"), TEXT("\x7981\x653b\x64ca"));
			MetaData->SetValue(ReturnEnum, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnEnum, TEXT("EndBuffKind.ToolTip"), TEXT("\x666e\x653b\x8f49\x63db\x70ba\x771f\x5be6\x50b7\x5bb3"));
			MetaData->SetValue(ReturnEnum, TEXT("Invulnerable.ToolTip"), TEXT("\x9b54\x6cd5\x514d\x75ab"));
			MetaData->SetValue(ReturnEnum, TEXT("MagicImmune.ToolTip"), TEXT("\x4e0d\x80fd\x88ab\x666e\x653b\x6307\x5b9a"));
			MetaData->SetValue(ReturnEnum, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnEnum;
	}
	uint32 Get_Z_Construct_UEnum_MOBA_EHeroBuffState_CRC() { return 1848136541U; }
	static FName NAME_AHeroBuff_BeDamage = FName(TEXT("BeDamage"));
	void AHeroBuff::BeDamage(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage)
	{
		HeroBuff_eventBeDamage_Parms Parms;
		Parms.attacker=attacker;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_BeDamage),&Parms);
	}
	static FName NAME_AHeroBuff_BeHeal = FName(TEXT("BeHeal"));
	void AHeroBuff::BeHeal(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
	{
		HeroBuff_eventBeHeal_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.heal_mount=heal_mount;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_BeHeal),&Parms);
	}
	static FName NAME_AHeroBuff_BeStealLife = FName(TEXT("BeStealLife"));
	void AHeroBuff::BeStealLife(AHeroCharacter* caster, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage, float heal_mount)
	{
		HeroBuff_eventBeStealLife_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		Parms.heal_mount=heal_mount;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_BeStealLife),&Parms);
	}
	static FName NAME_AHeroBuff_BeStuned = FName(TEXT("BeStuned"));
	void AHeroBuff::BeStuned(AHeroCharacter* caster, AHeroCharacter* target, float time)
	{
		HeroBuff_eventBeStuned_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.time=time;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_BeStuned),&Parms);
	}
	static FName NAME_AHeroBuff_CreateDamage = FName(TEXT("CreateDamage"));
	void AHeroBuff::CreateDamage(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage)
	{
		HeroBuff_eventCreateDamage_Parms Parms;
		Parms.attacker=attacker;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_CreateDamage),&Parms);
	}
	static FName NAME_AHeroBuff_OnAbilityExecuted = FName(TEXT("OnAbilityExecuted"));
	void AHeroBuff::OnAbilityExecuted(AHeroCharacter* caster, AHeroCharacter* target, FVector dest)
	{
		HeroBuff_eventOnAbilityExecuted_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.dest=dest;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnAbilityExecuted),&Parms);
	}
	static FName NAME_AHeroBuff_OnAbilityStart = FName(TEXT("OnAbilityStart"));
	void AHeroBuff::OnAbilityStart(AHeroCharacter* caster, AHeroCharacter* target, FVector dest)
	{
		HeroBuff_eventOnAbilityStart_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.dest=dest;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnAbilityStart),&Parms);
	}
	static FName NAME_AHeroBuff_OnAttackLanded = FName(TEXT("OnAttackLanded"));
	void AHeroBuff::OnAttackLanded(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage)
	{
		HeroBuff_eventOnAttackLanded_Parms Parms;
		Parms.attacker=attacker;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnAttackLanded),&Parms);
	}
	static FName NAME_AHeroBuff_OnAttackMiss = FName(TEXT("OnAttackMiss"));
	void AHeroBuff::OnAttackMiss(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage)
	{
		HeroBuff_eventOnAttackMiss_Parms Parms;
		Parms.attacker=attacker;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnAttackMiss),&Parms);
	}
	static FName NAME_AHeroBuff_OnAttackStart = FName(TEXT("OnAttackStart"));
	void AHeroBuff::OnAttackStart(AHeroCharacter* attacker, AHeroCharacter* target, EDamageType dtype, float OriginDamage, float RealDamage)
	{
		HeroBuff_eventOnAttackStart_Parms Parms;
		Parms.attacker=attacker;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.OriginDamage=OriginDamage;
		Parms.RealDamage=RealDamage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnAttackStart),&Parms);
	}
	static FName NAME_AHeroBuff_OnDeath = FName(TEXT("OnDeath"));
	void AHeroBuff::OnDeath(AHeroCharacter* caster, AHeroCharacter* killer, EDamageType dtype, float damage)
	{
		HeroBuff_eventOnDeath_Parms Parms;
		Parms.caster=caster;
		Parms.killer=killer;
		Parms.dtype=dtype;
		Parms.damage=damage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnDeath),&Parms);
	}
	static FName NAME_AHeroBuff_OnHealLanded = FName(TEXT("OnHealLanded"));
	void AHeroBuff::OnHealLanded(AHeroCharacter* caster, AHeroCharacter* target, float heal_mount)
	{
		HeroBuff_eventOnHealLanded_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.heal_mount=heal_mount;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnHealLanded),&Parms);
	}
	static FName NAME_AHeroBuff_OnHeroKilled = FName(TEXT("OnHeroKilled"));
	void AHeroBuff::OnHeroKilled(AHeroCharacter* caster, AHeroCharacter* killer, EDamageType dtype, float damage)
	{
		HeroBuff_eventOnHeroKilled_Parms Parms;
		Parms.caster=caster;
		Parms.killer=killer;
		Parms.dtype=dtype;
		Parms.damage=damage;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnHeroKilled),&Parms);
	}
	static FName NAME_AHeroBuff_OnStealLife = FName(TEXT("OnStealLife"));
	void AHeroBuff::OnStealLife(AHeroCharacter* caster, AHeroCharacter* target, EDamageType dtype, float damage, float heal_mount)
	{
		HeroBuff_eventOnStealLife_Parms Parms;
		Parms.caster=caster;
		Parms.target=target;
		Parms.dtype=dtype;
		Parms.damage=damage;
		Parms.heal_mount=heal_mount;
		ProcessEvent(FindFunctionChecked(NAME_AHeroBuff_OnStealLife),&Parms);
	}
	void AHeroBuff::StaticRegisterNativesAHeroBuff()
	{
		UClass* Class = AHeroBuff::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "Clone", (Native)&AHeroBuff::execClone },
			{ "CloneArray", (Native)&AHeroBuff::execCloneArray },
			{ "NewHeroBuff", (Native)&AHeroBuff::execNewHeroBuff },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_BeDamage()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BeDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventBeDamage_Parms));
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventBeDamage_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventBeDamage_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventBeDamage_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventBeDamage_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_attacker = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("attacker"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(attacker, HeroBuff_eventBeDamage_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x53d7\x5230\x50b7\x5bb3\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_BeHeal()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BeHeal"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventBeHeal_Parms));
			UProperty* NewProp_heal_mount = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("heal_mount"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(heal_mount, HeroBuff_eventBeHeal_Parms), 0x0010000000000080);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventBeHeal_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventBeHeal_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x88ab\x6cbb\x7642\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_BeStealLife()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BeStealLife"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventBeStealLife_Parms));
			UProperty* NewProp_heal_mount = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("heal_mount"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(heal_mount, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080);
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventBeStealLife_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x88ab\x5438\x6536\x751f\x547d\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_BeStuned()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BeStuned"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventBeStuned_Parms));
			UProperty* NewProp_time = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("time"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(time, HeroBuff_eventBeStuned_Parms), 0x0010000000000080);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventBeStuned_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventBeStuned_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x88ab\x6688\x7729\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_Clone()
	{
		struct HeroBuff_eventClone_Parms
		{
			AHeroBuff* ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Clone"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020401, 65535, sizeof(HeroBuff_eventClone_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventClone_Parms), 0x0010000000000580, Z_Construct_UClass_AHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_CloneArray()
	{
		struct HeroBuff_eventCloneArray_Parms
		{
			TArray<AHeroBuff*> input;
			TArray<AHeroBuff*> ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CloneArray"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(HeroBuff_eventCloneArray_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventCloneArray_Parms), 0x0010000000000580);
			UProperty* NewProp_ReturnValue_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AHeroBuff_NoRegister());
			UProperty* NewProp_input = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("input"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(input, HeroBuff_eventCloneArray_Parms), 0x0010000000000080);
			UProperty* NewProp_input_Inner = new(EC_InternalUseOnlyConstructor, NewProp_input, TEXT("input"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_CreateDamage()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CreateDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventCreateDamage_Parms));
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventCreateDamage_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventCreateDamage_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventCreateDamage_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventCreateDamage_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_attacker = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("attacker"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(attacker, HeroBuff_eventCreateDamage_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x9020\x6210\x50b7\x5bb3\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_NewHeroBuff()
	{
		struct HeroBuff_eventNewHeroBuff_Parms
		{
			AHeroBuff* ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("NewHeroBuff"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04022401, 65535, sizeof(HeroBuff_eventNewHeroBuff_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, HeroBuff_eventNewHeroBuff_Parms), 0x0010000000000580, Z_Construct_UClass_AHeroBuff_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("NewObject"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnAbilityExecuted()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnAbilityExecuted"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08820800, 65535, sizeof(HeroBuff_eventOnAbilityExecuted_Parms));
			UProperty* NewProp_dest = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dest"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(dest, HeroBuff_eventOnAbilityExecuted_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnAbilityExecuted_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnAbilityExecuted_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6210\x529f\x65bd\x653e\x6280\x80fd\x9032\x5165\x65bd\x6cd5\x5f8c\x6416"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnAbilityStart()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnAbilityStart"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08820800, 65535, sizeof(HeroBuff_eventOnAbilityStart_Parms));
			UProperty* NewProp_dest = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dest"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(dest, HeroBuff_eventOnAbilityStart_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnAbilityStart_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnAbilityStart_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6e96\x5099\x65bd\x653e\x6280\x80fd\x9032\x5165\x65bd\x6cd5\x524d\x6416"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackLanded()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnAttackLanded"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnAttackLanded_Parms));
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventOnAttackLanded_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventOnAttackLanded_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnAttackLanded_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnAttackLanded_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_attacker = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("attacker"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(attacker, HeroBuff_eventOnAttackLanded_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x653b\x64ca\x6253\x51fa\x50b7\x5bb3\x5f8c\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackMiss()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnAttackMiss"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnAttackMiss_Parms));
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventOnAttackMiss_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventOnAttackMiss_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnAttackMiss_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnAttackMiss_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_attacker = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("attacker"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(attacker, HeroBuff_eventOnAttackMiss_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x653b\x64ca\x6253\x51fa\x4f46\x88ab\x9583\x907f"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnAttackStart()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnAttackStart"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnAttackStart_Parms));
			UProperty* NewProp_RealDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("RealDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(RealDamage, HeroBuff_eventOnAttackStart_Parms), 0x0010000000000080);
			UProperty* NewProp_OriginDamage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OriginDamage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OriginDamage, HeroBuff_eventOnAttackStart_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnAttackStart_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnAttackStart_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_attacker = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("attacker"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(attacker, HeroBuff_eventOnAttackStart_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6e96\x5099\x653b\x64ca\xff0c\x4f46\x653b\x64ca\x9084\x6c92\x6253\x51fa\x53bb"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnDeath()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnDeath"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnDeath_Parms));
			UProperty* NewProp_damage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("damage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(damage, HeroBuff_eventOnDeath_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnDeath_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_killer = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("killer"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(killer, HeroBuff_eventOnDeath_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnDeath_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x88ab\x6253\x6b7b\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnHealLanded()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnHealLanded"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnHealLanded_Parms));
			UProperty* NewProp_heal_mount = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("heal_mount"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(heal_mount, HeroBuff_eventOnHealLanded_Parms), 0x0010000000000080);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnHealLanded_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnHealLanded_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x6cbb\x7642\x5225\x4eba\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnHeroKilled()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnHeroKilled"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnHeroKilled_Parms));
			UProperty* NewProp_damage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("damage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(damage, HeroBuff_eventOnHeroKilled_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnHeroKilled_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_killer = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("killer"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(killer, HeroBuff_eventOnHeroKilled_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnHeroKilled_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x64ca\x6bba\x6575\x65b9\x82f1\x96c4\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AHeroBuff_OnStealLife()
	{
		UObject* Outer = Z_Construct_UClass_AHeroBuff();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnStealLife"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x08020800, 65535, sizeof(HeroBuff_eventOnStealLife_Parms));
			UProperty* NewProp_heal_mount = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("heal_mount"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(heal_mount, HeroBuff_eventOnStealLife_Parms), 0x0010000000000080);
			UProperty* NewProp_damage = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("damage"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(damage, HeroBuff_eventOnStealLife_Parms), 0x0010000000000080);
			UProperty* NewProp_dtype = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("dtype"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(CPP_PROPERTY_BASE(dtype, HeroBuff_eventOnStealLife_Parms), 0x0010000000000080, Z_Construct_UEnum_MOBA_EDamageType());
			UProperty* NewProp_dtype_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_dtype, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_target = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("target"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(target, HeroBuff_eventOnStealLife_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			UProperty* NewProp_caster = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("caster"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(caster, HeroBuff_eventOnStealLife_Parms), 0x0010000000000080, Z_Construct_UClass_AHeroCharacter_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("MOBA"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("\x5438\x6536\x6575\x4eba\x751f\x547d\x7684\x77ac\x9593"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHeroBuff_NoRegister()
	{
		return AHeroBuff::StaticClass();
	}
	UClass* Z_Construct_UClass_AHeroBuff()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_MOBA();
			OuterClass = AHeroBuff::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_BeDamage());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_BeHeal());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_BeStealLife());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_BeStuned());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_Clone());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_CloneArray());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_CreateDamage());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_NewHeroBuff());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnAbilityExecuted());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnAbilityStart());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnAttackLanded());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnAttackMiss());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnAttackStart());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnDeath());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnHealLanded());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnHeroKilled());
				OuterClass->LinkChild(Z_Construct_UFunction_AHeroBuff_OnStealLife());

				UProperty* NewProp_Duration = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Duration"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(Duration, AHeroBuff), 0x0010000000000015);
				UProperty* NewProp_Superposition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Superposition"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Superposition, AHeroBuff), 0x0010000000000015);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(CanSuperposition, AHeroBuff);
				UProperty* NewProp_CanSuperposition = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CanSuperposition"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(CanSuperposition, AHeroBuff), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(CanSuperposition, AHeroBuff), sizeof(uint8), false);
				UProperty* NewProp_BuffTarget = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BuffTarget"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(BuffTarget, AHeroBuff), 0x0010000000000015);
				UProperty* NewProp_BuffTarget_Inner = new(EC_InternalUseOnlyConstructor, NewProp_BuffTarget, TEXT("BuffTarget"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_AHeroCharacter_NoRegister());
				UProperty* NewProp_BuffPropertyMap = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BuffPropertyMap"), RF_Public|RF_Transient|RF_MarkAsNative) UMapProperty(CPP_PROPERTY_BASE(BuffPropertyMap, AHeroBuff), 0x0010000000000005);
				UProperty* NewProp_BuffPropertyMap_Key_KeyProp = new(EC_InternalUseOnlyConstructor, NewProp_BuffPropertyMap, TEXT("BuffPropertyMap_Key"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000001);
				UProperty* NewProp_BuffPropertyMap_ValueProp = new(EC_InternalUseOnlyConstructor, NewProp_BuffPropertyMap, TEXT("BuffPropertyMap"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(FObjectInitializer(), EC_CppProperty, 1, 0x0000000000000001);
				UProperty* NewProp_BuffKind = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BuffKind"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(BuffKind, AHeroBuff), 0x0010000000000015);
				UProperty* NewProp_BuffKind_Inner = new(EC_InternalUseOnlyConstructor, NewProp_BuffKind, TEXT("BuffKind"), RF_Public|RF_Transient|RF_MarkAsNative) UEnumProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UEnum_MOBA_EHeroBuffState());
				UProperty* NewProp_BuffKind_Inner_Underlying = new(EC_InternalUseOnlyConstructor, NewProp_BuffKind_Inner, TEXT("UnderlyingType"), RF_Public|RF_Transient|RF_MarkAsNative) UByteProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_Head = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Head"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Head, AHeroBuff), 0x0010000000000015, Z_Construct_UClass_UTexture2D_NoRegister());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(FollowActor, AHeroBuff);
				UProperty* NewProp_FollowActor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FollowActor"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(FollowActor, AHeroBuff), 0x0010000000000015, CPP_BOOL_PROPERTY_BITMASK(FollowActor, AHeroBuff), sizeof(bool), true);
				UProperty* NewProp_Name = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Name"), RF_Public|RF_Transient|RF_MarkAsNative) UStrProperty(CPP_PROPERTY_BASE(Name, AHeroBuff), 0x0010000000000015);
				UProperty* NewProp_Priority = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Priority"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(Priority, AHeroBuff), 0x0010000000000015);
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_BeDamage(), "BeDamage"); // 755936290
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_BeHeal(), "BeHeal"); // 1562678336
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_BeStealLife(), "BeStealLife"); // 862845032
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_BeStuned(), "BeStuned"); // 3541539770
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_Clone(), "Clone"); // 1605607165
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_CloneArray(), "CloneArray"); // 3132089141
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_CreateDamage(), "CreateDamage"); // 234618424
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_NewHeroBuff(), "NewHeroBuff"); // 1512306067
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnAbilityExecuted(), "OnAbilityExecuted"); // 629870909
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnAbilityStart(), "OnAbilityStart"); // 2405546488
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnAttackLanded(), "OnAttackLanded"); // 1037278818
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnAttackMiss(), "OnAttackMiss"); // 1113594814
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnAttackStart(), "OnAttackStart"); // 1787572903
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnDeath(), "OnDeath"); // 2586248524
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnHealLanded(), "OnHealLanded"); // 2236767232
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnHeroKilled(), "OnHeroKilled"); // 1162514466
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AHeroBuff_OnStealLife(), "OnStealLife"); // 1256104908
				static TCppClassTypeInfo<TCppClassTypeTraits<AHeroBuff> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("HeroBuff.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Duration, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Duration, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Duration, TEXT("ToolTip"), TEXT("\x6bcf\x4e00\x5c64\x6301\x7e8c\x6642\x9593"));
				MetaData->SetValue(NewProp_Superposition, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Superposition, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Superposition, TEXT("ToolTip"), TEXT("\x758a\x52a0\x5c64\x6578"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_CanSuperposition, TEXT("ToolTip"), TEXT("\x662f\x5426\x80fd\x758a\x52a0"));
				MetaData->SetValue(NewProp_BuffTarget, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_BuffTarget, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_BuffPropertyMap, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_BuffPropertyMap, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_BuffPropertyMap, TEXT("ToolTip"), TEXT("\x984d\x5916\x52a0\x6210"));
				MetaData->SetValue(NewProp_BuffKind, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_BuffKind, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_BuffKind, TEXT("ToolTip"), TEXT("\x984d\x5916\x6548\x679c"));
				MetaData->SetValue(NewProp_Head, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Head, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Head, TEXT("ToolTip"), TEXT("logo"));
				MetaData->SetValue(NewProp_FollowActor, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_FollowActor, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_FollowActor, TEXT("ToolTip"), TEXT("Follow Actor"));
				MetaData->SetValue(NewProp_Name, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Name, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Name, TEXT("ToolTip"), TEXT("Buff \x540d\x5b57"));
				MetaData->SetValue(NewProp_Priority, TEXT("Category"), TEXT("HeroBuff"));
				MetaData->SetValue(NewProp_Priority, TEXT("ModuleRelativePath"), TEXT("Public/HeroBuff.h"));
				MetaData->SetValue(NewProp_Priority, TEXT("ToolTip"), TEXT("Buff \x512a\x5148\x6b0a"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHeroBuff, 3910335570);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHeroBuff(Z_Construct_UClass_AHeroBuff, &AHeroBuff::StaticClass, TEXT("/Script/MOBA"), TEXT("AHeroBuff"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHeroBuff);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
