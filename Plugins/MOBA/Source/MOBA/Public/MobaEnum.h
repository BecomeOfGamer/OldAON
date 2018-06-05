#pragma once


UENUM(BlueprintType)
enum class EDamageType : uint8
{
	//���z�ˮ`
	DAMAGE_PHYSICAL,
	//�]�k�ˮ`
	DAMAGE_MAGICAL,
	//�u��ˮ`
	DAMAGE_PURE
};

UENUM(BlueprintType)
enum class EHeroBuffState : uint8
{
	//�w��
	Stunning,
	//�T����
	BanMove,
	//�T����
	BanAttack,
	//�T�ޯ�
	BanSkill,
	//�T�D��
	BanEquipment,
	//����Q�k�N���w
	BanBeSkillSight,
	//����Q������w
	BanBeAttackSight,
	//�]�k�K��
	MagicalImmune,
	//���z�K��
	PhysicalImmune,
	//�u�˧K��
	PureImmune,
	//�L��
	Invulnerable,
	//�ίv�A�Q�����|����
	Sleeping,
	//�����ഫ���]�k�ˮ`
	AttackUseMagic,
	//�����ഫ���u��ˮ`
	AttackUsePure,
	//����
	Invisible,
	//�V��
	Blending,
	//�i����
	Rebirth,
	//�����C�|
	EndBuffKind,
};
#define HEROS EHeroBuffState

// BaseAttack�O��l�����O
// ���z��X = (((BaseAttack+AttackBounsConstantWhite)*(AttackBounsPercentage+1)+AttackBounsConstantGreen)*PhysicalDamageOutputPercentage)
// BaseManaRegen�O��l�^�]�t��
// �^�]�t�� = (BaseManaRegen*ManaRegenPercentage+ManaRegenConstant)*HealthRegenRatio
// BaseAttackSpeed �O��l��t�ABaseAttackSpeedFixed �O�ܨ��t����¦��t
// �����t�� = (BaseAttackSpeed*AttackSpeedConstant)*AttackSpeedRatio
// �����t�� = (BaseAttackSpeedFixed*AttackSpeedConstant)*AttackSpeedRatio
// 
// �i�|�[���ƭ�
UENUM(BlueprintType)
enum class EHeroBuffProperty : uint8
{
	//���z�ˮ`��X�[��(�ʤ���) EX. 0.1 �[��10%
	PhysicalDamageOutputPercentage,
	//�]�k�ˮ`��X�[��(�ʤ���) EX. 0.1 �[��10%
	MagicalDamageOutputPercentage,
	//�u�˶ˮ`��X�[��(�ʤ���) EX. 0.1 �[��10%
	PureDamageOutputPercentage,
	//���쪫�z�ˮ`�[��(�ʤ���) EX. -0.1 ���10%
	PhysicalDamageInputPercentage,
	//�����]�k�ˮ`�[��(�ʤ���) EX. -0.1 ���10%
	MagicalDamageInputPercentage,
	//����u��ˮ`�[��(�ʤ���) EX. -0.1 ���10%
	PureDamageInputPercentage,
	//���ʳt�ץ[��(�ʤ���) EX. 2 2���]�t
	MoveSpeedRatio,
	//���ʳt�ץ[��(�T�w��) EX. 100 �W�[100�]�t
	MoveSpeedConstant,
	//��t�[��(�ʤ���) EX. 2 2����t��}��¦��t����
	AttackSpeedRatio,
	//��t�[��(�T�w��) EX. 0.5 �W�[50%��t �̰�500% �[��¦��100�̰�600
	AttackSpeedConstant,
	//�l�����z�ˮ`(�ʤ���) EX. 0.1 �l�����쪺10%���z�ˮ`
	AbsorbPhysicalDamagePercentage,
	//�l���]�k�ˮ`(�ʤ���) EX. 0.1 �l�����쪺10%�]�k�ˮ`
	AbsorbMagicalDamagePercentage,
	//�l���u��ˮ`(�ʤ���) EX. 0.1 �l�����쪺10%�u��ˮ`
	AbsorbPureDamagePercentage,
	//�v¡�[��(�ʤ���) EX. 0.2 �v���ͩR����10%
	HealPercentage,
	//�^�](�T�w��) EX. 3 �C��^�]�W�[3
	ManaRegenConstant,
	//�^�](�ʤ���) EX. 0.03 �C��^�]�W�[�`�]�O��3%
	ManaRegenPercentage,
	//�^�](��ҥ[��) EX. 2 �^�_�]�O+200%=300% �p�G��e�^�]20�N�ܦ�60
	ManaRegenRatio,
	//�^��(�T�w��) EX. 10 �C��^��W�[10
	HealthRegenConstant,
	//�^��(�ʤ���) EX. 0.01 �C��^��W�[�`�ͩR��1%
	HealthRegenPercentage,
	//�^��(��ҥ[��) EX. 2 �^�_��q+200%=300% �p�G��e�^��50�N�ܦ�150
	HealthRegenRatio,
	//�����[��(�T�w��) EX. 30 �����զr+30 �i�H�Q�䥦�����[���v�T
	AttackBounsConstantWhite,
	//�����[��(�T�w��) EX. 30 ������r+30 ���|�Q�䥦�����[���v�T
	AttackBounsConstantGreen,
	//�����[��(�ʤ���) EX. 2 �����զr��2�[���r ���Q�䥦�����[���v�T
	AttackBounsPercentage,
	//���m�[��(�T�w��) EX. 5 ���m�զr+5
	ArmorBounsConstant,
	//���m�[��(�ʤ���) EX. 1 ��e���m���W1�[���r
	ArmorBounsPercentage,
	//�ͩR�l�� EX. 0.2 �l���y���ˮ`��20%
	StealHealth,
	//�������~���v EX. 0.15 15%�����vmiss
	AttackMiss,
	//���ɧ������v EX. 0.25 25%�����v���ɪ��z�ˮ`
	BlockingPhysical,
	//�����]�k���v EX. 0.25 25%�����v�����]�k�ˮ`
	BlockingMagical,
	//���ɯu�˾��v EX. 0.25 25%�����v���ɯu�˶ˮ`
	BlockingPure,
	//���ɩT�w���z�ˮ` EX. 500 ���󪫲z�ˮ`������500
	BlockingPhysicalConstant,
	//���ɩT�w�]�k�ˮ` EX. 200 �����]�k�ˮ`������200
	BlockingMagicalConstant,
	//���ɩT�w�u��ˮ` EX. 50  ����u��ˮ`������50
	BlockingPureConstant,
	//��q�W���W�[ EX. 300 �W�[300�̤j�ͩR��
	HealthBouns,
	//�]�q�W���W�[ EX. 250 �W�[250�̤j�]�O��
	ManaBouns,
	//�{�׾��v EX 0.1 ��10%���{�׾��v
	Dodge,
	//�O�q EX. 1.5 �N�[1.5���O�q
	Strength,
	//�ӱ� EX. 2.5 �N�[2.5���ӱ�
	Agile,
	//���z EX. 3.5 �N�[3.5�����z
	Intelligence,
	// �����C�|
	EndBuffProperty
};
#define HEROP EHeroBuffProperty

