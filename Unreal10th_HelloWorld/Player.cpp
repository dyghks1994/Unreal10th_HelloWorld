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
