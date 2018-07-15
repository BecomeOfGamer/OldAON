#pragma once


UENUM(BlueprintType)
enum class EDamageType : uint8
{
	//物理傷害
	DAMAGE_PHYSICAL,
	//魔法傷害
	DAMAGE_MAGICAL,
	//真實傷害
	DAMAGE_PURE
};

UENUM(BlueprintType)
enum class EShieldType : uint8
{
	//通用護盾
	SHIELD_GENERAL,
	//物理傷害
	SHIELD_PHYSICAL,
	//魔法傷害
	SHIELD_MAGICAL
};

UENUM(BlueprintType)
enum class EHeroBuffState : uint8
{
	//暈炫
	Stunning,
	//禁移動
	BanMove,
	//禁攻擊
	BanAttack,
	//禁技能
	BanSkill,
	//禁道具
	BanEquipment,
	//不能被法術指定
	BanBeSkillSight,
	//不能被普攻指定
	BanBeAttackSight,
	//魔法免疫
	MagicalImmune,
	//物理免疫
	PhysicalImmune,
	//真傷免疫
	PureImmune,
	//無敵
	Invulnerable,
	//睡眠，被攻擊會醒來
	Sleeping,
	//普攻轉換為魔法傷害
	AttackUseMagic,
	//普攻轉換為真實傷害
	AttackUsePure,
	//隱形
	Invisible,
	//混色
	Blending,
	//可重生
	Rebirth,
	//無視負面狀態
	IgnoreUnfriendly,
	//被嘲諷中
	BeTaunt,
	//無法控制
	UnableToControl,
	//結束列舉
	EndBuffKind,
};
#define HEROS EHeroBuffState

