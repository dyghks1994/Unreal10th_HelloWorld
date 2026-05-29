#include <iostream>
#include <fstream>
#include <string>
#include "Day0528.h"

using namespace std;

void Day0528()
{
	// 파싱(Parsing)
	// - 문자열이나 데이터 구조를 분석하여 의미있는 정보로 변환하는 과정
	// - csv, json, xml 등등

	//const char* TestString = "Orc, 10, 5, 10";
	//int Size = strlen(TestString);
	//for (int i = 0; i < Size; i++)
	//{
	//	if (TestString[i] == ',')
	//	{
	//
	//	}
	//}
	//char Name[256];
	//int Strength;

	//char Input[256];
	//std::cin >> Input;
	//printf("%s", Input);
	//std::cin.getline(Input, 256);	// 띄어쓰기 포함 입력 받을 때 사용
	//printf("%s\n", Input);

	//Day0528_String();
	//Day0528_FileIO();
	//Day0528_Structure();

	Maze0528();
}

void Day0528_String()
{
	const char* Temp = "Hello World!\n";	// c 스타일 문자열
	std::string Str1 = "Hello";
	printf("%s\n", Str1.c_str());
	std::string Str2 = "World!";
	printf("%s\n", Str2.c_str());
	std::string Str3 = Str1 + " " + Str2 + "\n";
	printf("%s\n", Str3.c_str());

	string Str4("Hello World?\n");	// 생성자를 사용하는 방식
	Str4 += Temp;					// 문자열 합치기(+=. =)
	Str4.append(" Append");
	printf("%s\n", Str4.c_str());

	// 문자열 길이 확인
	string Str5 = "Hello";
	//Str5.length();
	//Str5.size();
	printf("%s : %d\n", Str5.c_str(), (int)Str5.size());

	if (Str1 == Str5)
	{
		printf("Str1과 Str2는 같습니다.\n");
	}
	if (Str1 != Str2)
	{
		printf("Str2와 Str2는 다릅니다.\n");
	}
	if (Str1 < Str2)
	{
		printf("Str1이 Str2보다 앞에 있씁니다.\n");
	}

	// 문자열에서 특정 문자 위치 찾기
	int ePos = (int)Str1.find('e');
	printf("%s에서 'e'는 %d 인덱스에 있습니다.", Str1.c_str(), ePos);

	// 특정 문자열 모두 찾기
	size_t Pos = Str1.find('1');
	while (Pos != string::npos)		// npos는 못찾았을 경우
	{
		printf("% s에서 '1'는 %d 인덱스에 있습니다.", Str1.c_str(), (int)Pos);
		Pos = Str1.find('1', Pos + 1);
	}

	// 인덱스로 문자열의 특정 위치 접근하기
	printf("%s의 첫번째 글자는 %c입니다. \n", Str1.c_str(), Str1[0]);
	printf("%s의 네번째 글자는 %c입니다. \n", Str1.c_str(), Str1[4]);

	// std::string과 char를 파라메터로 받아서 string에 char가 어디에 있었는지 출력하는 함수 만들기
	// - 여러개 있으면 모두 출력
	// - 없으면 없다고 출력
	string Str6 = "banana";
	FindCharacter(Str6, 'n');
	FindCharacter(Str6, 'z');

}

