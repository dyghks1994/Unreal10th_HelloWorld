#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Day0527.h"

void Day0527()
{
	// 문자열(String)
	//	- 한 문장. 연속된 char.
	//	- C에서는 char*, char [] 사용
	//	- 항상 모든 문자열은 '\0'로 끝난다.
	const char* TestString1 = "Hello String!\n";
	const char* TestString2 = "안녕 문자열!\n";		// 인코딩이 자동으로 처리되서 한글이 보이는거다.

	// wchar_t : 유니코드용 char.

	const char* TestString = "Hello";
	int Size = MyStrLen(TestString);
	printf("[%s]의 길이는 [%d]입니다.\n", TestString, Size);

	Size = (int)strlen(TestString);
	printf("[%s]의 길이는 [%d]입니다.\n\n", TestString, Size);

	char Buffer[32] = { 0, };
	strcpy(Buffer, TestString);
	printf("Buffer의 내용은 [%s]입니다.\n", Buffer);	// Buffer : Hello

	strcat(Buffer, TestString);
	printf("Buffer의 내용은 [%s]입니다.\n\n", Buffer);	// Buffer : HelloHello

	int Result = strcmp("abc", "abc");	// 같으면 0
	Result = strcmp("ab", "abc");		// 왼쪽이 작으면 -1
	Result = strcmp("abb", "abc");
	Result = strcmp("abc", "abb");		// 오른쪽이 작으면 +1
	Result = strcmp("abc", "ab");

	const char* TestStringNubmer1 = "123";
	int Number = atoi(TestStringNubmer1);
	printf("문자열 [%s]는 인티저 [%d]입니다.\n", TestStringNubmer1, Number);

	const char* TestStringNubmer2 = "12.3";
	float FloatNumber = (float)atof(TestStringNubmer2);
	printf("문자열 [%s]는 실수 [%f]입니다.\n\n", TestStringNubmer2, FloatNumber);

	// 간단 실습
	// 1. MyStrCpy
	char TestBuffer[15] = "abcdefghij";
	printf("MyStrCpy 호출 전 : TestBuffer = %s\n", TestBuffer);
	MyStrCpy(TestBuffer, "1234567");
	printf("MyStrCpy(TestBuffer, \"1234567\") -> TestBuffer[%s]\n\n", TestBuffer);

	// 2. MyStrCat
	char TestMyStrCat[20] = "Hi Hello";
	printf("MyStrCat 호출 전 : TestBuffer = %s\n", TestMyStrCat);
	MyStrCat(TestMyStrCat, " Ba na na");
	printf("MyStrCat(TestMyStrCat, \" Ba na na\") -> TestMyStrCat[%s] \n\n", TestMyStrCat);

	// 3. MyStrCmp
	char TestMyStrCmp1[20] = "a1b2c3d4";
	char TestMyStrCmp2[20] = "a1b2c3d6";
	printf("MyStrCmp(%s , %s) = %d \n\n", TestMyStrCmp1, TestMyStrCmp2, MyStrCmp(TestMyStrCmp1, TestMyStrCmp2));

	// 4. MyAtoI
	char TestMyAtoI1[] = "123";
	char TestMyAtoI2[] = "0";
	char TestMyAtoI3[] = "  -7789";
	char TestMyAtoI4[] = "45ds";
	char TestMyAtoI5[] = "as56";
	char TestMyAtoI6[] = "+-123";
	printf("MyAtoI(%s) = (%d)\n", TestMyAtoI1, MyAtoI(TestMyAtoI1));
	printf("MyAtoI(%s) = (%d)\n", TestMyAtoI2, MyAtoI(TestMyAtoI2));
	printf("MyAtoI(%s) = (%d)\n", TestMyAtoI3, MyAtoI(TestMyAtoI3));
	printf("MyAtoI(%s) = (%d)\n", TestMyAtoI4, MyAtoI(TestMyAtoI4));
	printf("MyAtoI(%s) = (%d)\n", TestMyAtoI5, MyAtoI(TestMyAtoI5));
	printf("MyAtoI(%s) = (%d)\n\n", TestMyAtoI6, MyAtoI(TestMyAtoI6));


	// 5. MyAtoF
	int PassCount = 0;
	const char* TestMyAtoF1[] = { "123.45", "-38.556", "0.0", "3.14", "+0.5", ".7", "12.0", "-.54" };
	float TestFloat[] = { 123.45f, -38.556f, 0.0f, 3.14f, +0.5f, .7f, 12.0f, -.54f };

	int ArrayCount = sizeof(TestMyAtoF1) / sizeof(TestMyAtoF1[0]);
	for (int i = 0; i < ArrayCount; i++)
	{
		// 0.0001f 오차범위 내면 정상적으로 변환된 것으로 판단
		if (MyAtoF(TestMyAtoF1[i]) - TestFloat[i] < 0.0001f)
		{
			PassCount++;
		}
		printf("(%d) MyAtoF(%s) -> %f : PASS\n", i+1, TestMyAtoF1[i], MyAtoF(TestMyAtoF1[i]));
	}
	printf("PassCount = %d \n", PassCount);

	int FailCount = 0;
	const char* TestMyAtoF2[] = { "12.05.78", "45.dd", "aqw45.8", "12. 35", "" };
	
	int ArrayCount2 = sizeof(TestMyAtoF2) / sizeof(TestMyAtoF2[0]);
	for (int i = 0; i < ArrayCount2; i++)
	{
		if (MyAtoF(TestMyAtoF2[i]) == 0.0f)
		{
			FailCount++;
		}
		printf("(%d) MyAtoF(% s) -> %f : Fail \n", i+1, TestMyAtoF2[i], MyAtoF(TestMyAtoF2[i]));
	}
	printf("FailCount = %d \n", FailCount);

	// 위 함수들 만들기. 파라메터와 리턴 타입은 원본과 같이 만들기

}

