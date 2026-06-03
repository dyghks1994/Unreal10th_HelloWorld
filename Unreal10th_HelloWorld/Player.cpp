#include "Utils.h"
#include "Player.h"

Player::Player()
	: Actor()
	, Money(0)
{
}

Player::Player(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax)
	: Actor(InPos, InName, InHealth, InHealthMax, InAttackPowerMin, InAttackPowerMax)
	, Money(0)
{
}

Player::~Player()
{
}

int Player::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	return InActor.TakeDamage(Damage);
}

int Player::TakeDamage(int Damage)
{
	int ResultDmage = Damage;

	Health -= ResultDmage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDmage;
}
