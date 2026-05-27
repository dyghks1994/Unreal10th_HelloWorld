#include <iostream>
#include <stdlib.h>
#include "Day0526.h"

using namespace std;

void Day0526()
{
	// 포인터
	// - 메모리 '주소'를 저장하는 변수
	// - 각 데이터 타입에 *(아스트리크)만 붙이면 포인터 타입이 된다.

	// IntegerAddress 는 int 타입 변수의 주소를 저장하는 변수. 기본값으로 nullptr을 저장한다.
	int* IntegerAddress = nullptr;	// 인티저 포인터 IntegerAddress 선언하고 nullptr로 초기화히기

	float* pFloat = nullptr;		// 플롯 포인터 pFloat
	char* pTestString = nullptr;	// 캐릭터 포인터(문자열, string) pTestString

	// 포인터 연산자
	// - & : 주소 연산자. 변수 앞에 붙이면 그 변수의 주소를 돌려준다.
	// - * : 간접참조연산자. 포인터 변수 앞에 붙이면 그 포인터 변수가 가리키는 주소에 있는 실제 값을 돌려준다.
	int Data = 10;
	IntegerAddress = &Data;		// Data라는 변수의 주소를 IntegerAddress에 저장해라.
	int Temp1 = *IntegerAddress;	// IntegerAddress가 가리키는 주소에 있는 실제값(Data의 값)을 Temp에 대입해라.
	int Temp2 = (*IntegerAddress) * 2;

	// 상수와 포인터
	const int* ConstPointer = &Data;	// ConstPointer Data의 주소를 가리키는데 그 값을 변경하지 않겠다.
	ConstPointer = &Temp1;
	//(*ConstPointer) = 20;	// 값을 변경하는 것은 문법 에러
	int* const ConstPointer2 = &Data;	// ConstPointer는 Data의 주소를 가리키는데 주소를 변경하지 않겠다.
	//ConstPointer2 = &Temp2;	// 주소를 변경하는 것은 문법에러

	// +연산자와 -연산자
	int* pData = &Data;		// Data의 주소가 0x10이라고 가정하면
	pData = pData + 1;		// +1한 결과는 0x14, int의 크기가 4byte라서.
	pData++;				// 0x18
	pData--;				// 0x14

	// const는 자기 왼쪽에 있는 것(왼쪽에 아무것도 없으면 오른쪽에 있는 것)을 변경하지 않는 것
	const int a = 10;	// 일반적으로 많이 사용
	int const b = 20;	// 문법적으로는 문제 없으나 거의 사용 안함

	int Array[5] = { 1, 2, 3, 4, 5 };
	int* pArray = Array;	// Array의 첫번째 요소의 주소를 pArray에 저장해라.
	//Array[1];				// 배열의 두번째 요소에 접근
	//pArray + 1;				// 포인터를 이용해서 두번째 요소에 접근


	// range-for : 배열이나 컨테이너의 첫 요소에서 마지막 요소까지 순차적으로 처리할 떄 유용
	for (int Element : Array)
	{
		printf("%d", Element);
	}
	printf("\n");

	// pArray를 이용해서 Array의 4번째 요소 출력하기
	printf("%d\n", *(pArray + 3));
	Day0526_PointerParameter(Array, 5);
	
	printf("\n");

	
	// C++의 메모리 영역
	//	- 코드 영역
	//		프로그램의 실행 코드가 저장되는 공간
	//	- 데이터 영역
	//		- 프로그램이 시작할 떄 부터 끝날 때까지 유지되는 변수가 저장되는 공간.
	//		- 전역변수, static 변수 등
	//	- 스택 영역
	//		- 함수가 호출될 때마다 필요한 변수(지역변수)
	//		- 함수가 끝나면 자동으로 정리
	//		- 크기 제한이 있다.(윈도우에서 별다른 설정 없으면 1MB)
	//		- 빠르다.
	//	- 힙 영역
	//		- 프로그램 실행 중에 필요에 따라 직접 메모리를 할당하고 사용하는 공간
	//		- 반드시 할당을 하면 해제를 해줘야 한다.
	//		- 크기는 대략 RAM 크기와 같다.
	//		- 느리다.(상대적으로)

	// 동적 할당(Dynamic Allocation)
	//	- 프로그램실행 도중(Runtime)에 메모리를 사용하기 위해 확보하는 행위
	//	- 단점
	//		- 처리 속도가 느리다(= 자주하면 안된다.)
	//		- 메모리 단편화 문제가 발생할수 있다.
	//	- C++ 방식
	//		- 장점 : 초기화 있음. 타입안정성 있음. 생성자/소멸자 호출됨.
	//		- new, delete

	int* Alloc = new int(5);	// int 크기로 동적할당을 받고 초기값으로 5를 설정한 다음 그 주소를 Alloc에 저장해라.

	*Alloc = 20;

	delete Alloc;		// 다썼으면 반드시 해제해야 한다. 메모리를 할당하고 해제하지 않으면 메모리 릭이 발생한다.
	Alloc = nullptr;	// 댕글링 포인터 방지를 위해 꼭 하는 것이 좋음


	Alloc = new int[10];	// int 10개짜리 배열을 만들어라.
	delete[] Alloc;			// 배열을 할당받은 것을 해제할 때는 delete[]를 써야 한다.
	Alloc = nullptr;
	
	int** Array2Dim = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		Array2Dim[i] = new int[10];	// 가로 10
	}

	for (int i = 0; i < 5; i++)
	{
		delete[] Array2Dim[i];
	}
	delete[] Array2Dim;
	
	//int i = 0;


	
	int PraticeArray[] = { 5, 2, 74, 4, 15, 7, 3, 1, 52 };
	int PracticeSize = sizeof(PraticeArray) / sizeof(PraticeArray[0]);
	Day0526_PrintArray(PraticeArray, PracticeSize);

	// 간단 실습
	// 1. 두 변수의 값을 변경하는 함수 만들기
	//	int a, b; Swap(a, b); 하면 a와 b의 값이 서로 바뀐다.
	int Num1 = 10;
	int Num2 = 20;
	printf("실습1. Swap 전 Num1 = %d, Num2 = %d\n", Num1, Num2);
	Day0526_Practice1(&Num1, &Num2);
	printf("실습1. Swap 후 Num1 = %d, Num2 = %d\n\n", Num1, Num2);


	// 2. 포인터를 이용해서 배열의 최대값 찾는 함수 만들기
	//	- 인덱스 사용 금지. (Array[i] 이런식의 사용 금지)
	int NumArray[5] = { 17, 33, 6, 123, 45 };
	printf("실습2. 포인터를 이용해서 배열의 최대값 찾는 함수 만들기 \n");
	printf("NumArray = { %d, %d, %d, %d, %d }\n", NumArray[0], NumArray[1], NumArray[2], NumArray[3], NumArray[4]);
	printf("Max = %d\n\n", Day0526_Practice2(NumArray, 5));


	// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
	//	- 인덱스 사용 금지.
	printf("실습3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기\n");

	int Array2[5] = { 11, 22, 33, 44, 55 };
	printf("기존   Array2 = { %d, %d, %d, %d, %d }\n", Array2[0], Array2[1], Array2[2], Array2[3], Array2[4]);
	Day0526_Practice3(Array2, 5);
	printf("리버스 Array2 = { %d, %d, %d, %d, %d }\n", Array2[0], Array2[1], Array2[2], Array2[3], Array2[4]);
	//*/

	// 1. 1차원 배열을 할당받아서 2차원 배열처럼 사용하기
	//		주말과제의 Maze를 int* Maze; 로 변경해보기
	// 2. 미로 탈출 게임에 랜덤 인카운터 종류 늘려보기
	MazeVer2();
	
}

