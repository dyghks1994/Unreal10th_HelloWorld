#pragma once

void Day0522_Run();
void Day0522_Array_Example1();
void Day0522_Array_Example2();
void Day0522_Array_Example3();

void Day0522_Casting();

void Day0522_Reference();
void Test_Reference1(int Data);
int Test_Reference2(int Data);
void Test_Reference3(int& Data1, int& Data2, int& Data3);

void Day0522_ArrayParameter();
void Test_ArrayParameter(int* Array, int Length);


// 간단 실습
	// 1. 배열의 값들을 전부 출력해주는 함수 만들기
	// 2. 배열을 파라미터로 받는 함수를 만들어 구현하기
	//	- 배열 내부값을 모두 더하고 평균 구해보기
	//	- 배열의 값 중 최대값과 최소값 구해보기
	// 3. 피셔 예이츠 알고리즘 완성하기
void PrintArray(int* Array, int Length);
float AverageArrayElements(int* Array, int Length);
int FindMaxElements(int* Array, int Length);
int FindMinElements(int* Array, int Length);

void Day0522_Shuffle();
void FisherYateShuffle(int* Array, int Length);



// 0522 실습
// 1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기(배열 활용하기)
void DiceNumCount();

// 2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기(파라메터 : int* Array, int Size)
void ReverseArray(int* Array, int Size);

// 3. 로또 번호 생성기(셔플알고리즘 활용하기)
//	- 전체 숫자 범위: 1번부터 45번까지.
//	- 맞춰야 하는 숫자 개수 : 6개.
void MakeLottoNum();

// 4. 미로 탈출 게임 만들기
//	2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
//	미로의 구성
//		10행 20열의 2차원 배열
//			저장 방식
//				길(0) : '. '으로 표시
//				벽(1) : '# '으로 표시
//				시작점(2) : 'S '로 표시
//				출구(3) : 'E '로 표시
//	이동 입력 처리
//		w(W) : 위, s(S) : 아래, a(A) : 왼쪽, d(D) : 오른쪽
//		대소문자 구분 없이 처리
//		플레이어가 출구에 도착하면 종료
//			플레이어는 ‘P ‘로 표시
//		게임 화면은 다음과 같은 양식을 따른다.
//			w(↑) s(↓) a(←) d(→)는 이동 가능한 방향만 출력한다.
void EscapeMaze();
void PrintMaze(int* Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY);