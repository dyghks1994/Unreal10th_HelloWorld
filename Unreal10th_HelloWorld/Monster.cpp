#include "Utils.h"
#include "Monster.h"

Monster::Monster()
	: Actor()
	, Reward(0)
{
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
}

int Monster::ApplyDamage(Actor& InActor)
{
	return Actor::ApplyDamage(InActor);
}

int Monster::TakeDamage(int Damage)
{
	return Actor::TakeDamage(Damage);
}

Slime::Slime()
	: Monster()
	, SlimeHealthMax(20)
{
	Initialize();
}

Slime::Slime(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Monster()
	, SlimeHealthMax(20)
{
	Initialize();
}

Slime::~Slime()
{
}

void Slime::Initialize()
{
	Name = "슬라임";

	// Hp 리셋
	HealthMax = SlimeHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 2;
	AttackPowerMax = 5;

	// 보상 설정
	Reward = GetRandomRange(1, 10);
}

int Slime::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	return InActor.TakeDamage(Damage);
}

int Slime::TakeDamage(int Damage)
{
	int ResultDmage = Damage;

	Health -= ResultDmage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDmage;
}

Orc::Orc()
	: Monster()
	, OrcHealthMax(30)
{
	Initialize();
}

Orc::Orc(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Monster()
	, OrcHealthMax(30)
{
	Initialize();
	
}

Orc::~Orc()
{
}

void Orc::Initialize()
{
	Name = "오크";

	// Hp 리셋
	HealthMax = OrcHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 5;
	AttackPowerMax = 10;

	// 보상 설정
	Reward = GetRandomRange(10, 30);
}

int Orc::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	return InActor.TakeDamage(Damage);
}

int Orc::TakeDamage(int Damage)
{
	int ResultDmage = Damage;

	Health -= ResultDmage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDmage;
}

Skeleton::Skeleton()
	: Monster()
	, SkeletonHealthMax(50)
{
	Initialize();
}

Skeleton::Skeleton(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Monster()
	, SkeletonHealthMax(50)
{
	Initialize();
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize()
{
	Name = "스켈레톤";

	// Hp 리셋
	HealthMax = SkeletonHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 8;
	AttackPowerMax = 15;

	// 보상 설정
	Reward = GetRandomRange(30, 50);
}

int Skeleton::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	return InActor.TakeDamage(Damage);
}

int Skeleton::TakeDamage(int Damage)
{
	int ResultDmage = Damage;

	Health -= ResultDmage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDmage;
}


/*
구 struct 버전 코드
MazeEnemy::MazeEnemy()
{
	Health = GetRandomRange(15, 25);
	AttackPowerMin = GetRandomRange(3, 7);
	AttackPowerMax = GetRandomRange(8, 12);
	Reward = GetRandomRange(80, 120);

}

MazeEnemy::MazeEnemy(const std::string& InName, int InLevel)
	: Name(InName)
{
	Health *= InLevel;
	AttackPowerMin *= InLevel;
	AttackPowerMax *= InLevel;
	Reward *= InLevel;
}
//*/