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
{
}

Actor::Actor(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Pos(InPos.X, InPos.Y)
	, Name(InName)
	, Health(InHealth)
	, HealthMax(InHealthMax)
	, AttackPowerMin(InAttackPowerMin)
	, AttackPowerMax(InAttackPowerMax)
{
}

Actor::~Actor()
{
}

void Actor::ApplyDamage(Actor& InActor)
{
}

void Actor::TakeDamage(int Damage)
{
}
