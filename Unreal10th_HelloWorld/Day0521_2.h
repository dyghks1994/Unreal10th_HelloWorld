#pragma once


void Day0521_Run();

// 헤더파일에는 선언만 넣는다.

// Add라는 이름의 함수를 선언 했다.
// Add는 int Num1과 int Num2 두개의 파라미터를 가지고 
// int  타입의 데이터를 리턴한다.
int Add(int Num1, int Num2);
float Add(float Num1, float Num2);

int Sub(int Num1, int Num2);
float Sub(float Num1, float Num2);

int Mul(int Num1, int Num2);
float Mul(float Num1, float Num2);

int Div(int Num1, int Num2);
float Div(float Num1, float Num2);


// 리턴값 없음, 파리미터도 없음.
void Test();

// 템플릿
template <typename T>
T Add(T Num1, T Num2)
{
	T Result = Num1 + Num2;
	return Result;
}