void Day0528_FileIO()
{
	// 파일 입력
	const string FilePath = ".\\Data\\DataFile.txt";	// .은 현재 워킹 폴더(기본적으로 파일이 실행되는 곳)
	std::ifstream InputFile(FilePath);	// 입력용 파일 스트림 만들기
	if (InputFile.is_open())
	{
		string FileTexts(
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);
		printf("파일 내용 : \n%s\n", FileTexts.c_str());
		InputFile.close();
	}
	else
	{
		// 파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.\n");
	}

	// 파일 출력
	const string OutputFilePath = ".\\Data\\OutTest.txt";
	std::ofstream OutFile(OutputFilePath);					// 기존 파일 덮어쓰기
	//std::ofstream OutFile(OutputFilePath, std::ios::app);	// 덧붙이기
	if (OutFile.is_open())
	{
		OutFile << "Hello World\n";
		OutFile << "안녕하세요2.\n";
		OutFile.close();
	}
	else
	{
		printf("파일을 생성하는데 실패했습니다.");
	}


	// 간단 실습
	// - 이름과 돈을 입력 받고 파일로 저장하기
	// - 파일을 불러와서 저장된 이름과 돈을 출력하기
	std::string strName;
	int Money = 0;
	std::string OutText;

	std::string OutputFilePath2 = ".\\Data\\OutTest2.txt";
	std::ofstream OutFile2(OutputFilePath2);

	printf("이름 입력 = ");
	std::cin >> strName;
	printf("돈 입력 = ");
	std::cin >> Money;

	printf("간단 실습 \n 이름과 돈을 입력 받고 파일로 저장하기\n");
	if (OutFile2.is_open())
	{
		std::string outStr = "이름 : " + strName + "\n";
		//outStr = outStr + "돈 : " + Money + "\n";
	}
	else
	{
		printf("파일을 생성하는데 실패했습니다.");

	}
}

void Day0528_Structure()
{
	// 구조체
	//	- 관련된 데이터 집합을 표현하는데 사용.
	//		- 여러 종류의 데이터 타입을 하나로 묶어서 사용
	//	- 프로그램의 가독성과 유지보수성도 향상
	
	Enemy Orc;		// Orc라는 변수로 4가지의 정보에 접근 가능
	Enemy Orcs[5];	// Enemy 5개

	// 인스턴스
	// - 변수 그 자체
	// - int a;	// int타입의 인스턴스 a를 만들었다.

	// 구조체 멤버 접근법
	// - .을 이용한다.(실제 인스턴스일 때)
	// - ->를 이용한다.(주소를 가지고 있을 떄)

	Orc.Name = "돌쇠";			// .을 이용해 각 멤버에 접근
	Orc.Health = 100.0f;
	Orc.AttackPower = 10.0f;
	Orc.Reward = 5;

	Enemy* OrcAddress = &Orc;
	
	// 간단 실습
	// Enemy의 데이터를 출력하는 함수 만들기
	// - Enemy의 참조를 파라메터로 받는 함수
	PrintEnemyData(Orc);
	
	Orc.Name = "돌쇠였던 것";
	Orc.Health = 90.0f;

	// - Enemy의 주소를 파라메터로 받는 함수
	PrintEnemyData(&Orc);

	// 초기화 방법
	// 1. 멤버 직접 초기화
	//	- 구조체 선언할 때 직접 값을 넣어 놓는 것
	// 2. 중괄호 초기화
	//	- 인스턴스를 생성할 때 한번에 만드는 방식
	// 3. 생성자 초기화 리스트
	//	- 생성자에서 멤버가 선언된 순서대로 데이터 설정
	// 4. 생성자 내부 대입
	//	- 이미 생성된 객체에 값을 대입 처리

	// 생성자
	// - 구조체나 클래스의 객체가 만들어 질 때(인스턴스 생성자) 자동으로 호출되는 특별한 함수 같은 것.
	// - 주로 멤버 변수 초기화에 사용
	// - 특징
	//	- 이름이 구조체 이름과 같다.
	//	- 반환형이 없다.
	//	- 객체가생성될 떄 자동으로 호출
	//	- 생성자가 여러개 일 수도 있다.
		

	int Test[] = { 1,2,3,4,5 };
	EnemyOrc TestOrc = { std::string("쓰랄"), 200.0f, 50.0f, 100 };	// 2. 중괄호 초기화
	PrintEnemyData(&TestOrc);
	EnemyOrc* TestOrc2 = new EnemyOrc(3.0f);
	PrintEnemyData(TestOrc2);
	delete TestOrc2;
	TestOrc2 = nullptr;
	
	
	
	
	//Function(Orc);

}