// 배열 파라메터로 넘길 때는 포인터를 주로 활용한다.
void Day0526_PointerParameter(int* Data, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%d", *(Data + i));
	}
}

void Day0526_Practice1(int* a, int* b)
{
	int Temp = *a;
	*a = *b;
	*b = Temp;
}

int Day0526_Practice2(int* Array, int Size)
{
	int Max = INT32_MIN;
	for (int i = 0; i < Size; i++)
	{
		if (*(Array + i) > Max)
		{
			Max = *(Array + i);
		}
	}

	return Max;
}

void Day0526_Practice3(int* Array, int Size)
{
	// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
	//	- 인덱스 사용 금지.

	int Temp = 0;
	for (int i = 0; i < Size / 2; i++)
	{
		Temp = *(Array + i);
		*(Array + i) = *(Array + Size - 1 - i);
		*(Array + Size - 1 - i) = Temp;
	}
		
	/*
	int* Left = Array;
	int* Right = Array + (Size - 1);

	while (Left < Right)	// 왼쪽과 오른쪽이 같아지거나 교차하기 전까지 반복
	{
		Day0526_Practice1(Left, Right);

		Left++;
		Right--;
	}
	//*/
}

void Day0526_PrintArray(int* Array, int Size)
{
	printf("Array : [ ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Array + i));
	}
	printf("] \n");

}


