// Unreal10th_HelloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <random>

using namespace std;

int main()
{
	srand(time(0));

	// 간단 실습
	// 1. 가위 바위 보 게임 만들기
	//	- 3선승제
	//	- enum 활용
/*
	enum RPS
	{
		Scissors,
		Rock,
		Paper,
	};
	printf("1. 가위 바위 보 게임 (3선승제) \n");

	int PlayerWin = 0, ComputerWin = 0;
	int PlayerChoice = 0, ComputerChoice = 0;

	while (PlayerWin < 3 && ComputerWin < 3)
	{
		printf("1.가위, 2.바위, 3.보 선택 = ");
		cin >> PlayerChoice;
		PlayerChoice--;

		ComputerChoice = rand() % 3;	// 컴퓨터 선택

		switch (PlayerChoice)
		{
		case Rock:
			switch (ComputerChoice)
			{
			case Rock:
				printf("바위 vs 바위 = 무승부 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Paper:
				ComputerWin++;
				printf("바위 vs 보 = 컴퓨터 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Scissors:
				PlayerWin++;
				printf("바위 vs 가위 = 플레이어 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;
			}
			break;
	
		case Paper:
			switch (ComputerChoice)
			{
			case Rock:
				PlayerWin++;
				printf("보 vs 바위 = 플레이어 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Paper:
				printf("보 vs 보 = 무승부 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Scissors:
				ComputerWin++;
				printf("보 vs 가위 = 컴퓨터 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;
			}
			break;

		case Scissors:
			switch (ComputerChoice)
			{
			case Rock:
				ComputerWin++;
				printf("가위 vs 바위 = 컴퓨터 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Paper:
				PlayerWin++;
				printf("가위 vs 보 = 플레이어 승 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;

			case Scissors:
				printf("가위 vs 가위 = 무승부 | 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerWin, ComputerWin);
				break;
			}

			break;
		}
	}
	printf("최종 스코어 플레이어[%d] vs 컴퓨터[%d] \n\n", PlayerWin, ComputerWin);
*/


/*
	// 2. 하이 로우
	//	- 컴퓨터가 1~100 사이의 임의의 숫자를 선택하고, 사용자가 맞출 때 까지 입력을 받아 "더 높게", "더 낮게"등의 힌트를
	//	- 5번 안에 맞춰야 함
	printf("2. 하이 로우\n");

	int ComRandomNum = rand() % 100 + 1;
	int PlayerCallNum = 0;
	int Round = 1;
	const int Limit = 5;
		
	do
	{
		printf("숫자를 하나 입력하세요 = ");
		cin >> PlayerCallNum;

		if (PlayerCallNum < ComRandomNum)
		{
			printf("Up!! \n\n");
		}
		else if (PlayerCallNum > ComRandomNum)
		{
			printf("Down!! \n\n");
		}
		else
		{
			printf("정답입니다!\n\n"); 
			break;
		}

		Round++;
	} while (Round <= Limit);

	if (Round >= Limit)
	{
		printf("5회 안에 맞추기 실패...\n\n");
	}
/*/

	// 실습
	
/*
	// 
	// 1. 비트플래그를 이용한 캐릭터 상태 변환 구현하기
	//	- 캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
	//	- 다음 작업을 수행하고 현재 상태 출력하기
	//	- 플레이어의 상태를 대기로 설정
	//	- 점프 상태 추가
	//	- 공격 상태 추가
	//	- 대기 상태 해제
	//	- 무적 상태 추가
	//	- 무적 상태 토글(XOR 사용)
	//
	//	- 현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
	//	- 대기 : [O] , 점프 : [O] , 공격 : [X] , 무적 : [O]
	enum PlayerState
	{
		Idle		= 1 << 0,	// 대기
		Jump		= 1 << 1,	// 점프
		Attack		= 1 << 2,	// 공격
		Invincible	= 1 << 3,	// 무적
	};

	int vPlayerState = Idle;	// 초기상태 Idle
	

	// 초기 상태 출력
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');

	// 점프 상태 추가;
	vPlayerState |= Jump;
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');

	// 공격 상태 추가 
	vPlayerState |= Attack;
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');

	// 대기 상태 해제 
	vPlayerState &= ~Idle;
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');

	// 무적 상태 추가 
	vPlayerState |= Invincible;
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');

	// 무적 상태 토글 
	vPlayerState ^= Invincible;
	printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]\n", (vPlayerState& Idle) ? 'O' : 'X', (vPlayerState& Jump) ? 'O' : 'X', (vPlayerState& Attack) ? 'O' : 'X', (vPlayerState& Invincible) ? 'O' : 'X');
/*/


/*
	//	2. 주사위 게임
	//		1. 초기 세팅
	//			- 플레이어와 컴퓨터 모두 일정 금액(예 : 10000원)으로 시작한다.
	//		2. 1차 주사위 굴리기
	//			- 게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
	//			- 각자 주사위 결과를 공개한다.
	//		3. 배팅
	//			- 이전 판에서 진 쪽이 배팅 금액을 제시한다.
	//			- 제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
	//			- 배팅 금액은 두 사람 모두에게서 차감된다.
	//		4. 2차 주사위 굴리기
	//			- 다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
	//			- (1차 + 2차) 주사위의 합을 계산한다.
	//		5. 승패 판정 및 금액 증감
	//			- 합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
	//			- 동점일 경우 배팅 금액은 그대로 반환한다.
	//		6. 다음 판 진행
	//			- 소지금이 0 이하인 쪽이 나오면 게임 종료.

	enum Stage
	{
		FirstDice,
		Bet,
		SecondDice,
		Result,
		End,
	};

	enum FirstBetPlayer
	{
		Player,
		Computer,
	};

	Stage sStage = FirstDice;
	FirstBetPlayer vFirstBetPlayer = Player;

	int PlayerMoney = 10000, ComputerMoney = 10000;
	int PlayerBet = 0, ComputerBet = 0;
	int PlayerDice = 0, ComputerDice = 0;
	int Pot = 0;

	printf("초기 소지금 - 플레이어[%d] : 컴퓨터[%d] \n\n", PlayerMoney, ComputerMoney);
	do
	{
		switch (sStage)
		{
		case FirstDice:
		{
			int PlayerFirstDice = rand() % 6 + 1;
			PlayerDice = PlayerFirstDice;

			int ComputerFirstDice = rand() % 6 + 1;
			ComputerDice = ComputerFirstDice;
			
			printf("1차 주사위 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerFirstDice, ComputerFirstDice);

			sStage = Bet;	// 게임 상태 (Bet) 변경
			
			break;
		}

		case Bet:
		{
			// 최대 제한 베팅금액
			// 플레이어와 컴퓨터중 더 적은 금액으로 설정
			int MaxLimitMoney = (PlayerMoney < ComputerMoney) ? PlayerMoney : ComputerMoney;	
			int MaxMultiplier = MaxLimitMoney / 100;

			if (vFirstBetPlayer == Player)
			{
				printf("선플레이어 = 플레이어, 베팅 금액 입력 : ");
				do
				{
					cin >> PlayerBet;
					if (PlayerBet > PlayerMoney)
					{
						printf("베팅 금액은 현재 금액보다 클 수 없습니다. 현재 보유머니  %d\n", PlayerMoney);
					}

					else if (PlayerBet > MaxLimitMoney)
					{
						printf("베팅 금액은 양쪽의 보유머니 보다 클 수 없습니다. 현재 보유머니  플레이어[%d] : 컴퓨터[%d]\n", PlayerMoney, ComputerMoney);
					}
				} while (PlayerBet > MaxLimitMoney);
			
				ComputerBet = PlayerBet;	// 플레이어의 베팅금액 만큼 컴퓨터도 배팅금액 설정
			}
			else if (vFirstBetPlayer == Computer)
			{
				// 컴퓨터 배팅금액 결정
				if (MaxMultiplier > 0)
				{
					// 배팅금액 100 단위로 조정
					ComputerBet = (rand() % MaxMultiplier + 1) * 100;
				}

				// 보유 금액이 100보다 작을경우 예외처리
				else
				{
					// 올인
					ComputerBet = ComputerMoney;
				}
			}
			
			// 컴퓨터 배팅금액 만큼 플레이어 배팅금액 설정
			PlayerBet = ComputerBet;		
			
			printf("배팅 금액 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerBet, ComputerBet);
			

			// 팟에 배팅금액 넣고, 플레이어, 컴퓨터 보유머니 차감
			Pot = PlayerBet;
			PlayerMoney -= PlayerBet;

			Pot += ComputerBet;
			ComputerMoney -= ComputerBet;

			sStage = SecondDice;
			break;
		}

		case SecondDice:	// 두번째 주사위 던지고 합산
		{

			int PlayerSecondDice = rand() % 6 + 1;
			int ComputerSecondDice = rand() % 6 + 1;

			PlayerDice += PlayerSecondDice;
			ComputerDice += ComputerSecondDice;

			printf("2차 주사위 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerSecondDice, ComputerSecondDice);

			sStage = Result;
			break;
		}

		case Result:
		{

			// 플레이어 승
			if (PlayerDice > ComputerDice)
			{
				printf("Player Win!! - 플레이어 주사위[%d] : 컴퓨터 주사위[%d]\n", PlayerDice, ComputerDice);
				PlayerMoney += Pot;
				Pot = 0;
				
				printf("남은 소지금 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerMoney, ComputerMoney);
				printf("-------------------------------------------------------\n\n");

				// 컴퓨터가 졌으므로 다음 차례에 먼저 배팅
				vFirstBetPlayer = Computer;
			}

			// 컴퓨터 승
			else if (PlayerDice < ComputerDice)
			{
				printf("Computer Win!! - 플레이어 주사위[%d] : 컴퓨터 주사위[%d]\n", PlayerDice, ComputerDice);
				
				ComputerMoney += Pot;
				Pot = 0;
				
				printf("남은 소지금 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerMoney, ComputerMoney);
				printf("-------------------------------------------------------\n\n");

				// 플레이어가 졌으므로 다음 차례에 먼저 배팅
				vFirstBetPlayer = Player;
			}

			// 무승부
			else
			{
				printf("무승부!! - 플레이어 주사위[%d] : 컴퓨터 주사위[%d]\n", PlayerDice, ComputerDice);
				PlayerMoney += Pot / 2;
				ComputerMoney += Pot / 2;

				printf("남은 소지금 - 플레이어[%d] : 컴퓨터[%d]\n\n", PlayerMoney, ComputerMoney);
				printf("-------------------------------------------------------\n\n");


				Pot = 0;
			}

			// 한쪽이 소지금을 모두 잃으면
			if (PlayerMoney <= 0 || ComputerMoney <= 0)
			{
				sStage = End;
			}
			// 양쪽 다 소지금이 남아 있으면
			else
			{
				sStage = FirstDice;
			}

			break;
		}
					
		}

	}while (sStage != End);
	printf("주사위 게임 종료!\n\n");
*/

/*
	//	3. 홀짝 게임
	//		1. 초기 금액 및 배팅
	//			- 플레이어는 기본금 100원으로 베팅을 시작한다.
	//		2. 홀짝 선택
	//			- 플레이어가 1(홀)또는 2(짝)을 선택한다.
	//		3. 결과 결정
	//			- 컴퓨터가 랜덤으로 1(홀)또는 2(짝)을 선택한다.
	//			- 플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
	//		4. 연속 배팅 선택
	//			- 승리 시 플레이어는 두 가지 중 하나를 선택 :
	//			- (A)이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
	//			- (B)이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
	//		5. 게임 종료 조건
	//			- 플레이어가 소지금이 100원 미만일 경우 게임 종료.
	
	int PlayerMoney = 1000;		// 머니 초기화
	int BetMoney = 0;			// 베팅 금액 
	int PlayerAction = 0;		// 플레이어 홀,짝 선택
	int PlayerWinAction = 0;	// 승리 시 연승도전 여부 선택
	int ComputerAction = 0;		// 컴퓨터의 랜덤 선택
	bool IsWin = 0;				// 승패 판단
	
	printf("3. 홀짝 게임 \n\n");
	printf("현재 머니 [%d] \n", PlayerMoney);
	
	do
	{
		// 연승 베팅아닌 경우 새로 베팅
		if (PlayerWinAction != 1)
		{
			printf("베팅 금액 입력 = ");
			cin >> BetMoney;
			PlayerMoney -= BetMoney;
		}

		printf("1(홀), 2(짝) 중 선택하세요 = ");
		cin >> PlayerAction;

		ComputerAction = rand() % 2 + 1;	// 컴퓨터 1 ~ 2 랜덤 선택

		switch (ComputerAction)
		{
		case 1:
			printf("홀!  \n");
			break;

		case 2:
			printf("짝!! \n");
			break;
		}

		// 승패 판단
		(PlayerAction == ComputerAction) ? IsWin = true : IsWin = false;

		// 홀짝 성공
		if (IsWin)
		{
			// 베팅금액 2배로
			BetMoney *= 2;
			
			printf("1.언승도전  (현재 베팅액 %d )  ,   2.베팅금액 2배 획득 후 리겜  = ", BetMoney);
			cin >> PlayerWinAction;

			// 베팅금액 획득 선택시
			if (PlayerWinAction == 2)
			{
				PlayerMoney += BetMoney;
				printf("베팅금액 획득, 누적 머니 = [%d]\n\n", PlayerMoney);
				BetMoney = 0;
			}
		}

		// 홀짝 실패
		else
		{			
			BetMoney = 0;
			printf("실패.  남은머니 = %d \n\n", PlayerMoney);
		}

	} while (PlayerMoney > 100);

*/

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
