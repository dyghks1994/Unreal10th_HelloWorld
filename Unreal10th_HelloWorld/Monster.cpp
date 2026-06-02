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

Slime::Slime()
	: Monster()
	, SlimeHealthMax(20)
{
}

Slime::Slime(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Monster()
	, SlimeHealthMax(20)
{
}

Slime::~Slime()
{
}

void Slime::Initialize()
{
	// Hp 리셋
	HealthMax = SlimeHealthMax;
	Health = HealthMax;
}

void Slime::ApplyDamage(Actor& InActor)
{
}

void Slime::TakeDamage(int Damage)
{
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