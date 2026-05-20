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


	/*
	// 조건문 간단 실습
	// 1. 숫자를 입력 받아 양수인지 음수인지 0인지 판단하는 코드
	int Num = 0;
	printf("양수인지 음수인지 확인할 숫자 입력 = ");
	std::cin >> Num;

	if (Num > 0)		// 조건문에서는 항상 범위가 큰 것을 먼저 체크하는 것이 좋다.
	{
		printf("%d = 양수 \n", Num);
	}
	else if (Num < 0)
	{
		printf("%d = 음수 \n", Num);
	}
	else
	{
		printf("%d = 0 \n", Num);
	}


	// 2. 숫자를 입력 받아 홀수인지 짝수인지 판단하는 코드
	int Num2 = 0;
	printf("홀수/짝수 확인 할 숫자 입력 = ");
	std::cin >> Num2;

	switch (Num2 % 2)
	{
	case 0:
		printf("%d = 짝수\n\n", Num2);
		break;

	case 1:
		printf("%d = 홀수\n\n", Num2);
		break;
	}

	// 3. 두 수를 입력 받아 더 큰 수를 출력하는 코드, 같을 경우 같다고 출력
	int Num3 = 0, Num4 = 0;
	printf("크기 비교 할 숫자 2개 입력 = ");
	std::cin >> Num3 >> Num4;

	if (Num3 > Num4)
	{
		printf("Num3(%d) 가 더 크다\n", Num3);
	}
	else if (Num3 < Num4)
	{
		printf("Num4(%d) 가 더 크다\n", Num4);
	}
	else
	{
		printf("Num3(%d) == Num4(%d) \n\n", Num3, Num4);
	}


	// 논리 연산자 간단 실습
	// 1. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기
	int age = 0, height = 0;
	printf("나이와 키를 순서대로 입력 = ");
	std::cin >> age >> height;

	if (age >= 6 && height >= 120)
	{
		printf("나이 = %d세, 키 %dcm -> 롤로코스터 탑승 가능\n\n", age, height);
	}
	else
	{
		printf("나이 = %d세, 키 %dcm -> 롤로코스터 탑승 불가능\n\n", age, height);
	}

	// 2. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기
	int Score = 0;
	printf("점수 입력 = ");
	std::cin >> Score;

	if (Score >= 90)
	{
		printf("점수 = %d, A학점\n\n", Score);
	}
	else if (Score >= 80)
	{
		printf("점수 = %d, B학점\n\n", Score);
	}
	else if (Score >= 70)
	{
		printf("점수 = %d, C학점\n\n", Score);
	}
	else if (Score >= 60)
	{
		printf("점수 = %d, D학점\n\n", Score);
	}
	else
	{
		printf("점수 = %d, F학점\n\n", Score);
	}

	// 3. 세 과목의 점수를 입력 받아 세 과목의 평균점이 60점 이상이면 "합격", 아니면 "불합격"을 출력하는 프로그램을 작성하기
	//		한 과목이라도 40점 미만이면 불합격 출력하기
	int Score2 = 0, Score3 = 0, Score4 = 0;
	float average = 0.0f;

	printf("세 과목 점수 입력 = ");
	std::cin >> Score2 >> Score3 >> Score4;

	average = (float)(Score2 + Score3 + Score4) / 3.0f;

	if (Score2 < 40 || Score3 < 40 || Score4 < 40)
	{
		printf("Score2 = %d, Score3 = %d, Score4 = %d, 평균 = %.2f 과락", Score2, Score3, Score4, average);
	}
	else if(average < 60.0f)
	{
		printf("Score2 = %d, Score3 = %d, Score4 = %d, 평균 = %.2f 불합격", Score2, Score3, Score4, average);
	}
	else
	{
		printf("Score2 = %d, Score3 = %d, Score4 = %d, 평균 = %.2f 합격", Score2, Score3, Score4, average);
	}
	*/


	// 5/19 실습
	//  1. 세 수 중 최댓값과 최솟값 찾기
	//  	3개의 정수를 입력받아, 그중 가장 큰 수와 가장 작은 수를 출력

	printf("1. 세 수 중 최댓값과 최솟값 찾기 \n");
	int a = 0, b = 0, c = 0;

	printf("정수 3개 입력 = ");
	std::cin >> a >> b >> c;

	if (a >= b && a >= c)
	{
		printf("최댓값 = %d \n\n", a);
	}
	else if (b >= a && b >= c)
	{
		printf("최댓값 = %d \n\n", b);
	}
	else
	{
		printf("최댓값 = %d \n\n", c);
	}

	if (a <= b && a <= c)
	{
		printf("최소값 = %d \n\n", a);
	}
	else if (b <= a && b <= c)
	{
		printf("최소값 = %d \n\n", b);
	}
	else
	{
		printf("최소값 = %d \n\n", c);
	}


	//  2. 세 개의 선분 길이를 입력받아, 이 선분들로 삼각형을 만들 수 있는지 판별하기
	//  	조건 : 삼각형이 되려면 '한 변의 길이 < 나머지 두 변의 길이의 합'이어야 함.
	printf("2. 세 개의 선분 길이를 입력 받아 이 선분들로 삼각형을 만들 수 있는지 판별하기 \n");

	int LineA = 0, LineB = 0, LineC = 0;
	printf("세 개의 선분 길이 입력 = ");
	std::cin >> LineA >> LineB >> LineC;

	if ((LineA < LineB + LineC) && (LineB < LineA + LineC) && (LineC < LineA + LineB))
	{
		printf(" 삼각형 가능\n\n");
	}
	else
	{
		printf(" 삼각형 불가능\n\n");
	}

	//  3. 미니 계산기
	//  	두 개의 정수와 하나의 연산자(+, -, *, / )를 입력받아 결과를 출력
	//  	단, 나눗셈에서 0으로 나누려고 하면 "0으로 나눌 수 없습니다"라는 에러 메시지를 출력
	printf("3. 미니 계산기 \n");
	int Number1 = 0, Number2 = 0;
	char Operator = '\0';

	printf("두개의 정수와 연산자를 입력하시오 = ");
	std::cin >> Number1 >> Operator >> Number2;

	switch (Operator)
	{
	case '+':
		printf("%d %c %d = %d\n\n", Number1, Operator, Number2, Number1 + Number2);
		break;

	case '-':
		printf("%d %c %d = %d\n\n", Number1, Operator, Number2, Number1 - Number2);
		break;

	case '*':
		printf("%d %c %d = %d\n\n", Number1, Operator, Number2, Number1 * Number2);
		break;

	case '/':
		if (Number2 == 0)
		{
			printf("0으로 나눌 수 없습니다. \n\n");
		}
		else
		{
			printf("%d %c %d = %f\n\n", Number1, Operator, Number2, (float)(Number1 / Number2));
		}
		break;

	default:
	{
		printf("잘못 입력했습니다. \n\n");
	}
	}



	//  4. 윤년 판별기
	//  	연도(예 : 2024)를 입력받아 그 해가 윤년인지 평년인지 출력
	//  	윤년의 조건 :
	//			연도가 4로 나누어 떨어지면 윤년이다.
	//  		하지만 100으로 나누어 떨어지면 평년이다.
	//  		그럼에도 400으로 나누어 떨어지면 윤년이다.
	printf("4. 윤년 판별기 \n");
	int Year = 0;
	printf("연도를 입력 하세요 = ");
	std::cin >> Year;

	if (((Year % 4 == 0) && (Year % 100 != 0)) || ((Year % 4 == 0) && (Year % 400 == 0)))
	{
		printf("%d년은 윤년 입니다.\n\n", Year);
	}
	else
	{
		printf("%d년은 윤년이 아닙니다.\n\n", Year);
	}

}