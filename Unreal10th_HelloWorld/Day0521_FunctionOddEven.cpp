#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>
#include "Day0521_FunctionOddEven.h"

using namespace std;

void OddEvenGame()
{
	const int InitialMoney = 10000;	// 게임 시작할 때 플레이어의 돈
	const int MinimumBet = 100;		// 최소 배팅 금액
	const int WinMultiplier = 2;	// 이겼을 때 배율
	
	int Money = InitialMoney;		// 플레이어의 현재 돈
	int CurrentBat = MinimumBet;	// 현재 배팅 금액
	
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	
	srand(Seed);	// 시드값 초기화
	
	while (Money >= 100)	// 게임 종료 조건 : 플레이어가 소지금이 100원 미만일 경우 게임 종료.
	{
		// 배팅
		// 플레이어는 기본금 100원으로 베팅을 시작한다.
		printf("\n현재 소지금 : [%d]원\n", Money);
		printf("현재 배팅 금액 : [%d]원\n", CurrentBat);
		Money -= CurrentBat;	// 배팅 금액만큼 감소
	
		// 홀짝 선택
		//	플레이어가 1(홀)또는 2(짝)을 선택한다.
		int Select = 0;
		while (Select != 1 && Select != 2)	// 잘못된 입력 방지
		{
			printf("홀(1) 또는 짝(2)을 선택하세요 : ");
			Select = SelectNum();
		}
	
		// 결과 결정
		//	컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
		//	플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
		int Result = MakeRandomNumber();	// 랜덤으로 1 or 2 고르기
		ShowResult(Result);

		if (Select == Result)
		{
			int WinPrice = CurrentBat * WinMultiplier;	// 승리 상금은 현재 배팅금액의 두배
			ShowWinMessage(WinPrice, MinimumBet);

			int KeepGoing = 0;
			while (KeepGoing != 1 && KeepGoing != 2)	// 선택지 입력받기
			{
				KeepGoing = SelectNum();
			}
			if (KeepGoing == 1)
			{
				CurrentBat = WinPrice;		// 상금을 다시 그대로 배팅
			}
			else
			{
				Money += WinPrice;			// 상금을 받고
				CurrentBat = MinimumBet;	// 100원부터 다시 배팅
			}
		}
		else
		{
			CurrentBat = ResetBetMoney(CurrentBat, MinimumBet);	// 배팅 금액 초기화
		}
	}
	
	printf("소지금이 부족해서 더 이상 진행할 수 없습니다.\n");
}

int MakeRandomNumber()
{
	return rand() % 2 + 1;;
}

void ShowResult(int Result)
{
	printf("결과는 [%s]입니다.\n", (Result == 1) ? "홀" : "짝");
	return;
}

void ShowWinMessage(int WinPrice, int MinimumBet)
{
	printf("축하합니다! [%d]원을 획득할 수 있습니다.\n", WinPrice);
	printf("1) [%d]원을 모두 다시 배팅\n", WinPrice);
	printf("2) [%d]원을 받고 다시 [%d]원부터 배팅\n", WinPrice, MinimumBet);
	printf("1 또는 2 중 하나를 선택하세요 : ");

	return;
}

int SelectNum()
{
	int Num = 0;

	cin >> Num;						// 입력 받고
	cin.clear();					// 잘못된 입력일 때 에러 리셋
	cin.ignore(10000, '\n');		// 버퍼 비우기
	
	return Num;
}

int ResetBetMoney(int CurrentBat, const int MinimumBet)
{
	printf("안타깝네요! 배팅한 [%d]원을 모두 잃었습니다.\n", CurrentBat);
	CurrentBat = MinimumBet;	// 배팅 금액 초기화
	return CurrentBat;
}