void FindCharacter(const std::string& str, const char Target)
{
	/*
	printf("%s에서 %c의 위치는 = ", str.c_str(), Target);

	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == Target)
		{
			printf("%d ", i + 1);
			count++;
		}
	}

	if (count > 0)
	{
		printf("입니다.\n");
	}
	else
	{
		printf("%c는 없습니다.\n",Target);
	}
	//*/

	bool bFound = false;
	size_t Pos = str.find(Target);	// 일단 찾기 시도
	while (Pos != string::npos)		// 찾았으면 while 안으로 들어가기(npos는 못 찾았을 경우)
	{
		printf("%s에서 '%c'는 %d 인덱스에 있습니다.\n", str.c_str(), Target, (int)Pos);
		Pos = str.find(Target, Pos + 1);	// str에서 Target를 찾는데 Pos(이전에 찾은 위치) 다음부터 찾아라. find의 두번째 파라메터는 시작 위치
		bFound = true;	// 찾았다고 표시
	}

	if (!bFound)
	{
		// 찾은 것이 없다.
		printf("%s에서 '%c'는 없습니다.\n", str.c_str(), Target);
	}
}

void TestStruct(Enemy Target)
{
	printf("[Call by Value Test]\n");
	printf("오크의 이름은 [%s]입니다.\n", Target.Name.c_str());
	printf("오크의 체력은 [%.1f]입니다.\n", Target.Health);
	printf("오크의 공격력은 [%.1f]입니다.\n", Target.AttackPower);
	printf("오크의 보상은 [%d]입니다.\n", Target.Reward);
}