int MyStrLen(const char* str)
{
	// \0는 제외한 길이를 리턴
	int Length = 0;
	while (*(str + Length) != '\0')
	{
		Length++;
	}
	return Length;
}

char* MyStrCpy(char* strDestination, const char* strSource)
{
	/*
	int Length = MyStrLen(strSource);

	for (int i = 0; i <= Length; i++)
	{
		*(strDestination + i) = *(strSource + i);
	}

	return strDestination;
	*/

	char* Result = strDestination;

	while ((*strDestination++ = *strSource++) != '\0') 
	{
		// 바디는 아무것도 안함
	}

	// 1. *Destination = *Source : Source의 char 값을 Destination 에 담는다.
	// 2. Destination++, Source++로 다음 글자로 이동
	// 3. Destination의 현재 값을 나타내는 글자가 \0인지 아닌지 확인

	return Result;
}

char* MyStrCat(char* strDestination, const char* strSource)
{
	/*
	int DstLength = MyStrLen(strDestination);
	int SrcLength = MyStrLen(strSource);

	for (int i = DstLength, j = 0; j <= SrcLength; i++, j++)
	{
		*(strDestination + i) = *(strSource + j);
	}

	return strDestination;
	*/

	char* Result = strDestination;
	
	// Destination의 마지막까지 이동
	while (*strDestination)
	{
		strDestination++;
	}

	// Destination의 마지막부터 Source를 하나씩 붙여넣기
	while ((*strDestination++ = *strSource++) != '\0')
	{
		// 바디는 아무것도 안함
	}

	return Result;

}

int MyStrCmp(const char* str1, const char* str2)
{
	// str1의 값이 '\0'이 아니고, str1과 str2가 같을 때
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int MyAtoI(const char* Source)
{
	//	- 성공 : "123", "-342", "0", " 33", "+92", "  -11"
	//  - 실패. 무조건 0반환 : "45ds", "as54", " +-233", "12 35", ""

	// 공백 제거
	while (*Source == ' ' || *Source == '\t' || *Source == '\n' || *Source == '\r')
	{
		Source++;
	}

	// 부호처리
	int Sign = 1;
	if (*Source == '-')
	{
		Sign = -1;
		Source++;
	}
	else if (*Source == '+')
	{
		Source++;
	}

	// 문자를 숫자로 바꾸기
	int Result = 0;
	while (*Source >= '0' && *Source <= '9')
	{
		Result = Result * 10 + (*Source - '0');	// 숫자 누적하기
		Source++;
	}

	// 숫자가 아닌 것이 나왔을 때 처리
	if (*Source != '\0')
	{
		Result = 0;
	}

	return Result * Sign;
}

float MyAtoF(const char* Source)
{
	//	- 성공 : "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54"
	//	- 실패. 무조건 0반환 : "12.05.78", "45.dd", "aqw45.8", "12. 35", ""

	// 공백 제거
	while (*Source == ' ' || *Source == '\t' || *Source == '\n' || *Source == '\r')
	{
		Source++;
	}

	// 부호 처리
	int Sign = 1;
	if (*Source == '-')
	{
		Sign = -1;
		Source++;
	}
	else if (*Source == '+')
	{
		Source++;
	}

	// 문자를 숫자로 바꾸기
	float Result = 0;
	while (*Source >= '0' && *Source <= '9')
	{
		Result = Result * 10.0f + (*Source - '0');	// 숫자 누적하기
		Source++;
	}

	// 소수점(.) 처리
	if (*Source == '.')
	{
		Source++;

		float Fraction = 1.0f;
		// 문자를 숫자로 바꾸기
		while (*Source >= '0' && *Source <= '9')
		{
			Result = Result * 10.0f + (*Source - '0');	// 숫자 누적하기
			Source++;
			Fraction *= 0.1f;	// 소수점 아래로 얼마나 내려갈지 누적
		}
		Result *= Fraction;		// 소수점 적용
	}

	// 숫자가 아닌 것이 나왔을 때 처리
	if (*Source != '\0')
	{
		Result = 0;
	}

	return Result * Sign;
}
