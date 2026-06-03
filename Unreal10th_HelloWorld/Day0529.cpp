#include "Player.h"
#include "Day0529.h"

void Day0529()
{
	/*
	MazeEnemy E1("오크", 1);
	MazeEnemy E2("슬라임", 2);

	PrintEnemyInfo(E1);
	PrintEnemyInfo(E2);

	MazeEnemy E3 = FusionEnemy(E1, E2);
	PrintEnemyInfo(E3);

	MazeEnemy E4 = E1 + E2;
	PrintEnemyInfo(E4);

	// 간단 실습
	// 1. MazeEnemy에 -연산자 오버로딩하기
	//		E5 = E1 - E2;
	// 2. MazeEnemy에 *연산자 오버로딩하기(*의 오른쪽 값은 float)
	//		E6 = E5 * 2;
	// 3. MazeEnemy에 *=연산자 오버로딩하기(*의 오른쪽 값은 float)
	//		E6 *= 3;

	// 간단 실습 2
	// 위치 좌표를 표현하기 위한 구조체 Position 만들기
	// 멤버 변수로 int X, int Y를 가진다.
	// 두 멤버 변수는 기본값이 0이어야 한다.
	// 두 개의 정수 값을 받아서 멤버 변수에 할당하는 생성자를 만든다.(Position(int InX, int InY))
	// '+' 연산자를 오버로딩하여 두 Position 객체를 더했을 때, 각각의 멤버끼리 더한 결과를 갖는 새로운 Position 객체가 생성되도록 한다.
	// '-' 연산자도 오버로딩하여 두 Position 객체를 뺐을 때, 각각의 멤버끼리 뺀 결과를 갖는 새로운 Position 객체가 생성되도록 한다.
	Position P1;
	Position P2(10, 15);
	Position P3(3, 7);

	printf("P1.X = %2d, P1.Y = %2d \n", P1.X, P1.Y);
	printf("P2.X = %2d, P2.Y = %2d \n", P2.X, P2.Y);
	printf("P3.X = %2d, P3.Y = %2d \n\n", P3.X, P3.Y);

	printf("P2 + P3 = X = %2d, Y = %2d \n", (P2 + P3).X, (P2 + P3).Y);
	printf("P2 - P3 = X = %2d, Y = %2d \n\n", (P2 - P3).X, (P2 - P3).Y);
	//*/
}

/*
void PrintEnemyInfo(MazeEnemy& InEnemy)
{
	printf("----------------------------\n");
	printf("이름   : %s\n", InEnemy.Name.c_str());
	printf("체력   : %d\n", InEnemy.Health);
	printf("공격력 : %d - %d\n", InEnemy.AttackPowerMin, InEnemy.AttackPowerMax);
	printf("보상   : %d\n", InEnemy.Reward);
	printf("----------------------------\n");
}

MazeEnemy FusionEnemy(MazeEnemy& InEnemy1, MazeEnemy& InEnemy2)
{
	MazeEnemy Result;
	Result.Name = InEnemy1.Name + InEnemy2.Name;
	Result.AttackPowerMin = (InEnemy1.AttackPowerMin + InEnemy2.AttackPowerMin) / 2;
	Result.AttackPowerMax = InEnemy1.AttackPowerMax + InEnemy2.AttackPowerMax;
	Result.Reward = InEnemy1.Reward + InEnemy2.Reward;

	return Result;
}

//*/
void Maze0529()
{
}