void MazeVer2()
{
	// 4. 1차원 배열을 할당받아서 2차원 배열처럼 사용하기
	// 주말과제의 Maze를 int* Maze;로 변경해보기
	// 미로 크기
	const int MazeRows = 10;
	const int MazeCols = 20;

	// 미로 배열

	//int Maze[MazeRows][MazeCols] =
	//{
	//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
	//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
	//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
	//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
	//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
	//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	//};
	//*/

	/*
	int Maze_0[MazeCols] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int Maze_1[MazeCols] = { 1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1 };
	int Maze_2[MazeCols] = { 1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1 };
	int Maze_3[MazeCols] = { 1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1 };
	int Maze_4[MazeCols] = { 1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1 };
	int Maze_5[MazeCols] = { 1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1 };
	int Maze_6[MazeCols] = { 1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1 };
	int Maze_7[MazeCols] = { 1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1 };
	int Maze_8[MazeCols] = { 1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1 };
	int Maze_9[MazeCols] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	// int* Maze 변수
	int* Maze2[MazeRows];
	Maze2[0] = Maze_0;
	Maze2[1] = Maze_1;
	Maze2[2] = Maze_2;
	Maze2[3] = Maze_3;
	Maze2[4] = Maze_4;
	Maze2[5] = Maze_5;
	Maze2[6] = Maze_6;
	Maze2[7] = Maze_7;
	Maze2[8] = Maze_8;
	Maze2[9] = Maze_9;
	//*/

	int* MazePointer[MazeRows];
	MazePointer[0] = new int[MazeCols] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	MazePointer[1] = new int[MazeCols] { 1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 };
	MazePointer[2] = new int[MazeCols] { 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 };
	MazePointer[3] = new int[MazeCols] { 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 };
	MazePointer[4] = new int[MazeCols] { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 };
	MazePointer[5] = new int[MazeCols] { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 };
	MazePointer[6] = new int[MazeCols] { 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 };
	MazePointer[7] = new int[MazeCols] { 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3, 1 };
	MazePointer[8] = new int[MazeCols] { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 };
	MazePointer[9] = new int[MazeCols] { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	/*
	
	//*/
	

	// 플레이어 위치 변수 시작위치로 초기화
	int PlayerPosY = 1;
	int PlayerPosX = 1;

	// 골인지점 위치 초기화
	int GoalPosY = 7;
	int GoalPosX = 18;

	//  골 도착 여부
	bool bGoal = false;

	char PlayerInput = 0;

	const int PlayerHpMax = 100;
	int PlayerHp = PlayerHpMax;		// 플레이어 Hp 초기화
	int EnemyHp = 50;				// 적 Hp 초기화

	printf("== = 미로 탈출 게임 Ver2 == =\n");
	//PrintMaze(&Maze[0][0], MazeRows, MazeCols);

	do
	{
		//system("cls");
		//getchar();

		PrintMaze2(MazePointer, MazeRows, MazeCols, PlayerPosX, PlayerPosY);
		printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽) :\n");
		printf("w(↑) s(↓) a(←) d(→)\n");

		cin >> PlayerInput;
		cin.clear();
		cin.ignore(10000, '\n');

		// 이동하려는 위치 변수 현재 위치로 초기화
		int CheckPosY = PlayerPosY;
		int CheckPosX = PlayerPosX;

		/// 위로 이동하려고 할 때
		if (PlayerInput == 'w' || PlayerInput == 'W')
		{
			CheckPosY -= 1;
		}

		/// 왼쪽으로 이동하려고 할 때
		else if (PlayerInput == 'a' || PlayerInput == 'A')
		{
			CheckPosX -= 1;
		}

		/// 아래쪽으로 이동하려고 할 때
		else if (PlayerInput == 's' || PlayerInput == 'S')
		{
			CheckPosY += 1;
		}

		/// 오른쪽으로 이동하려고 할 때
		else if (PlayerInput == 'd' || PlayerInput == 'D')
		{
			CheckPosX += 1;
		}

		// 이동하려는 위치가 벽이 아니라면
		if (MazePointer[CheckPosY][CheckPosX] != 1)
		{
			// 플레이어 위치 이동
			PlayerPosY = CheckPosY;
			PlayerPosX = CheckPosX;

			// 이동 후 미로 재출력
			//PrintMaze2(Maze2, MazeRows, MazeCols, PlayerPosX, PlayerPosY);

			// 골인 지점 도착시 종료 판별 변수 설정
			if (PlayerPosY == GoalPosY && PlayerPosX == GoalPosX)
			{
				printf("미로 탈출 성공!!\n");
				bGoal = true;
			}

			// 랜덤 확률로 이벤트 발생
			else
			{
				// 랜덤 숫자 생성
				int RandNum = rand() % 10;

				/// 20% 확률로 전투 진입
				// 랜덤으로 0~9 숫자를 선택하고
				// 값이 0 or 1 인 경우
				if (RandNum < 2)
				{
					// 적 Hp 리셋
					EnemyHp = 50;

					// 전투 진행 후 결과 저장
					int Result = Battle(&PlayerHp, &EnemyHp);

					// 플레이어 패배
					if (Result == -1)
					{
						printf("미로를 탈출하지 못했습니다..\n\n");
					}
				}

				/// 20% 확률로 Hp 회복
				// 5, 6인 경우
				if (RandNum >= 5 && RandNum <= 6)
				{
					HealHp(&PlayerHp, PlayerHpMax);
				}
			}
		}

		else
		{
			printf("이동 불가!\n\n");
		}

	} while (bGoal == false && PlayerHp > 0);

	printf("===================================================\n\n");

	// 동적 할당 포인터 배열 해제
	for (int* Element : MazePointer)
	{
		delete Element;
		Element = nullptr;
	}

}

