#include "Utils.h"
#include "Enemy.h"

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