// ���i�|�[���ƭ�
UENUM(BlueprintType)
enum class EHeroBuffUnique : uint8
{
	//��̧C�� EX. 100 ��q���|�֩�100
	MinHealth,
	//��̰��� EX. 2000 ��q���|����2000
	MaxHealth,
	//��̧C�] EX. 200 �]�O���|�C��200
	MinMana,
	//��̰��] EX. 400 �]�O���|����400
	MaxMana,
	//���ܰ�¦��t(�ʤ���) EX. 0.9 ��¦��t�q1.8�ܬ�0.9
	BaseAttackSpeedFixed,
	//���ʳt�ץ[��(�ߤ@) EX. 80 �h�Ӹ˳Ƥ]�O�T�w�[80�]�t
	MoveSpeedUnique,
	//�T�w���ʳt�� EX. 700 �T�w700�]�t
	MoveSpeedFixed,
	//��Buff���z�z�����v EX. 0.25 25%�����v�z��
	PhysicalCriticalChance,
	//��Buff���z�z�����v EX. 2.25 2.25�z���ˮ`
	PhysicalCriticalPercentage,
	//��Buff�]�k�z�����v EX. 0.25 25%�����v�z��
	MagicalCriticalChance,
	//��Buff�]�k�z�����v EX. 2.25 2.25�z���ˮ`
	MagicalCriticalPercentage,
	//��Buff�u���z�����v EX. 0.25 25%�����v�z��
	PureCriticalChance,
	//��Buff�u���z�����v EX. 2.25 2.25�z���ˮ`
	PureCriticalPercentage,
	//���ɪ��z���v EX. 0.25 25%�����v���ɪ��z�ˮ`
	BlockingPhysicalChance,
	//�����]�k���v EX. 0.25 25%�����v�����]�k�ˮ`
	BlockingMagicalChance,
	//���ɯu�˾��v EX. 0.25 25%�����v���ɯu�˶ˮ`
	BlockingPureChance,
	//���ɩT�w���z�ˮ` EX. 500 ���󪫲z�ˮ`������500
	BlockingPhysicalConstant,
	//���ɩT�w�]�k�ˮ` EX. 200 �����]�k�ˮ`������200
	BlockingMagicalConstant,
	//���ɩT�w�u��ˮ` EX. 50  ����u��ˮ`������50
	BlockingPureConstant,
	//���N�Ӷ������εL��
	UnInvisibleTeam,
	//��ĤH���F��/�����b�|
	AuraRadiusEnemy,
	//��ۤv�H���F��/�����b�|
	AuraRadiusFriends,
	// �����C�|
	EndBuffProperty,
};
#define HEROU EHeroBuffUnique

