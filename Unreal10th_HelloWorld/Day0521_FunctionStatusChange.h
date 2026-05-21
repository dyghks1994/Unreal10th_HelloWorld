#pragma once

//// 실습 풀이 ---------------------------------------------------------------------
//	/*
//	* 비트플래그를 이용한 캐릭터 상태 변환 구현하기
//		캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
//		다음 작업을 수행하고 현재 상태 출력하기
//			플레이어의 상태를 대기로 설정
//			점프 상태 추가
//			공격 상태 추가
//			대기 상태 해제
//			무적 상태 추가
//			무적 상태 토글(XOR 사용)
//		현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
//			대기 : [O], 점프: [O], 공격: [X], 무적: [O]
//	*/

enum PlayerState;

void StatusChange();

int SetState(int CurState, PlayerState TargetState);
int ClearState(int CurState, PlayerState TargetState);
int ToggleState(int CurState, PlayerState TargetState);

void ShowStatus(int CurState);