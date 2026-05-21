#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include "Day0521_FunctionStatusChange.h"

using namespace std;


enum PlayerState
{
	None = 0,
	Wait = 1 << 0,	// 0001
	Jump = 1 << 1,	// 0010
	Attack = 1 << 2,	// 0100
	Invincible = 1 << 3	// 1000
};

void StatusChange()
{		
	int State = None;
	// 플레이어의 상태를 대기로 설정
	State = SetState(State, Wait);		// State에 Wait을 Or 시키고 저장해라.
	ShowStatus(State);
		
	// 점프 상태 추가
	State = SetState(State, Jump);		// State에 Jump을 Or 시키고 저장해라.
	ShowStatus(State);
	
	// 공격 상태 추가
	State = SetState(State, Attack);	// State에 Attack을 Or 시키고 저장해라.
	ShowStatus(State);
	
	// 대기 상태 해제
	//State &= (~Wait);	// State에 Not시킨 Wait를 And시키고 저장해라.
	State = ClearState(State, Wait);
	ShowStatus(State);
	
	// 무적 상태 추가
	State = SetState(State, Invincible);
	ShowStatus(State);
	
	// 무적 상태 토글(XOR 사용)
	State = ToggleState(State, Invincible);
	ShowStatus(State);
}

int SetState(int CurState, PlayerState TargetState)
{
	return CurState | TargetState;
}

int ClearState(int CurState, PlayerState TargetState)
{
	return CurState & (~TargetState);
}

int ToggleState(int CurState, PlayerState TargetState)
{
	return CurState ^ TargetState;
}

void ShowStatus(int CurState)
{
	printf("\n현재상태\n");
	printf("대기 : [%c], 점프: [%c], 공격: [%c], 무적: [%c]",
		(CurState & Wait) ? 'O' : 'X',
		(CurState & Jump) ? 'O' : 'X',
		(CurState & Attack) ? 'O' : 'X',
		(CurState & Invincible) ? 'O' : 'X');

	return;
}