void PrintEnemyData(Enemy& Target)
{
	printf("[Call by Reference Test]\n");
	printf("적의 이름은 [%s]입니다.\n", Target.Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n", Target.Health);
	printf("적의 공격력은 [%.1f]입니다.\n", Target.AttackPower);
	printf("적의 보상은 [%d]입니다.\n", Target.Reward);
}

void PrintEnemyData(Enemy* Target)
{
	//(*Target).Health;	// 이것도 가능
	printf("[Call by Address Test]\n");
	printf("적의 이름은 [%s]입니다.\n", Target->Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n", Target->Health);
	printf("적의 공격력은 [%.1f]입니다.\n", Target->AttackPower);
	printf("적의 보상은 [%d]입니다.\n", Target->Reward);
}

void PrintEnemyData(EnemyOrc* Target)
{
	printf("적의 이름은 [%s]입니다.\n", Target->Name.c_str());
	printf("적의 체력은 [%.1f]입니다.\n", Target->Health);
	printf("적의 공격력은 [%.1f]입니다.\n", Target->AttackPower);
	printf("적의 보상은 [%d]입니다.\n", Target->Reward);
}

// MapData.txt 파일에서 입력받아 미로 초기화 ver
void Maze0528()
{
	const int MazeRows = 10;
	const int MazeCols = 20;

	// 미로 배열

	//int Maze[MazeRows][MazeCols] =
	//{
	//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
	//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
	//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
	//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
	//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
	//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
	//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	//};
	//*/
		
	int* MazePointer = nullptr;
	//MazePointer = new int[20 * 10]
	InitializeMaze0528(&MazePointer);
	
	// 플레이어 생성
	MazePlayer Player;
	
	// 골인지점 위치 초기화
	int GoalPosY = 7;
	int GoalPosX = 18;

	//  골 도착 여부
	bool bGoal = false;

	char PlayerInput = 0;

	//PrintMaze(&Maze[0][0], MazeRows, MazeCols);

	do
	{
		//getchar();
		//system("cls");
		printf("== = 미로 탈출 게임 Ver2 == =\n");
		

		PrintMaze0528(&MazePointer, MazeRows, MazeCols, Player.PosX, Player.PosY);
		printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽) :\n");
		printf("w(↑) s(↓) a(←) d(→)\n");

		cin >> PlayerInput;
		cin.clear();
		cin.ignore(10000, '\n');

		// 이동하려는 위치 변수 현재 위치로 초기화
		int CheckPosY = Player.PosY;
		int CheckPosX = Player.PosX;

		/// 위로 이동하려고 할 때
		if (PlayerInput == 'w' || PlayerInput == 'W')
		{
			CheckPosY -= 1;
		}

		/// 왼쪽으로 이동하려고 할 때
		else if (PlayerInput == 'a' || PlayerInput == 'A')
		{
			CheckPosX -= 1;
		}

		/// 아래쪽으로 이동하려고 할 때
		else if (PlayerInput == 's' || PlayerInput == 'S')
		{
			CheckPosY += 1;
		}

		/// 오른쪽으로 이동하려고 할 때
		else if (PlayerInput == 'd' || PlayerInput == 'D')
		{
			CheckPosX += 1;
		}

		// 이동하려는 위치가 벽이 아니라면
		if (MazePointer[CheckPosY * MazeCols + CheckPosX] != 1)
		{
			// 플레이어 위치 이동
			Player.PosY = CheckPosY;
			Player.PosX = CheckPosX;

			// 이동 후 미로 재출력
			//PrintMaze2(Maze2, MazeRows, MazeCols, PlayerPosX, PlayerPosY);

			// 골인 지점 도착시 종료 판별 변수 설정
			if (Player.PosY == GoalPosY && Player.PosX == GoalPosX)
			{
				printf("미로 탈출 성공!!\n");
				bGoal = true;
			}

			// 랜덤 확률로 이벤트 발생
			else
			{
				// 랜덤 숫자 생성
				int RandNum = rand() % 10;

				/// 20% 확률로 전투 진입
				// 랜덤으로 0~9 숫자를 선택하고
				// 값이 0 or 1 인 경우
				if (RandNum < 2)
				{
					// 적 생성 
					MazeEnemyHW Enemy;

					// 전투 진행 후 결과 저장
					int Result = Battle0528(Player, Enemy);

					// 플레이어 패배
					if (Result == -1)
					{
						printf("미로를 탈출하지 못했습니다..\n\n");
					}
				}

				/// 20% 확률로 Hp 회복
				// 5, 6인 경우
				if (RandNum >= 5 && RandNum <= 6)
				{
					HealHp0528(&Player.HealthPoint, Player.MaxHealthPoint);
				}
			}

		}

		else
		{
			printf("이동 불가!\n\n");
			
		}


	} while (bGoal == false && Player.HealthPoint > 0);

	printf("===================================================\n\n");

	// 동적 할당 포인터 해제
	delete MazePointer;
}

void InitializeMaze0528(int** Maze)
{
	std::string FilePath = ".\\Data\\MapData.txt";
	std::ifstream In(FilePath);

	// 맵 데이터 정상적으로 연결 됐으면
	if (!In.is_open())
	{
		printf("파일을 열 수 없습니다.\n");
		In.close();

		return;
	}

	int MazeWidth = 0;
	int MazeHeight = 0;

	// 첫번째 줄은 미로의 사이즈라고 약속(정의)하고 사용
	std::string str;
	getline(In, str);

	/// 데이터 파일의 첫 번째 줄을 추출해서 미로의 가로, 세로 구하기
	{
		/// 첫 라인에서 가로, 세로 크기 파싱
		size_t pos = str.find(',');
		if (pos != std::string::npos)
		{
			MazeHeight = std::stoi(str.substr(0, pos));	// 가로 크기
			MazeWidth = std::stoi(str.substr(pos + 1));	// 세로 크기
		}
	}

	/// Width * Height 미로 생성
	*Maze = new int[MazeWidth * MazeHeight];
	for (int i = 0; i < MazeWidth * MazeHeight; i++)
	{
		(*Maze)[i] = 0;	// 초기화
	}
	
	/// 데이터 파일의 두 번째 줄부터 각 칸의 데이터 추출	
	// 두 번쨰 줄부터 데이터는 한자리 숫자라는 전제 필요( 0, 1, 2, 3 )
	int InsertIndex = 0;
	int TotalSize = MazeHeight * MazeWidth;
	while (getline(In, str) && InsertIndex < TotalSize)
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			// 숫자만 가져오기
			if (str[i] >= '0' && str[i] <= '9')
			{
				int Val = static_cast<int>(str[i] - '0');
				(*Maze)[InsertIndex] = Val;
				InsertIndex++;
			}
		}
		//printf("\n");
	}
	//*/
	
}

