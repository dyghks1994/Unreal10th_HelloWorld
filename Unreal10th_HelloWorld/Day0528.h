#pragma once

void Day0528();
void Day0528_String();
void Day0528_FileIO();
void Day0528_Structure();

void FindCharacter(const std::string& str, char c);

struct Enemy	// 적은
{
	std::string Name;	// 이름을 가지고
	float Health;		// 체력을 가지고
	float AttackPower;	// 공격력을 가지고
	int Reward;			// 보상을 가진다.
};

struct EnemyOrc	
{
	std::string Name = "Orc";	// 멤버 직접 초기화
	float Health = 150.0f;		// 
	float AttackPower = 10.0f;	// 
	int Reward = 50;			// 

	//EnemyOrc()	// 기본 생성자(생성자가 하나도 없으면 자동으로 생긴다.)
	//{
	//
	//}	
	EnemyOrc() = default;
	
	EnemyOrc(std::string DefaultName)
	{
		Name = DefaultName;
	}

	EnemyOrc(std::string _Name, float _Health, float _AttackPower, int _Reward)
		: Name(_Name), Health(_Health), AttackPower(_AttackPower), Reward(_Reward)
	{
		Name = _Name;
	}

	EnemyOrc(float Modifer = 1.0f)
	{
		// 체력은 모디파이어의 10바
		Health *= Modifer * 10.0f;

		// 공격력은 모디파이어의 5배
		AttackPower *= Modifer * 5.0f;

		// 리워드는 모디파이어의 3배
		Reward *= (int)(Modifer * 3.0f);

	}

};

struct MazePlayer
{
	int PosX = 1;
	int PosY = 1;
	const int MaxHealthPoint = 100;
	int HealthPoint = MaxHealthPoint;
	const int MinAttackPower = 5;
	const int MaxAttackPower = 15;
	int AttackPower = 15;
	int Money = 0;
};

struct MazeEnemyHW
{
	const int MaxHealthPoint = 30;
	int HealthPoint = MaxHealthPoint;
	const int MinAttackPower = 5;
	const int MaxAttackPower = 15;
	int AttackPower = MaxAttackPower;
	const int MaxReward = 30;
	int Reward = 30;

	MazeEnemyHW()
	{
		// 1 ~ Max 사이 랜덤 값 설정
		HealthPoint = (rand() % MaxHealthPoint) + 1;
		Reward = (rand() % MaxReward) + 1;

		// 공격력은 공격시에 5 ~ 15 사이 값 설정

	}
};

void TestStruct(Enemy Target);		// 값에 의한 호출(Call by Value)
void PrintEnemyData(Enemy& Target);	// 참조에 의한 호출(Call by reference)
void PrintEnemyData(Enemy* Target);	// 주소에 의한 호출(Call by Address)
void PrintEnemyData(EnemyOrc* Target);

void Maze0528();
void InitializeMaze0528(int** Maze);
void PrintMaze0528(int** Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY);
int Battle0528(MazePlayer& Player, MazeEnemyHW& Enemy);
void HealHp0528(int* PlayerHp, const int MaxHp);