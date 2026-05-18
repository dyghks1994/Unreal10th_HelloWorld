// Unreal10th_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int main()  // 코드의 시작점
{
	/*
	int Number = 10;	// 대입 연산자로 Number에 10을 넣었다.
	printf("Number = %d\n", Number);
	printf("Number = %5d\n", Number); // Number를 정수 5자리로 출력해라
	Number = 20;		// 대입 연산자로 Number에 20을 넣었다.(덮어써진다)
	printf("Number = %d\n", Number);
	Number = 5 + 10;	// 산술 연산자 +를 이용해서 5와 10을 더하고 그 결과를 Number에 대입한다.
	printf("Number = %d\n", Number);
	Number = 7 % 3;		// 산술 연산자 %를 이용해서 7을 3으로 나눈 나머지를 구하고(1) 그 결과를 Number에 대입한다.

	int Temp1 = 7;

	Number += Temp1;	// Number와 Temp1의 값을 더하고 그 결괄를 Number에 덮어쓴다. (Number = 8)
	printf("Number = %d\n", Number);
	Number *= Temp1;	// Number와 Temp1의 값을 곱하고 그 결괄를 Number에 덮어쓴다. (Number = 56)
	printf("Number = %d\n", Number);

	Number--;	// (Number = 55)
	Number--;	// (Number = 54)
	Number--;	// (Number = 53)
	printf("Number = %d\n", Number);
	*/

	/*
	// 간단 실습
	// - 두 수를 입력받아 스왑하기
	printf("두 수를 입력 받아 스왑하기\n");
	int num1 = 0;
	int num2 = 0;
	printf("num1 입력 = ");
	std::cin >> num1;

	printf("num2 입력 = ");
	std::cin >> num2;

	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("Swap 후 num1 = [%d], num2 = [%d] \n\n", num1, num2);

	//////////////////////////////////////////////////////////////////////////////
	
	// - 두 수를 입력받아 합을 출력하기
	printf("두 수를 입력 받아 합을 출력하기\n");
	int num3 = 0;
	int num4 = 0;
	printf("num3 입력 = ");
	std::cin >> num3;
	printf("num4 입력 = ");
	std::cin >> num4;
	printf("num3 + num4 = %d \n\n", num3 + num4);

	//////////////////////////////////////////////////////////////////////////////
	
	// - 사각형의 가로, 세로를 입력받아 넓이를 출력하기
		printf("사각형의 가로, 세로를 입력받아 넓이를 출력하기\n");
	int width = 0;
	int height = 0;

	printf("넓이 입력 = ");
	std::cin >> width;
	printf("높이 입력 = ");
	std::cin >> height;
	printf("사각형의 넓이 = %d \n\n", width * height);

	//////////////////////////////////////////////////////////////////////////////

	// - 두 수를 입력받아 나머지를 출력하기(% 연산자를 사용한 것과 안 한것 모두)
	printf("두 수를 입력받아 나머지를 출력하기(%% 연산자를 사용한 것과 안 한것 모두)\n");
	printf("1. %연산자 사용\n");
	int a = 0;
	int b = 0;
	printf("숫자a 입력 = ");
	std::cin >> a;
	printf("숫자b 입력 = ");
	std::cin >> b;
	printf("a %% b = %d \n\n", a % b);

	printf("2. %%연산자 미사용 ver\n");
	printf("%d - (%d / %d) * %d = %d \n\n", a, a, b, b, a - (a / b) * b);


	/////////////////////////////////////////////////////////////////////////////
	*/

	
	//	1. 온도 변환기 
	//	설명: 섭씨 온도를 정수로 입력받아 화씨 온도로 변환하여 출력하는 프로그램.
	//	공식: 화씨 = 섭씨 * 9 / 5 + 32
	printf("1. 온도 변환기 \n");
	printf("섭씨 온도 정수 입력 = ");
	int Celsius = 0;
	std::cin >> Celsius;

	int Fahrenheit = Celsius * 9 / 5 + 32;
	printf("화씨 온도 = F˚%d\n\n", Fahrenheit);



	//	2. 시간 계산기
	//	초를 입력 받아 시분초 출력하기
	printf("2. 시간 계산기 \n");
	int Time = 0;
	int Hour = 0;
	int Minute = 0;
	int Seconds = 0;

	printf("시간 초 입력 = ");	
	std::cin >> Time;			// 초단위 입력
	
	Hour = Time / 3600;			// 시간 계산 1시간 = 3600초
	
	Time %= 3600;				// 분 계산 시간 제외하고 60초로 나누기
								// Time -= Hour * 3600; 도 가능
	Minute = Time / 60;

	Seconds = Time % 60;		// 초 계산, 나머지
								// Time -= Minute * 60; 도 가능

	printf("Hour = %d, Minute = %d, Seconds = %d \n\n", Hour, Minute, Seconds);


	//	3. 동전 개수 계산하기
	//	금액을 입력받아 500원, 100원, 50원, 10원 동전이 각각 몇 개 필요한지 계산하는 프로그램.
	//	금액이 큰 동전을 최대한 많이 받아야 한다.
	printf("3. 동전 개수 계산하기 \n");
	printf("금액 입력 = ");
	int Money = 0;
	std::cin >> Money;

	int Coin500 = 0, Coin100 = 0, Coin50 = 0, Coin10 = 0;
	Coin500 = Money / 500;
	Money -= 500 * Coin500;

	Coin100 = Money / 100;
	Money -= 100 * Coin100;

	Coin50  = Money / 50;
	Money -= 50 * Coin50;

	Coin10  = Money / 10;
	Money -= 10 * Coin10;

	printf("500 = %d, 100 = %d, 50 = %d, 10 = %d \n\n", Coin500, Coin100, Coin50, Coin10);

	
	//	4. 자리수 분리하기(입력은 항상 세자리라고 가정)
	//	수를 입력받고 100의 자리, 10의 자리, 1의 자리를 각각 출력하기
	//	각 자리의 수를 합해서 출력하기
	printf("4. 자리수 분리하기(입력은 항상 세자리라고 가정) \n");
	int num = 0;
	std::cin >> num;

	int units = 0, tens = 0, hundreds = 0;
	
	hundreds = num / 100;
	num %= 100;

	tens = num / 10;
	num %= 10;

	units = num;

	printf("100의자리 = %d, 10의자리 = %d, 1의자리 = %d \n\n", hundreds, tens, units);
	printf("각 자리수의 합 = %d \n\n", hundreds + tens + units);
		
	//	5. 파일 용량 환산기
	//	메가바이트(MB) 단위의 파일 크기를 입력받아, 킬로바이트(KB)와 바이트(Byte) 단위로 환산해 출력하는 프로그램
	//	공식: 1MB = 1024KB, 1KB = 1024Byte
	printf("5. 파일 용량 환산기 \n");
	printf("MB 입력 = ");
	int MB = 0, KB = 0, Byte = 0;
	std::cin >> MB;

	KB = MB * 1024;
	Byte = KB * 1024;

	printf("%dMB = %dKB = %dByte", MB, KB, Byte);


	//	6. 타일 개수 계산기 (면적 구하기)
	//	직사각형 방의 가로, 세로 길이(cm)를 입력받고, 가로 30cm, 세로 30cm인 타일로 이 방을 채우려면 타일이 총 몇 개 필요한지 출력하기
	printf("6. 타일 개수 계산기 (면적 구하기) \n");
	
	int Width = 0, Height = 0;
	int TileSize = 30;

	printf("가로, 세로 입력 = ");
	std::cin >> Width >> Height;

	int WidthCount = (Width + (TileSize - 1)) / TileSize;
	int HeightCount = (Height + (TileSize - 1)) / TileSize;

	printf("필요한 타일 개수 = %d", WidthCount * HeightCount);

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