void PrintMaze2(int** Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY)
{
	printf("\n");

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			// 플레이어의 위치를 출력하려고 할 때
			if (i == PlayerPosY && j == PlayerPosX)
			{
				// P 출력 후 다음 위치로 넘김
				printf("P");
				continue;
			}

			// 현재 인덱스의 값 추출
			//int Val = (Maze[i * Cols + j]);	// 2차원 배열 시절 코드

			int Val = (Maze[i][j]);				/// int*로 변경후 코드
			//printf("%d", Val);

			switch (Val)
			{
			case 0: { printf(".");	break; }	// 길
			case 1: { printf("#");	break; }	// 벽
			case 2: { printf("S");	break; }	// 시작점
			case 3: { printf("E");  break; }	// 출구
			}
		}
		printf("\n");
	}
	//*/
}

// 적과의 전투
// 플레이어와 적이 서로 번갈아가면서 공격한다.
// 
int Battle(int* PlayerHp, int* EnemyHp)
{
	int Result = 0;			// 전투 상태 체크 1(플레이어 승리), 0(전투중), -1(적 승리)
	int TurnCount = 1;	// 턴 카운트

	printf("========= 전투 시작 =========\n");

	// 전투중 턴 진행
	while (Result == 0)
	{
		printf("-> 턴 (%d)\n", TurnCount);

		// 플레이어 데미지 계산
		int PlayerDamage = (rand() % 11) + 5;	// 5 ~ 15

		// 10% 확률로 크리티컬 적용
		int Temp = rand() % 10;
		if (Temp < 1)
		{
			PlayerDamage *= 2;	// 데미지 2배 적용
		}

		printf("플레이어의 공격~! 데미지 : %d\n", PlayerDamage);
		*EnemyHp -= PlayerDamage;
		if (*EnemyHp < 0)
		{
			*EnemyHp = 0;
		}
		printf("현재 적 체력 = [%d]\n", *EnemyHp);

		// 적이 죽으면
		if (*EnemyHp <= 0)
		{
			Result = 1;	// 플레이어 승리 처리
			printf("\n적을 쓰러뜨렸다!!!\n\n");
			printf("=============================\n");

			break;
		}

		// 적 데미지 계산
		int EnemyDamage = (rand() % 11) + 5;	// 5 ~ 15
		printf("적의 공격~! 데미지 : %d\n", EnemyDamage);
		*PlayerHp -= EnemyDamage;
		if (*PlayerHp < 0)
		{
			*PlayerHp = 0;
		}
		printf("현재 플레이어 체력 = [%d]\n", *PlayerHp);


		// 플레이어가 죽으면
		if (*PlayerHp <= 0)
		{
			Result = -1;	// 적 승리 처리
			printf("\n플레이어 Hp가 0이 되어 패배...\n\n");
			printf("=============================\n");

			break;
		}

		printf("\n");

		// 턴 증가
		TurnCount++;
	}

	return Result;
}

void HealHp(int* PlayerHp, const int MaxHp)
{
	// HP 회복
	(*PlayerHp) += 15;

	// 최대 HP보다 넘치면 최대 HP로 보정
	if (*PlayerHp > MaxHp)
	{
		*PlayerHp = MaxHp;
	}

	printf("[ Hp가 회복 됩니다. 남은 Hp = %d ]\n", *PlayerHp);
}
