// Unreal10th_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;

int main()  // 코드의 시작점
{

	// 간단 실습
	// 1. 비트 연산을 활용해서 홀짝을 판별하기. (입력 데이터는 무조건 양수이다.)
	int Number = 0;
	printf("홀짝 판별할 수 입력 = ");
	cin >> Number;

	if (Number & 1)
	{
		printf("%d 는 홀수\n\n", Number);
	}
	else
	{
		printf("%d 는 짝수\n\n", Number);
	}


	// 2. 캐릭터가 사용하는 무기 enum 만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 만들기
	enum Weapon
	{
		Sword = 1 << 0,	// 1
		Gun = 1 << 1,	// 2
		Claw = 1 << 2,	// 4
		Wand = 1 << 3,	// 8
	};
	int MyWeapon = Claw;

	printf("현재 사용가능한지 확인하고 싶은 무기 번호를 입력하세요\n");
	printf("1.Sword,  2.Gun,  3.Claw,  4.Wand\n");

	int Input = 0;
	cin >> Input;

	if (1 << Input - 1 & MyWeapon)
	{
		printf("사용 가능\n\n");
	}
	else
	{
		printf("사용 불가능\n\n");
	}

	// 3.1 캐릭터가 사용 가능한 무기를 추가하기
	printf("추가할 무기번호를 입력하세요 =");
	cin >> Input;
	MyWeapon |= (1 << Input - 1);


	printf("현재 사용가능한지 확인하고 싶은 무기 번호를 입력하세요\n");
	cin >> Input;
	if (1 << Input - 1 & MyWeapon)
	{
		printf("사용 가능\n");
	}
	else
	{
		printf("사용 불가능\n");
	}

	// 3.2 캐릭터가 사용 가능한 무기를 삭제하기
	printf("삭제할 무기번호를 입력하세요 =");
	cin >> Input;
	MyWeapon &= ~(1 << Input - 1);

	printf("현재 사용가능한지 확인하고 싶은 무기 번호를 입력하세요\n");
	cin >> Input;
	if (1 << Input - 1 & MyWeapon)
	{
		printf("사용 가능\n");
	}
	else
	{
		printf("사용 불가능\n");
	}
}

int main()  // 코드의 시작점
{
	// 반복문
	// - 특정 코드블록을 조건에 따라 여러번 반복해서 실행할 수 있게 해주는 문(Statement)

	// for
	// - 반복 회수가 명확할 때 사용하기 좋다.
	for (int i = 0; i < 5; i++)	// (변수초기화; 종료조건; 증감부)
	{
		printf("Hello For : %d\n", i);
	}

	// while
	// - 반복 회수가 명확하지 않고 조건에 따라 반복해야 할 떄 사용하기 좋다.
	int j = 0;
	while (j < 5)
	{
		printf("Hello while : %d\n", j);
		j++;
	}

	// do-while
	// - while과 비슷한데 최소 한번은 실행해야 할 때 사용하기 좋다.
	j = 0;
	do
	{
		printf("Hello do~whle : %d\n", j);
		j++;
	} while (j < 5);


	// 간단 실습
	// 1. 0을 입력 받을 때까지 입력 받은 숫자의 합을 출력
	// - while이랑 do ~ while 둘 다 해보기
	int Num = -1;
	int WhileSum = 0;
	printf("(while) 더할 숫자 입력(0 입력 시 종료) = ");
	while (Num != 0)
	{
		cin >> Num;

		WhileSum += Num;
	}
	printf("Sum = %d\n\n", WhileSum);


	int DoWhileSum = 0;
	printf("(do ~ while) 더할 숫자 입력(0 입력 시 종료) = ");
	do
	{
		cin >> Num;
		DoWhileSum += Num;
	} while (Num != 0);
	printf("Sum = %d\n\n", DoWhileSum);


	// 2. 입력받은 수의 구구단 출력하기
	int Dan = 0;
	printf("2. 출력할 구구단의 단 입력 = ");

	cin >> Dan;
	for (int i = 1; i <= 9; i++)
	{
		printf("%d * %d = %2d \n", Dan, i, Dan * i);
	}
	printf("\n");

	// 3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기
	printf("3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기. 수 입력 = ");
	int Num3 = 0;

	cin >> Num3;

	for (int i = 1; i <= Num3; i += 2)
	{
		printf("%d ", i);
	}
	printf("\n\n");

	// 4. 1~100 중에 7의 배수만 출력하기
	printf("4. 1~100 중에 7의 배수만 출력하기. \n");
	for (int i = 1; i <= 100; i++)
	{
		if (i % 7 == 0)
		{
			printf("%d \n", i);
		}
	}

	// 5. 팩토리얼 계산하기
	printf("5. 팩토리얼 계산하기, 숫자 입력 = \n");
	int Factorial = 0;
	int Result = 1;

	cin >> Factorial;

	printf("%d! = ", Factorial);
	for (int i = Factorial; i > 1; i--)
	{
		printf("%d * ", i);
		Result *= i;
	}
	printf("1 = %d \n\n ", Result);

	// 6. *로 피라미드 모양의 삼각형 찍기
	int  Pyramid = 0;

	printf("6. *로 피라미드 모양의 삼각형 찍기. 층수 입력 = ");
	cin >> Pyramid;

	for (int i = 1; i <= Pyramid; i++)
	{
		for (int j = Pyramid - i; j > 0; j--)
		{
			printf(" ");
		}

		for (int k = 1; k <= i * 2 - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}


	// 랜덤
	srand(time(0));		// 랜덤의 시드값을 현재 시간으로 설정하기(프로그램 실행할 떄 한번만 하면 된다.)

	int RandomNumber;
	int TestCount = 10000000;
	int Num1 = 0, Num2 = 0, Num3 = 0, Num4 = 0, Num5 = 0, Num6 = 0;

	for (int i = 0; i < TestCount; i++)
	{
		RandomNumber = rand() % 6 + 1;	// 1 ~ 6이 랜덤으로 골라진다.
		//printf("Random : %d \n", RandomNumber);

		switch (RandomNumber)
		{
		case 1:
			Num1++;
			break;

		case 2:
			Num2++;
			break;

		case 3:
			Num3++;
			break;

		case 4:
			Num4++;
			break;

		case 5:
			Num5++;
			break;

		case 6:
			Num6++;
			break;

		default:
			printf("ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!! \n\n");
		}

	}
	printf("Num1 : [%d], Num2 : [%d], Num3 : [%d], Num4 : [%d], Num5 : [%d], Num6 : [%d]", Num1, Num2, Num3, Num4, Num5, Num6);

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