// BaseAttack是原始攻擊力
// 物理輸出 = (((BaseAttack+AttackBounsConstantWhite)*(AttackBounsPercentage+1)+AttackBounsConstantGreen)*PhysicalDamageOutputPercentage)
// BaseManaRegen是原始回魔速度
// 回魔速度 = (BaseManaRegen*ManaRegenPercentage+ManaRegenConstant)*HealthRegenRatio
// BaseAttackSpeed 是原始攻速，BaseAttackSpeedFixed 是變身系的基礎攻速
// 攻擊速度 = (BaseAttackSpeed*AttackSpeedConstant)*AttackSpeedRatio
// 攻擊速度 = (BaseAttackSpeedFixed*AttackSpeedConstant)*AttackSpeedRatio
// 
// 可疊加的數值
UENUM(BlueprintType)
enum class EHeroBuffProperty : uint8
{
	//物理傷害輸出加成(百分比) EX. 0.1 加成10%
	PhysicalDamageOutputPercentage,
	//魔法傷害輸出加成(百分比) EX. 0.1 加成10%
	MagicalDamageOutputPercentage,
	//真傷傷害輸出加成(百分比) EX. 0.1 加成10%
	PureDamageOutputPercentage,
	//受到物理傷害加成(百分比) EX. -0.1 減傷10%
	PhysicalDamageInputPercentage,
	//受到魔法傷害加成(百分比) EX. -0.1 減傷10%
	MagicalDamageInputPercentage,
	//受到真實傷害加成(百分比) EX. -0.1 減傷10%
	PureDamageInputPercentage,
	//移動速度加成(百分比) EX. 2 2倍跑速
	MoveSpeedRatio,
	//移動速度加成(固定值) EX. 100 增加100跑速
	MoveSpeedConstant,
	//攻速加成(百分比) EX. 2 2倍攻速突破基礎攻速限制
	AttackSpeedRatio,
	//攻速加成(固定值) EX. 0.5 增加50%攻速 最高500% 加基礎值100最高600
	AttackSpeedConstant,
	//吸收物理傷害(百分比) EX. 0.1 吸收受到的10%物理傷害
	AbsorbPhysicalDamagePercentage,
	//吸收魔法傷害(百分比) EX. 0.1 吸收受到的10%魔法傷害
	AbsorbMagicalDamagePercentage,
	//吸收真實傷害(百分比) EX. 0.1 吸收受到的10%真實傷害
	AbsorbPureDamagePercentage,
	//治癒加成(百分比) EX. 0.2 治療生命提升10%
	HealPercentage,
	//回魔(固定值) EX. 3 每秒回魔增加3
	ManaRegenConstant,
	//回魔(百分比) EX. 0.03 每秒回魔增加總魔力的3%
	ManaRegenPercentage,
	//回魔(比例加成) EX. 2 回復魔力+200%=300% 如果當前回魔20就變成60
	ManaRegenRatio,
	//回血(固定值) EX. 10 每秒回血增加10
	HealthRegenConstant,
	//回血(百分比) EX. 0.01 每秒回血增加總生命的1%
	HealthRegenPercentage,
	//回血(比例加成) EX. 2 回復血量+200%=300% 如果當前回血50就變成150
	HealthRegenRatio,
	//攻擊加成(固定值) EX. 30 攻擊白字+30 可以被其它攻擊加成影響
	AttackBounsConstantWhite,
	//攻擊加成(固定值) EX. 30 攻擊綠字+30 不會被其它攻擊加成影響
	AttackBounsConstantGreen,
	//攻擊加成(百分比) EX. 2 攻擊白字乘2加到綠字 不被其它攻擊加成影響
	AttackBounsPercentage,
	//防禦加成(固定值) EX. 5 防禦白字+5
	ArmorBounsConstant,
	//防禦加成(百分比) EX. 1 當前防禦乘上1加到綠字
	ArmorBounsPercentage,
	//生命吸收 EX. 0.2 吸收造成傷害的20%
	StealHealth,
	//攻擊失誤機率 EX. 0.15 15%的機率miss
	AttackMiss,
	//格檔攻擊機率 EX. 0.25 25%的機率格檔物理傷害
	BlockingPhysical,
	//格檔魔法機率 EX. 0.25 25%的機率格檔魔法傷害
	BlockingMagical,
	//格檔真傷機率 EX. 0.25 25%的機率格檔真傷傷害
	BlockingPure,
	//格檔固定物理傷害 EX. 500 任何物理傷害先格檔500
	BlockingPhysicalConstant,
	//格檔固定魔法傷害 EX. 200 任何魔法傷害先格檔200
	BlockingMagicalConstant,
	//格檔固定真實傷害 EX. 50  任何真實傷害先格檔50
	BlockingPureConstant,
	//血量上限增加 EX. 300 增加300最大生命值
	HealthBouns,
	//魔量上限增加 EX. 250 增加250最大魔力值
	ManaBouns,
	//閃避機率 EX 0.1 有10%的閃避機率
	Dodge,
	//力量 EX. 1.5 就加1.5的力量
	Strength,
	//敏捷 EX. 2.5 就加2.5的敏捷
	Agility,
	//智慧 EX. 3.5 就加3.5的智慧
	Intelligence,
	// 結束列舉
	EndBuffProperty
};
#define HEROP EHeroBuffProperty