// �S�ĸ��H����m
UENUM(BlueprintType)
enum class EBuffPosition : uint8
{
	//�Y�W
	Head,
	//�}�W
	Foot,
	//���⤤���I
	Root
};


UENUM(BlueprintType)
enum class EKeyBehavior : uint8
{
	// �ޯ�1
	KEY_SKILL_1,
	// �ޯ�2
	KEY_SKILL_2,
	// �ޯ�3
	KEY_SKILL_3,
	// �ޯ�4
	KEY_SKILL_4,
	// �ޯ�5
	KEY_SKILL_5,
	// �ޯ�6
	KEY_SKILL_6,
	// �ޯ�7
	KEY_SKILL_7,
	// �ޯ�8
	KEY_SKILL_8,
	// �ޯ�9
	KEY_SKILL_9,
	// �ޯ�10
	KEY_SKILL_10,
	// ����
	KEY_ATTACK,
	// ����
	KEY_MOVE,
	// ����Ҧ��ʧ@
	KEY_STOP,
	// ��ܦۤv���^��
	KEY_SELECT_OWNED_HERO,
};

UENUM(BlueprintType)
enum class EHeroActionStatus : uint8
{
	//���ۥ�
	Default,
	//A�I�a�O ���ʤ��J��ĤH���U�ӧ���
	MovingAttackToPosition,
	//���ʨ���w��m
	MoveToPosition,
	//���ʨ���w���H����
	MoveToActor,
	//��ۤH��
	FollowActor,
	//�����w���H
	AttackActor,
	//�䲾����������w�ĤH
	MovingAttackActor,
	//�����I��ޯ�
	SpellNow,
	//���w�a�I���ޯ�
	SpellToPosition,
	//���V��
	SpellToDirection,
	//���w��
	SpellToActor,
	//�߸�
	MoveToPickup,
	//���
	MoveToThrowEqu,
	//��˵��H
	ThrowEquToActor,
	// �}�a��������
	AttackSceneObject,
};


UENUM(BlueprintType)
enum class EHeroBodyStatus : uint8
{
	//���۵o�b
	Standing,
	//���ʤ�
	Moving,
	//�w�t��
	Stunning,
	//��������
	AttackWating,
	//�����e�n
	AttackBegining,
	//������n
	AttackEnding,
	//�I�k�e����
	SpellWating,
	//�I�k�e�n
	SpellBegining,
	//�I�k��n
	SpellEnding,
	//�����Y�H�I�k��
	SpellChannellingActor,
	//����I�k��
	SpellChannelling,
};


UENUM(BlueprintType)
enum class ETeamFlag : uint8
{
	// ´�Эx
	Team1 = 1,
	// �p�X�x
	Team2 = 2,
	// �Ķ�
	TeamEnemy,
	// �ͭx
	TeamFriends,
	// ����
	TeamAll,
};

UENUM(BlueprintType)
enum class EMOBAType : uint8
{
	// �^��
	HeroUnit,
	// �p�L
	BasicUnit,
	// �ؿv��
	BuildingUnit,
};
