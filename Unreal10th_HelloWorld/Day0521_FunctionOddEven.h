#pragma once

// 홀짝 게임 ------------------------------------
//	/*
//	* 홀짝 게임
//		초기 금액 및 배팅
//			플레이어는 기본금 100원으로 베팅을 시작한다.
//		홀짝 선택
//			플레이어가 1(홀) 또는 2(짝)을 선택한다.
//		결과 결정
//			컴퓨터가 랜덤으로 1(홀) 또는 2(짝)을 선택한다.
//			플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
//		연속 배팅 선택
//			승리 시 플레이어는 두 가지 중 하나를 선택:
//				(A) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
//				(B) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
//		게임 종료 조건
//			플레이어가 소지금이 100원 미만일 경우 게임 종료.
//	*/
//

void OddEvenGame();

int MakeRandomNumber();

void ShowResult(int Result);
void ShowWinMessage(int WinPrice, int MinimumBet);

int SelectNum();
int ResetBetMoney(int CurrentBat, const int MinimumBet);