// 不可疊加的數值
UENUM(BlueprintType)
enum class EHeroBuffUnique : uint8
{
	//鎖最低血 EX. 100 血量不會少於100
	MinHealth,
	//鎖最高血 EX. 2000 血量不會高於2000
	MaxHealth,
	//鎖最低魔 EX. 200 魔力不會低於200
	MinMana,
	//鎖最高魔 EX. 400 魔力不會高於400
	MaxMana,
	//改變基礎攻速(百分比) EX. 0.9 基礎攻速從1.8變為0.9
	BaseAttackSpeedFixed,
	//移動速度加成(唯一) EX. 80 多個裝備也是固定加80跑速
	MoveSpeedUnique,
	//固定移動速度 EX. 700 固定700跑速
	MoveSpeedFixed,
	//該Buff物理爆擊機率 EX. 0.25 25%的機率爆擊
	PhysicalCriticalChance,
	//該Buff物理爆擊倍率 EX. 2.25 2.25爆擊傷害
	PhysicalCriticalPercentage,
	//該Buff魔法爆擊機率 EX. 0.25 25%的機率爆擊
	MagicalCriticalChance,
	//該Buff魔法爆擊倍率 EX. 2.25 2.25爆擊傷害
	MagicalCriticalPercentage,
	//該Buff真傷爆擊機率 EX. 0.25 25%的機率爆擊
	PureCriticalChance,
	//該Buff真傷爆擊倍率 EX. 2.25 2.25爆擊傷害
	PureCriticalPercentage,
	//格檔物理機率 EX. 0.25 25%的機率格檔物理傷害
	BlockingPhysicalChance,
	//格檔魔法機率 EX. 0.25 25%的機率格檔魔法傷害
	BlockingMagicalChance,
	//格檔真傷機率 EX. 0.25 25%的機率格檔真傷傷害
	BlockingPureChance,
	//格檔固定物理傷害 EX. 500 任何物理傷害先格檔500
	BlockingPhysicalConstant,
	//格檔固定魔法傷害 EX. 200 任何魔法傷害先格檔200
	BlockingMagicalConstant,
	//格檔固定真實傷害 EX. 50  任何真實傷害先格檔50
	BlockingPureConstant,
	//對第N個隊伍隱形無效
	UnInvisibleTeam,
	//對敵人的靈氣/光環半徑
	AuraRadiusEnemy,
	//對自己人的靈氣/光環半徑
	AuraRadiusFriends,
	// 結束列舉
	EndBuffProperty,
};
#define HEROU EHeroBuffUnique

// 特效跟隨的位置
UENUM(BlueprintType)
enum class EBuffPosition : uint8
{
	//頭上
	Head,
	//腳上
	Foot,
	//角色中心點
	Root
};


UENUM(BlueprintType)
enum class EKeyBehavior : uint8
{
	// 技能1
	KEY_SKILL_1,
	// 技能2
	KEY_SKILL_2,
	// 技能3
	KEY_SKILL_3,
	// 技能4
	KEY_SKILL_4,
	// 技能5
	KEY_SKILL_5,
	// 技能6
	KEY_SKILL_6,
	// 技能7
	KEY_SKILL_7,
	// 技能8
	KEY_SKILL_8,
	// 技能9
	KEY_SKILL_9,
	// 技能10
	KEY_SKILL_10,
	// 攻擊
	KEY_ATTACK,
	// 移動
	KEY_MOVE,
	// 停止所有動作
	KEY_STOP,
	// 選擇自己的英雄
	KEY_SELECT_OWNED_HERO,
};

UENUM(BlueprintType)
enum class EHeroActionStatus : uint8
{
	//站著休息
	Default,
	//A點地板 移動中遇到敵人停下來攻擊
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
	//直接施放技能
	SpellNow,
	//指定地點的技能
	SpellToPosition,
	//指向技
	SpellToDirection,
	//指定技
	SpellToActor,
	//開關技能
	ToggleSkill,
	//撿裝
	MoveToPickup,
	//丟裝
	MoveToThrowEqu,
	//丟裝給人
	ThrowEquToActor,
	// 破壞場景物件
	AttackSceneObject,
};


UENUM(BlueprintType)
enum class EHeroBodyStatus : uint8
{
	//站著發呆
	Standing,
	//移動中
	Moving,
	//暈眩中
	Stunning,
	//攻擊等待
	AttackWating,
	//攻擊前搖
	AttackBegining,
	//攻擊後搖
	AttackEnding,
	//施法前等待
	SpellWating,
	//施法前搖
	SpellBegining,
	//施法後搖
	SpellEnding,
	//持續對某人施法中
	SpellChannellingActor,
	//持續施法中
	SpellChannelling,
};


UENUM(BlueprintType)
enum class ETeamFlag : uint8
{
	// 織田軍
	Team1 = 1,
	// 聯合軍
	Team2 = 2,
	// 敵隊
	TeamEnemy,
	// 友軍
	TeamFriends,
	// 全部
	TeamAll,
};

UENUM(BlueprintType)
enum class EMOBAType : uint8
{
	// 英雄
	HeroUnit,
	// 小兵
	BasicUnit,
	// 建築物
	BuildingUnit,
};