void PrintMaze0528(int** Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY)
{
	printf("\n");

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			// 플레이어의 위치를 출력하려고 할 때
			if (i == PlayerPosY && j == PlayerPosX)
			{
				// P 출력 후 다음 위치로 넘김
				printf("P");
				continue;
			}

			// 현재 인덱스의 값 추출
			int Val = (*Maze)[i * Cols + j];				/// int*로 변경후 코드

			switch (Val)
			{
			case 0: { printf(". ");	break; }	// 길
			case 1: { printf("# ");	break; }	// 벽
			case 2: { printf("S ");	break; }	// 시작점
			case 3: { printf("E "); break; }	// 출구
			}
		}
		printf("\n");
	}
	//*/
}

int Battle0528(MazePlayer& Player, MazeEnemyHW& Enemy)
{
	int Result = 0;			// 전투 상태 체크 1(플레이어 승리), 0(전투중), -1(적 승리)
	int TurnCount = 1;	// 턴 카운트

	printf("========= 전투 시작 =========\n");

	// 전투중 턴 진행
	while (Result == 0)
	{
		printf("-> 턴 (%d)\n", TurnCount);

		// 플레이어 데미지 계산
		Player.AttackPower = (rand() % (Player.MaxAttackPower - Player.MinAttackPower + 1)) + Player.MinAttackPower;	// 5 ~ 15

		// 10% 확률로 크리티컬 적용
		int Temp = rand() % 10;
		if (Temp < 1)
		{
			Player.AttackPower *= 2;	// 데미지 2배 적용
		}

		printf("플레이어의 공격~! 데미지 : %d\n", Player.AttackPower);
		Enemy.HealthPoint -= Player.AttackPower;
		if (Enemy.HealthPoint < 0)
		{
			Enemy.HealthPoint = 0;
		}
		printf("현재 적 체력 = [%d]\n", Enemy.HealthPoint);

		// 적이 죽으면
		if (Enemy.HealthPoint <= 0)
		{
			Result = 1;	// 플레이어 승리 처리

			// 보상 설정
			int Reward = rand() % Enemy.Reward + 1;

			Player.Money += Reward;

			printf("적을 쓰러뜨렸다!!!\n");
			printf("%d원 획득! 현재 Money = %d\n", Reward, Player.Money);
			printf("=============================\n");

			break;
		}

		// 적 데미지 계산
		Enemy.AttackPower = (rand() % (Enemy.MaxAttackPower - Enemy.MinAttackPower + 1)) + Enemy.MinAttackPower;	// 5 ~ 15
		printf("적의 공격~! 데미지 : %d\n", Enemy.AttackPower);
		Player.HealthPoint -= Enemy.AttackPower;
		if (Player.HealthPoint < 0)
		{
			Player.HealthPoint = 0;
		}
		printf("현재 플레이어 체력 = [%d]\n", Player.HealthPoint);


		// 플레이어가 죽으면
		if (Player.HealthPoint <= 0)
		{
			Result = -1;	// 적 승리 처리
			printf("\n플레이어 Hp가 0이 되어 패배...\n\n");
			printf("=============================\n");

			break;
		}

		printf("\n");

		// 턴 증가
		TurnCount++;
	}

	return Result;
}

void HealHp0528(int* PlayerHp, const int MaxHp)
{
	// HP 회복
	(*PlayerHp) += 15;

	// 최대 HP보다 넘치면 최대 HP로 보정
	if (*PlayerHp > MaxHp)
	{
		*PlayerHp = MaxHp;
	}

	printf("[ Hp가 회복 됩니다. 남은 Hp = %d ]\n", *PlayerHp);
}
