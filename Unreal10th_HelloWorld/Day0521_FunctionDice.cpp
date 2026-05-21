#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>

#include "Day0521_FunctionDice.h"

using namespace std;

void DiceGame()
{

	const int InitialMoney = 10000;	// 게임 시작시 소유 금액		
	unsigned int Seed = (unsigned int)time(0);
	//Seed = 0;		// 테스트용으로 임시로 설정

	srand(Seed);	// 시드값 초기화

	int Turn = 1;					// 현재 턴
	bool PlayerLost = false;		// 이전판의 승자 기록용 bool. 플레이어가 졌으면 true, 플레이어가 이겼으면 false
	int Bet = 0;					// 현재 배팅 금액(한명분)
	int MaxBet = 0;					// 최대 배팅 금액
	int PlayerMoney = InitialMoney;	// 플레이어의 소유 금액
	int ComMoney = InitialMoney;	// 컴퓨터의 소유 금액

	while (PlayerMoney > 0 && ComMoney > 0)	// 한명이 돈이 남아 있는 한 반복
	{
		// 턴 상황 표시
		ShowTurnInfo(Turn, PlayerMoney, ComMoney);

		// 1차 주사위 굴리기
		const int DiceSize = 6;
		int PlayerDice1 = 0;			// 플레이어의 첫번째 주사위 값
		int ComDice1 = 0;				// 컴퓨터의 첫번째 주사위 값
		PlayerDice1 = ThrowDice(DiceSize);
		ComDice1 = ThrowDice(DiceSize);
		ShowFirstDiceNumber(PlayerDice1, ComDice1);

		// 배팅
		//if (PlayerMoney < ComMoney)
		//{
		//	MaxBet = PlayerMoney;
		//}
		//else
		//{
		//	MaxBet = ComMoney;
		//}
		MaxBet = (PlayerMoney < ComMoney) ? PlayerMoney : ComMoney;	// 배팅금액의 최대치는 보유금액까지
		if (PlayerLost)
		{
			// 플레이어가 졌다. => 플레이어가 배팅
			do
			{
				Bet = BetPlayer(Bet, MaxBet);
				
			} while (Bet<1 || Bet > MaxBet);	// 범위를 벗어난 값이나 잘못 입력했을 때를 위해 다시 입력 받는 처리
		}
		else
		{
			// 플레이어가 이겼다 => 컴퓨터가 배팅
			Bet = BetComputer(Bet, MaxBet);
		}
		PlayerMoney = CalcBetMoney(PlayerMoney, Bet);	// 배팅 금액 차감
		ComMoney = CalcBetMoney(ComMoney, Bet);		// 배팅 금액 차감

		// 2차 주사위 굴리기
		int PlayerDice2 = 0;			// 플레이어의 두번째 주사위 값
		int ComDice2 = 0;				// 컴퓨터의 두번째 주사위 값
		PlayerDice2 = ThrowDice(DiceSize);
		ComDice2 = ThrowDice(DiceSize);
		ShowSecondDiceNumber(PlayerDice2, ComDice2);

		int PlayerSum = PlayerDice1 + PlayerDice2;		// 합계 출력
		int ComSum = ComDice1 + ComDice2;
		ShowSumDiceNumber(PlayerSum, ComSum);

		// 승패 판정 및 금액 증감
		if (PlayerSum > ComSum)
		{
			printf("플레이어 승리! 당신이 [%d]원을 획득합니다.\n", Bet * 2);
			PlayerMoney += (Bet * 2);
			PlayerLost = false;
		}
		else if (ComSum > PlayerSum)
		{
			printf("컴퓨터 승리! 컴퓨터가 [%d]원을 획득합니다.\n", Bet * 2);
			ComMoney += (Bet * 2);
			PlayerLost = true;
		}
		else
		{
			printf("무승부입니다. 배팅 금액은 반환됩니다.");
			PlayerMoney += Bet;
			ComMoney += Bet;
		}

		// 턴 종료
		Turn++;
	}

	ShowGameEndMessage(PlayerMoney);
}

void ShowTurnInfo(int TurnNum, int PlayerMoney, int ComMoney)
{
	printf("\n---------- %d Turn ----------\n", TurnNum);
	printf("플레이어 금액 : %d\t/\t컴퓨터 금액 : %d\n", PlayerMoney, ComMoney);
}

void ShowFirstDiceNumber(int Dice1, int Dice2)
{
	printf("플레이어 1차 주사위 : %d\n", Dice1);
	printf("컴퓨터 1차 주사위   : %d\n", Dice2);

	return;
}

void ShowSecondDiceNumber(int Dice1, int Dice2)
{
	printf("플레이어 2차 주사위 : %d\n", Dice1);
	printf("컴퓨터 2차 주사위   : %d\n", Dice2);

	return;
}

void ShowSumDiceNumber(int Sum1, int Sum2)
{
	printf("플레이어 주사위 합계 : %d\n", Sum1);
	printf("컴퓨터 주사위 합계   : %d\n", Sum2);
}

int ThrowDice(const int DiceSize)
{
	return rand() % DiceSize + 1;
	// return rand() % (Max + 1 - Min) + Min;
}

int BetPlayer(int Bet, int MaxBet)
{
	printf("배팅 금액을 입력하세요(1~%d) : ", MaxBet);
	cin >> Bet;
	cin.clear();					// 에러 상태 해제
	cin.ignore(10000, '\n');		// 이전 입력 제거

	return Bet;
}

int BetComputer(int Bet, int MaxBet)
{
	Bet = rand() % MaxBet + 1;
	printf("컴퓨터가 배팅 금액으로 [%d]원을 지정했습니다.\n", Bet);

	return Bet;
}

int CalcBetMoney(int Money, int Bet)
{
	return Money - Bet;
}

void ShowGameEndMessage(int PlayerMoney)
{
	printf("\n------------ 게임 종료 ------------\n");
	if (PlayerMoney > 0)
	{
		printf("당신의 승리입니다.\n");
	}
	else
	{
		printf("컴퓨터의 승리입니다. 당신은 파산했습니다.\n");
	}
}
