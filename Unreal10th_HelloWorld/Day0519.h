#pragma once

#include <iostream>

int main()  // 코드의 시작점
{
	// 이진수
	// - 0과 1로만 표현되는 숫자
	// - ex) int i = 8;		// 메모리 : 0000 0000 0000 0000 0000 0000 0000 1000
	// 
	// float(부동소수점)
	// 32bit
	// - 소수점이 있는 숫자를저장한다.
	// - 구조적으로 오차가 있는 데이터 타입. 같다는 비교를 조심해서 해야한다.

	// double(부동수수점)
	// - 64bit

	float RealNumber = 0.0f;	// 0.0f는 float
	RealNumber = 0.1;			// 0.1은 double	-> 암시적 변환이 일어나 float으로 저장됨 -> 워닝 발생
	RealNumber = (float)0.1f;	// 명시적 변환, casting

	printf("이것은 실수입니다 : %f \n", RealNumber);

	RealNumber = 0.1f + 0.5f;
	printf("이것은 실수입니다 : %.2f\n", RealNumber);	// 소수점 아래 둘째자리까지 출력

	RealNumber -= 0.2f;
	printf("이것은 실수입니다 : %8.2f\n", RealNumber);	// 소수점 포함 전체 8자리, 소수점 아래 둘째자리까지 출력

	// 불리언 타입
	// bool
	// - true, false 이 둘만 저장
	// - 프로그램의 각종 분기를 결정할 때 사용
	// - 8bit
	bool bTest = false;
	bTest = true;
	printf("bool 타입의 사이즈는 [%d]byte 입니다.", (int)sizeof(bool));


	// char(캐릭터 타입)
	// - 글자 하나를 저장하는 데이터 타입
	// - 8bit짜리 정수형 데이터 타입
	char testChar = 'a';
	testChar = 'b';

	printf("char c = %c \n", testChar);

	// 문자열
	// - char*, std::string
	std::string TestString = "Hello World\n";

	// 부호 없는 인티저(32bit, 숫자범위 0~42억)
	unsigned int TestIngeter = 0;

	// 64bit 인티저
	long long TestInteger64 = 0;
	unsigned long long TestInteger64_2 = 0;

	// 유니코드 캐릭터
	wchar_t UnicodeChar = L'가';

	int Size = 100;
	printf("한변이 %d인 정사각형의 넓이는 %d 입니다. \n", Size, Size * Size);
	Size = 50000;
	printf("한변이 %d인 정사각형의 넓이는 %u 입니다. \n\n", Size, (unsigned int)Size * (unsigned int)Size);

	// 간단 실습
	// 1. 원의 반지름 입력 받고 넓이 구하기
	const float PI = 3.141592f;
	float Radius = 0.0f;
	printf("원의 반지름 입력 = ");
	std::cin >> Radius;

	printf("원의 넓이 = %f \n\n", PI * Radius * Radius);

	// 2. 3개의 값을 입력 받고 평균값 구하기
	float Num1 = 0.0f, Num2 = 0.0f, Num3 = 0.0f;
	float Average = 0.0f;

	printf("실수 3개 입력 = ");
	std::cin >> Num1 >> Num2 >> Num3;
	
	Average = (Num1 + Num2 + Num3) / 3.0f;
	printf("세 수의 평균은 = %f \n\n", Average);


	// 3. 정가와 할인율을 입력받고 할인된 가격 구하기
	float Price = 0.0f;
	float Discount = 0.0f;

	printf("정가 입력 = ");
	std::cin >> Price;
	printf("할인율 입력 = ");
	std::cin >> Discount;

	printf("최종 가격 = %df \n\n", Price - Price * (Discount * 0.01f));



	// 상수
	// - 절대 변하지 않는 숫자
	// - 코드의 안정성과 가독성을 높여준다.
	const int TestCount = 10;
	// TestCount = 20;	// 컴파일 에러

	// 비교 연선자
	// - 두 변수를 비교하는 연산자 (크다, 작다, 같다 등등을 계산)
	bool bTest = false;
	bTest = 10 > 5;		// true
	bTest = 10 < 5;		// false
	bTest = 10 >= 5;	// true
	bTest = 10 >= 10;	// true
	bTest = 10 > 10;	// false
	bTest = 10 == 10;	// true

	bTest = 0.1f + 0.2f == 0.3f;	// 이런식의 비교는 절대로 하면 안된다.

	// 조건문
	// - 특정 조건에 따라 다른 동작을 하게 만드는 문(statement)

	// if
	// - ()사이의 조건식이 true면 아래쪽 {} 사이의 코드를 실행한다.
	int a = 30;
	int b = 20;
	if (a > b)
	{
		printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
	}

	// if else
	// - ()사이의 조건식이 true면 아래쪽 {} 사이의 코드를 실행하고 false면 else 아래의 {} 사이의 코드를 실행한다.
	if (a > b)
	{
		printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
	}

	else
	{
		printf("a(%d)가 b(%d)보다 작습니다.\n", a, b);
	}

	// else if
	// - if를 중첩하기
	if (a > b * 2)
	{

	}

	else if (a > b)
	{

	}

	else if (a > (b / 2))
	{

	}

	// switch
	// - 값이 여러가지 중 하나일 때 각각의 경우에 따라 다르게 처리할 때 사용
	switch (a)
	{
	case 1:
		printf("a는 1 입니다.\n");
		break;

	case 2:
		printf("a는 2 입니다.\n");
		break;

	default:
		printf("a는 %d입니다.\n", a);
		break;
	}

	// 삼항 연산자
	int x = (a > 10) ? 1 : 0;	// ? 앞에 조건식이 참이면  ?와 : 사이에 있는 값, 거짓이면 : 뒤에 있는 값.

	// 논리 연산자
	// - 참 아니면 거짓이 나오는 연산
	// - bool을 다루는 연산자

	// &&
	//  - AND
	//  - && 연산자 좌우의 갑이 모두 true면 true, 아니면 false
	//  - bool bTeest = true && true	// 이때만 bTest가 true.
	// ||
	//  - OR
	//  - || 연산자 좌우의 값이 하나라도 true면 true, 둘다 false일 때만 false
	//	- bool bTest = false || false;	// 이때만 fbTest가 false
	// !
	//	- NOT
	//	- true는 false로 만들고 false는 true로 변경
	//	- bool bTest = true; bTest = !bTest;	// bTest는 false

	int Point = 78;
	if (Point < 90 && Point >= 80)
	{
		printf("B학점 입니다.\n");
	}
}