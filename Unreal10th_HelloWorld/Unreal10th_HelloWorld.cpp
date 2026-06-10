// Unreal10th_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>

#include "Day0521_2.h"
#include "Day0522.h"
#include "Weekend0523.h"
#include "Day0526.h"
#include "Day0527.h"
#include "Day0528.h"
#include "Day0529.h"
#include "Day0602.h"
#include "Day0605.h"
#include "Day0609.h"
#include "Day0610.h"

#include "Maze.h"

using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	// RunCode
	{
		///0522 내용
		//Day0521_Run();
		
		/// 0522 내용
		//Day0522_Run();
		//Day0522_Array_Example1();
		//Day0522_Array_Example2();
		//Day0522_Array_Example3();

		//Day0522_Casting();
		//Day0522_Reference();

		//Day0522_Shuffle();
		//Weekend0523_Dungeon();
		
		//Day0526();
		//Day0527();
		//Day0528();
		//Day0529();
	
		//Day0602();
		
		//Day0605 day0605;
		//day0605.Test();
		//day0605.EnumClass();
		//day0605.TestDArray();
	}

	//Day0609 day0609;
	//day0609.Day0609_Main();

	Day0610 day0610;
	day0610.TestMain();

	//Maze_Run();

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