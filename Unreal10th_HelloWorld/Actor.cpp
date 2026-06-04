#include "Actor.h"

Position::Position()
	: X(0)
	, Y(0)
{
}

Position::Position(const int InX, const int InY)
	: X(InX)
	, Y(InY)
{
}

Actor::Actor()
	: Pos(0, 0)
	, Name("")
	, Health(0)
	, HealthMax(0)
	, AttackPowerMin(0)
	, AttackPowerMax(0)
	, CriticalRate(0.0f)
	, CriticalStrikeMultiplier(1.0f)
{
}

Actor::Actor(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Pos(InPos.X, InPos.Y)
	, Name(InName)
	, Health(InHealth)
	, HealthMax(InHealthMax)
	, AttackPowerMin(InAttackPowerMin)
	, AttackPowerMax(InAttackPowerMax)
	, CriticalRate(0.0f)
	, CriticalStrikeMultiplier(1.0f)
{
}

Actor::~Actor()
{
}

int Actor::ApplyDamage(Actor& InActor)
{
	return 0;
}

int Actor::TakeDamage(int Damage)
{
	return 0;
}

