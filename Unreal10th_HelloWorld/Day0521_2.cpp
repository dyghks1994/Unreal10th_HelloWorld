#include <stdio.h>
#include "Day0521_2.h"

int Add(int Num1, int Num2)
{
	return Num1 + Num2;
}

float Add(float Num1, float Num2)
{
	return Num1 + Num2;
}

int Sub(int Num1, int Num2)
{
	return Num1 - Num2;
}

float Sub(float Num1, float Num2)
{
	return Num1 - Num2;
}

int Mul(int Num1, int Num2)
{
	return Num1 * Num2;
}

float Mul(float Num1, float Num2)
{
	return Num1 * Num2;
}

int Div(int Num1, int Num2)
{
	if (Num2 != 0)
	{
		return Num1 / Num2;
	}
	else
	{
		return 0;
	}
}

float Div(float Num1, float Num2)
{
	if (Num2 != 0.0f)
	{
		return Num1 / Num2;
	}
	else
	{
		return 0.0f;
	}
}

void Test()
{
	printf("Hello World\n");
	return;
}
