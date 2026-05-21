// 주사위 게임(함수화)-----------------------------
//	/*
//	주사위 게임
//		초기 세팅
//			플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
//		1차 주사위 굴리기
//			게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
//			각자 주사위 결과를 공개한다.
//		배팅
//			이전 판에서 진 쪽이 배팅 금액을 제시한다.
//			제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
//			배팅 금액은 두 사람 모두에게서 차감된다.
//		2차 주사위 굴리기
//			다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
//			(1차+2차) 주사위의 합을 계산한다.
//		승패 판정 및 금액 증감
//			합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
//			동점일 경우 배팅 금액은 그대로 반환한다.
//		다음 판 진행
//			소지금이 0 이하인 쪽이 나오면 게임 종료.
//	*/

#pragma once
void DiceGame();

void ShowTurnInfo(int TurnNum, int PlayerMoney, int ComMoney);
void ShowFirstDiceNumber(int Dice1, int Dice2);
void ShowSecondDiceNumber(int Dice1, int Dice2);
void ShowSumDiceNumber(int Sum1, int Sum2);

int ThrowDice(const int DiceSize);
int BetPlayer(int Bet, int MaxBet);
int BetComputer(int Bet, int MaxBet);

int CalcBetMoney(int Money, int Bet);

void ShowGameEndMessage(int PlayerMoney);

// 기능이 완전히 독립적이라 재활용 용도로 만드는 함수

// 의도를 명확하게 보여주는 용도로 만드는 함수

// 각종 수식처럼 자주 변할 수 있는 부분을 쉽게 구분하기 위해 만드는 함수