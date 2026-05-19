// Unreal10th_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int main()  // 코드의 시작점
{
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

	if ( (LineA < LineB + LineC) && (LineB < LineA + LineC) && (LineC < LineA + LineB))
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

	if ( ((Year % 4 == 0) && (Year % 100 != 0)) || ((Year % 4 == 0) && (Year % 400 == 0)))
	{
		printf("%d년은 윤년 입니다.\n\n", Year);
	}
	else
	{
		printf("%d년은 윤년이 아닙니다.\n\n", Year);
	}

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
