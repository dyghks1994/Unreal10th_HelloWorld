#include <iostream>
#include <random>
#include "Day0522.h"

using namespace std;

void Day0522_Run()
{
	// 배열
	// 같은 종류의 데이터 타입을 한번에 여러개 저장할 때 사용
	// 같은 데이터 타입을 가진 요소들이 연속적으로 저장되어 있는 데이터 구조를 가진다.
	// 장점 : 빠르게 각 요소에 접근이 가능하다(랜덤 엑세스 성능이 매우 뛰어나다)
	// 단점 : 크기가 고정이다. 삽입/삭제가 힘들다.

	/*
	int Num1, Num2, Num3;	// 이전까지 데이터 3개 저장하는 방식
	int Numbers[3];			// 배열을 이용해서 데이터 3개 저장하는 방식
	Numbers[0] = 10;		// 배열의 각 요소에 접근하는 방식
	Numbers[1] = 20;
	Numbers[2] = 50;

	Numbers[1] = Numbers[0];	// Numbers의 첫번째 요소를 두번째 요소에 대입하기

	int index = 3;
	//Numbers[index] = 100;			// 범위를 벗어나서 접근하는 것은 안됨!!

	int Array1[5] = { 1, 4, 76, 32, 6 };		// 순서대로 데이터 초기화
	int Array2[5] = { 32, 6 };				// 32, 6들어가고 나머지는 0

	int ArraySize = sizeof(Array1);
	printf("ArrySize = %d Byte\n", ArraySize);
	int ArrayCount = ArraySize / sizeof(int);
	printf("ArryCount = %d Byte\n\n", ArrayCount);

	// 2차원 배열
	int Array3[4][3];	// int 3개짜리 배열이 4개 있다.
	int Array4[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };	// int Array4[12];


	// 간단 실습
	//Day0522_Array_Example1();
	//Day0522_Array_Example2();
	//Day0522_Array_Example3();
	//
	//Day0522_Casting();
	//Day0522_Reference();

	//Day0522_Shuffle();
	*/

	// 실습 문제 실행
	//DiceNumCount();

	const int ArraySize = 10;
	int Array[ArraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//ReverseArray(Array, ArraySize);

	//MakeLottoNum();

	EscapeMaze();
}

void Day0522_Array_Example1()
{
	// 1. 배열 만들고 초기화 하고 전부 출력해보기(1차원과 2차원 모두)
	int Array5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int Array5Count = sizeof(Array5) / sizeof(int);

	printf("Array5 출력\n");
	for (int i = 0; i < Array5Count; i++)
	{
		printf("%d ", Array5[i]);
	}
	printf("\n\n");

	// constexpr 이 더 정확하다.
	const int Horizontal = 3;
	const int Vertical = 3;
	int Array6[Horizontal][Vertical] = { { 10, 20, 30 }, { 40, 50 ,60 }, { 70, 80, 90 } };
	printf("Array6 출력\n");
	for (int i = 0; i < Horizontal; i++)
	{
		for (int j = 0; j < Vertical; j++)
		{
			printf("%d ", Array6[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void Day0522_Array_Example2()
{
	// 2. 배열 내부값을 모두 더하고 평균 구해보기
	int Array5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int Array5Count = sizeof(Array5) / sizeof(int);

	printf("Array5 요소들의 총 합과 평균 \n");
	int Array5Sum = 0;
	float Array5Average = 0.0f;
	for (int i = 0; i < Array5Count; i++)
	{
		Array5Sum += Array5[i];
	}
	Array5Average = Array5Sum / Array5Count;
	printf("Sum = %d,   Average = %.2f\n\n", Array5Sum, Array5Average);
}

void Day0522_Array_Example3()
{
	// 3. 배열의 값 중 최대값과 최소값 구해보기
	const int Horizontal = 3;
	const int Vertical = 3;
	int Array6[Horizontal][Vertical] = { { 10, 20, 30 }, { 40, 50 ,60 }, { 70, 80, 90 } };

	int Array6Max = 0;
	int Array6Min = 10000;

	for (int i = 0; i < Horizontal; i++)
	{
		for (int j = 0; j < Vertical; j++)
		{
			// 현재 요소가 더 크면 Max 갱신
			if (Array6Max < Array6[i][j])
			{
				Array6Max = Array6[i][j];
			}

			// 현재 요소가 더 작으면 Min 갱신
			if (Array6Min > Array6[i][j])
			{
				Array6Min = Array6[i][j];
			}

		}
		printf("\n");
	}
	printf("Array6 Max = % d,  Min = %d\n\n", Array6Max, Array6Min);
}

void Day0522_Casting()
{
	// 같은 데이터 타입을 다른 타입으로 변경하는 것
	// C스타일
	// - 강제 변환(위험)
	int Integer = 10;
	float RealNumber = (float) Integer;		// Integer에 있는 값을 float 타입으로 임시변경한 후 RealNumber에 저장

	bool Boolean = (bool)Integer;

	int i = 0;

	// C++ 스타일
	// 1. static_cast
	//	- C스타일 cast와 매우 유사
	//	- 문법적으로 암시적 변환이 허용될 때만 캐스팅을 한다.
	RealNumber = static_cast<float>(Integer);
	
	// 2. dynamic_cast
	//	- 상속을 배워야 의미가 있음. 다운캐스팅을 할 때 사용.
	//	- 캐스팅 할 수 있으면 null이 아닌 값. 할 수 없으면 null을 반환.
	//	- RTTI(RunTime Type Information)를 관리.
	//	- 변환 속도가 매우 늦다.(일반적인 게임에서 남용하면 안된다.)
	//	- 캐스팅된 결과를 받을 변수 = dynamic_cast<캐스팅할 타입>(변수);
	
	// 3. const_cast
	//	- const나 volatile 속성을 제거하거나 추가할 떄 사용
	//	- 사용되지 않는 것이 권장(레거시 처리용)
	
	// 4. reinterpret_cast
	//	- C스타일 캐스트의 위험한 부분을 그대로 가져온 것
	//  - 원래 타입의 구조를 무시하고 새 타입으로 강제적으로 해석하게 하는 cast
	//	- 포인터 타입간 변환이나 유니온 변환 같은 경우 사용
	


}

void Day0522_Reference()
{
	// 참조
	// - 변수의 별명
	// - 재설정이 불가능하다.(선언할 때 참조하 변수를 지정해줘야 한다.)

	int Num = 10;
	int Target = Num;
	Target = 15;

	Test_Reference1(Num);
	Num = Test_Reference2(Num);

	int& NumRef = Num;
	int i;
	//int& Ref;	// 참조할 변수 지정 없이 사용하는건 안된다.
	NumRef = 100;	// 참조하고 있는 변수인 Num이 100이 된다.

	int Num1 = 0, Num2 = 0, Num3 = 0;
	Test_Reference3(Num1, Num2, Num3);

	printf("Num1=%d, Num2=%d, Num3=%d \n", Num1, Num2, Num3);
}

void Test_Reference1(int Data)
{
	Data += 10;
}

int Test_Reference2(int Data)
{
	return Data += 10;
}

void Test_Reference3(int& OutData1, int& OutData2, int& OutData3)
{
	OutData1 = 10;
	OutData2 = 20;
	OutData3 = 30;
}

void Day0522_ArrayParameter()
{
	const int Length = 5;
	int Array[Length] = { 10, 50, 30, 20, 40 };

	// 포인터(*)와 배열은 근본적으로 같다.
	Test_ArrayParameter(Array, Length);
}

void Test_ArrayParameter(int* Array, int Length)
{
	printf("Array : [");
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}

void Day0522_Shuffle()
{
	const int DataSize = 100;
	int Data[DataSize] = { 0, };

	for (int i = 0; i < DataSize; i++)
	{
		Data[i] = i;
	}
	Test_ArrayParameter(Data, DataSize);

	FisherYateShuffle(Data, DataSize);
	Test_ArrayParameter(Data, DataSize);
}

void FisherYateShuffle(int* Array, int Length)
{
	// 1. 인덱스는 배열의 마지막 요소에서 첫번째 요소로 진행
	// 2. 인덱스가 가리키는 요소와 0~인덱스까지의 요소 중 임의의 요소를 선택
	// 3. 인덱스가 가리키는 요소와 임의로 선택된 요소를 교환
	// 4. 인덱스는 1 감소

	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}

}

// 0522 실습
// 1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기(배열 활용하기)
void DiceNumCount()
{
	printf("1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기(배열 활용하기) \n");

	const int DiceSize = 6;
	int Array[DiceSize] = { 0, };

	int Num = 0;

	for (int i = 0; i < 1000000; i++)
	{
		// 1 ~ 6 생성
		Num = (rand() % DiceSize) + 1;

		// Num - 1 위치에 저장(배열 0부터 시작하므로 보정)
		Array[Num-1]++;
	}
	printf("1(%d), 2(%d), 3(%d), 4(%d), 5(%d), 6(%d)\n\n", Array[0], Array[1], Array[2], Array[3], Array[4], Array[5]);
}

// 2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기(파라메터 : int* Array, int Size)
void ReverseArray(int* Array, int Size)
{
	printf("2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기(파라메터 : int* Array, int Size)\n");

	// 중간 지점 체크할 변수
	int HalfIndex = Size / 2;

	printf("기존 배열 출력 = ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");

	// 0과 Size-1 부터 중간지점을 향해 +, - 해가면서 양사이드 스왑
	for (int i = 0, j = Size - 1; i <= HalfIndex; i++, j--)
	{
		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}

	printf("리버스 배열 출력 = ");
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n\n");
}

// 3. 로또 번호 생성기(셔플알고리즘 활용하기)
//	- 전체 숫자 범위: 1번부터 45번까지.
//	- 맞춰야 하는 숫자 개수 : 6개.
void MakeLottoNum()
{
	const int MaxNum = 45;
	int ArrayLotto[MaxNum] = { 0, };

	// 로또 배열 초기화 1~45
	for (int i = 0; i < MaxNum; i++)
	{
		ArrayLotto[i] = i + 1;
	}

	// 로또 번호 셔플
	FisherYateShuffle(ArrayLotto, MaxNum);

	// 로또 번호 출력(앞에서부터 6개)
	printf("로또 번호 = ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", ArrayLotto[i]);
	}
	printf("\n\n");
}

// 4. 미로 탈출 게임 만들기
//	2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
//	미로의 구성
//		10행 20열의 2차원 배열
//			저장 방식
//				길(0) : '. '으로 표시
//				벽(1) : '# '으로 표시
//				시작점(2) : 'S '로 표시
//				출구(3) : 'E '로 표시
//	이동 입력 처리
//		w(W) : 위, s(S) : 아래, a(A) : 왼쪽, d(D) : 오른쪽
//		대소문자 구분 없이 처리
//		플레이어가 출구에 도착하면 종료
//			플레이어는 'P'로 표시
//		게임 화면은 다음과 같은 양식을 따른다.
//			w(↑) s(↓) a(←) d(→)는 이동 가능한 방향만 출력한다.
void EscapeMaze()
{
	// 미로 크기
	const int MazeRows = 10;
	const int MazeCols = 20;

	// 미로 배열
	
	int Maze[MazeRows][MazeCols] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
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

	printf("== = 텍스트 미로 탈출 게임 == =\n");
	//PrintMaze(&Maze[0][0], MazeRows, MazeCols);
	PrintMaze(*Maze, MazeRows, MazeCols, PlayerPosX, PlayerPosY);

	do 
	{
		printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽) :\n");
		printf("w(↑) s(↓) a(←) d(→)\n");
		
		cin >> PlayerInput;

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
		if (Maze[CheckPosY][CheckPosX] != 1)
		{
			// 플레이어 위치 이동
			PlayerPosY = CheckPosY;
			PlayerPosX = CheckPosX;
			
			// 골인 지점 도착시 종료 판별 변수 설정
			if (PlayerPosY == GoalPosY && PlayerPosX == GoalPosX)
			{
				bGoal = true;
			}
		}

		else
		{
			printf("이동 불가!\n\n");
		}
		
		// 입력 후 미로 재출력
		PrintMaze(*Maze, MazeRows, MazeCols, PlayerPosX, PlayerPosY);

		
		
	} while (bGoal == false);

	printf("미로 탈출 성공!!\n");
}

void PrintMaze(int*Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY)
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
			int Val = (Maze[i * Cols + j]);
			//printf("%d", Val);

			switch (Val)
			{
				case 0: { printf(".");	break; }	// 길
				case 1:	{ printf("#");	break; }	// 벽
				case 2: { printf("S");	break; }	// 시작점
				case 3: { printf("E");  break; }	// 출구
			}
		}
		printf("\n");
	}
	//*/
}

void PrintArray(int* Array, int Length)
{
	printf("Array = ");

	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
}

float AverageArrayElements(int* Array, int Length)
{
	int Sum = 0;
	float Average = 0.0f;
	
	for (int i = 0; i < Length; i++)
	{
		Sum += Array[i];
	}
	Average = static_cast<float>(Sum) / static_cast<float>(Length);
	
	return Average;
}

int FindMaxElements(int* Array, int Length)
{
	int Max = 0;

	for (int i = 0; i < Length; i++)
	{
		if (Max < Array[i])
		{
			Max = Array[i];
		}
	}
	return Max;
}

int FindMinElements(int* Array, int Length)
{
	int Min = 10000;

	for (int i = 0; i < Length; i++)
	{
		if (Min > Array[i])
		{
			Min = Array[i];
		}
	}

	return Min;
}


