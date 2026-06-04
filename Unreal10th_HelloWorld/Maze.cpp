#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Utils.h"
#include "Player.h"
#include "Monster.h"
#include "Maze.h"



/// 06/02 실습 클래스화 적용
// 미로 탈출 게임에 클래스 적용하기
// 적과 플레이어의 부모인 Actor 클래스 만들기
// 공통 함수로 ApplyDamage, TakeDamage가 있어야 한다.
// Player 클래스 만들고 적용하기(Actor를 상속 받아야 함)
// Monster 클래스 만들기(Actor를 상속 받아야 함)
// 3종류 이상의 몬스터 클래스 만들기(Monster 클래스를 상속 받아야 함)
// 전투시 랜덤한 몬스터가 등장하게 수정
// 결과는 플레이 영상 링크 제출

// 미로 배열
//int Maze[MazeHeight][MazeWidth] =
//{
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//    {1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//    {1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//    {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//    {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
//int* Maze = nullptr;
MazeData Maze;

void Maze_Run()
{
    Maze_Dungeon();
}

void Maze_Dungeon()
{
    //int Maze[MazeHeight][MazeWidth];  // 메모리 구조는 똑같다.
    //Maze = new int[MazeHeight * MazeWidth]
    //    {
    //        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    //        1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    //        1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1,
    //        1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
    //        1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    //        1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
    //        1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    //        1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3, 1,
    //        1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    //        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    //    };
    std::string MapDataString = ReadFile(MapFilePath);  // 읽고
    Maze = ParseMaze(MapDataString);    // 파싱하고
    if (!IsValidMazeData(&Maze))        // 검증
    {
        return;
    }

    
    Player MyPlayer({ 0, 0 }, "플레이어", 500, 500, 5, 15);
    

    MyPlayer.SetPosition(FindStart());    // 시작 위치 찾기

    if (MyPlayer.GetPosition().X != InvalidPosition && MyPlayer.GetPosition().Y != InvalidPosition)
    {
        // 시작 위치를 잘 찾은 정상적인 경우
        printf("\n\n===== 텍스트 미로 탈출 게임 =====\n\n");
        bool IsGameOver = false;

        while (!IsGameOver)
        {
            printf("진행을 위해 아무키나 눌러주세요");
            int Temp = getchar();

            system("cls"); // 화면 깨끗이 지우기

            // 화면 출력
            PrintMaze(MyPlayer);
            PrintPlayerState(MyPlayer);

            // 출구에 도달했는지 확인
            if (IsGoal(MyPlayer))
            {
                printf("축하합니다! 미로를 탈출했습니다!\n\n");
                break;
            }

            // 입력 처리
            MoveDirection Direction = GetMoveInput(MyPlayer);
            Position Pos = MyPlayer.GetPosition();  // 이동할 좌표 담을 임시 변수
            
            switch (Direction)
            {
            case DirUp:
                Pos.Y--;
                break;
            case DirDown:
                Pos.Y++;
                break;
            case DirLeft:
                Pos.X--;
                break;
            case DirRight:
                Pos.X++;
                break;
            case DirNone:
            default:
                printf("ERROR!!! 비정상적인 방향입니다!!!!\n");
                break;
            }
            // 이동할 좌표를 실제 플레이어 좌표로 세팅
            MyPlayer.SetPosition(Pos);

            // 랜덤 인카운터 처리
            switch (RandomIncounter())
            {
            case RI_Battle:
                // 전투 시작
                if (Battle(MyPlayer))
                {
                    printf("승리! 탐색을 계속합니다.\n");
                    Temp = getchar();
                }
                else
                {
                    Temp = getchar();
                    printf("당신은 패배했습니다.\nGame Over...\n");
                    IsGameOver = true;
                }
                break;
            case RI_Heal:
                Heal(MyPlayer);
                Temp = getchar();
                break;
            case RI_Treasure:
                Treasure(MyPlayer);
                Temp = getchar();
                break;
            case RI_None:
            default:
                break;
            }
        }
    }
    else
    {
        // 시작 위치를 찾지 못한 비정상적인 경우
        printf("ERROR!!!!! 맵에 시작위치를 찾을 수 없습니다.!!!\n");
    }

    //delete[] Maze;
    //Maze = nullptr;
    CleanupMazeData(&Maze);

    printf("게임 종료\n");
}

void FindStart(int& OutX, int& OutY)
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (unsigned int y = 0; y < Maze.Height; y++)
    {
        for (unsigned int x = 0; x < Maze.Width; x++)
        {
            if (GetMazeData(x, y) == MazeStart)    // 플레이어 시작점을 찾았으면
            {
                OutX = x;
                OutY = y;
                return;     // 저장하고 함수 종료
            }
        }
    }
    OutX = InvalidPosition; // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
    OutY = InvalidPosition;
}

Position FindStart()
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (unsigned int y = 0; y < Maze.Height; y++)
    {
        for (unsigned int x = 0; x < Maze.Width; x++)
        {
            if (GetMazeData(x, y) == MazeStart)    // 플레이어 시작점을 찾았으면
            {
                return Position(x, y);
            }
        }
    }

    // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
    return Position(InvalidPosition, InvalidPosition);
}

void PrintMaze(Player& InPlayer)
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (unsigned int y = 0; y < Maze.Height; y++)
    {
        for (unsigned int x = 0; x < Maze.Width; x++)
        {
            // 현재 위치에 맞는 모양 찍어주기
            if (InPlayer.GetPosition().X == x && InPlayer.GetPosition().Y == y)
            {
                printf(ShapePlayer);    //printf("P ");와 같음                
            }
            else if (GetMazeData(x, y) == MazeWall)
            {
                printf(ShapeWall);
            }
            else if (GetMazeData(x, y) == MazePath)
            {
                printf(ShapePath);
            }
            else if (GetMazeData(x, y) == MazeStart)
            {
                printf(ShapeStart);
            }
            else if (GetMazeData(x, y) == MazeEnd)
            {
                printf(ShapeEnd);
            }
        }
        printf("\n");   // 줄바꿈 추가
    }
}

void PrintPlayerState(Player& InPlayer)
{
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  HP : [%4d] / [%4d]\t\tMoney : %6d  │\n", InPlayer.GetHealth(), InPlayer.GetHealthMax(), InPlayer.GetMoney());
    printf("└───────────────────────────────────────────────┘\n");
}

bool IsGoal(Player& InPlayer)
{
    return GetMazeData(InPlayer.GetPosition().X, InPlayer.GetPosition().Y) == MazeEnd;
}

int PrintAvailableMoves(Player& InPlayer)
{
    int Flags = DirNone;

    // w(↑) s(↓) a(←) d(→)
    if (!IsWall(InPlayer.GetPosition().X, InPlayer.GetPosition().Y - 1))
    {
        printf("w(↑) ");
        Flags |= DirUp;
    }
    if (!IsWall(InPlayer.GetPosition().X, InPlayer.GetPosition().Y + 1))
    {
        printf("s(↓) ");
        Flags |= DirDown;
    }
    if (!IsWall(InPlayer.GetPosition().X - 1, InPlayer.GetPosition().Y))
    {
        printf("a(←) ");
        Flags |= DirLeft;
    }
    if (!IsWall(InPlayer.GetPosition().X + 1, InPlayer.GetPosition().Y))
    {
        printf("d(→) ");
        Flags |= DirRight;
    }
    printf("\n");

    return Flags;
}

bool IsWall(int X, int Y)
{
    return (
        X < 0 || X >= static_cast<int>(Maze.Width)
        || Y < 0 || Y >= static_cast<int>(Maze.Height)
        || GetMazeData(X, Y) == MazeWall);
}

MoveDirection GetMoveInput(Player& InPlayer)
{
    printf("이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽):\n");
    int AvailableFlags = PrintAvailableMoves(InPlayer);

    MoveDirection Result = DirNone;
    char Input = 0;
    while (true)
    {
        printf("방향 입력 : ");
        std::cin >> Input;

        if ((Input == 'w' || Input == 'W') && (AvailableFlags & DirUp))
        {
            Result = DirUp;
            break;
        }
        if ((Input == 's' || Input == 'S') && (AvailableFlags & DirDown))
        {
            Result = DirDown;
            break;
        }
        if ((Input == 'a' || Input == 'A') && (AvailableFlags & DirLeft))
        {
            Result = DirLeft;
            break;
        }
        if ((Input == 'd' || Input == 'D') && (AvailableFlags & DirRight))
        {
            Result = DirRight;
            break;
        }


        printf("잘못된 입력입니다. 이동 가능한 방향 중에서 선택하세요.\n");
    }

    return Result;
}


RandomIncounterType RandomIncounter()
{
    RandomIncounterType Result = RI_None;
    float Rate = GetRandom();
    if (Rate < BattleRate)
    {
        Result = RI_Battle;     // 0.0 ~ 0.1 사이다.
    }
    else if (Rate < (BattleRate + HealRate))
    {
        Result = RI_Heal;       // 0.1 ~ 0.2 사이다.
    }
    else if (Rate < (BattleRate + HealRate + TresureRate))
    {
        Result = RI_Treasure;   // 0.2 ~ 0.3 사이다.
    }
    return  Result;
}

bool Battle(Player& InPlayer)
{
    // 랜덤으로　몬스터 생성
    enum MonsterType
    {
        SlimeType = 0,
        OrcType,
        SkeletonType,
        NUM_OF_MONSTER_TYPE
    };

    MonsterType Type = static_cast<MonsterType>((GetRandomRange(0, NUM_OF_MONSTER_TYPE - 1)));
    Monster* Monster = nullptr;
    switch (Type)
    {
        case SlimeType:
        {
            Monster = new Slime();
            break;
        }

        case OrcType:
        {
            Monster = new Orc();
            break;
        }

        case SkeletonType:
        {
            Monster = new Skeleton();
            break;
        }
    }


    printf("[%s]이 나타났다!! 전투 시작!\n", Monster->GetName().c_str());

    int Turn = 1;
    while (InPlayer.IsAlive() && Monster->IsAlive())
    {
        // 전투 턴 진행
        printf("------------턴 %d------------\n", Turn);
        printf("| Player : %3d  Enemy : %3d |\n", InPlayer.GetHealth(), Monster->GetHealth());
        printf("-----------------------------\n");
       
        printf("당신의 공격 : %d의 데미지를 주었다.\n", InPlayer.ApplyDamage(*Monster));
        
        if (Monster->IsAlive())
        {
            printf("적의 공격 : %d의 데미지를 받았다.\n", Monster->ApplyDamage(InPlayer));
        }
        
        // 턴 카운트 증가
        Turn++;
    }

    // 몬스터 메모리 해제
    delete Monster;
    Monster = nullptr;

    return InPlayer.IsAlive();    // 플레이어의 살아있으면 플레이어가 이긴것
}

void Heal(Player& InPlayer)
{
    const int HealMin = 10;
    const int HealMax = 30;

    int HealAmount = GetRandomRange(HealMin, HealMax);
    printf("회복의 샘을 발견했습니다.\n[%d]만큼의 체력을 회복합니다.\n", HealAmount);
    InPlayer.SetHealth(InPlayer.GetHealth() + HealAmount);   // 랜덤하게 회복
    if (InPlayer.GetHealth() > InPlayer.GetHealthMax())
    {
        InPlayer.SetHealth(InPlayer.GetHealthMax());   // 최대치까지만 회복
    }
}

void Treasure(Player& InPlayer)
{
    const int TreasureMin = 100;
    const int TreasureMax = 500;

    int TreasureAmount = GetRandomRange(TreasureMin, TreasureMax);
    printf("보물을 발견했습니다.\n[%d]만큼의 돈을 획득합니다.\n", TreasureAmount);
    InPlayer.SetMoney(InPlayer.GetMoney() + TreasureAmount);
}

int GetSum(int Number)
{
    int Sum = 0;
    while (Number > 0)
    {
        Sum += Number % 10;     // 1/10로 나눈 나머지는 따로 저장하기
        Number /= 10;           // 계속 1/10로 나누기
    }
    return Sum;
}

int GetSum(const char* NumberString)
{
    int Size = 0;
    while (NumberString[Size] != '\0')
    {
        Size++;
    }
    //const char* p = NumberString;
    //while (*p != '\0')
    //{
    //    p++;
    //    Size++;
    //}

    int Sum = 0;
    for (int i = 0; i < Size; i++)
    {
        if (NumberString[i] >= '0' && NumberString[i] <= '9')
        {
            Sum += NumberString[i] - '0';
        }
        else
        {
            Sum = -1;
            break;
        }

    }

    return Sum;
}

MazeTile GetMazeData(int X, int Y)
{
    return (MazeTile)(Maze.Data[X + Maze.Width * Y]);
}

std::string ReadFile(const std::string& Path)
{
    std::ifstream InputFile(Path);	// 입력용 파일스트림 만들기
    if (InputFile.is_open())
    {
        std::string FileTexts(
            (std::istreambuf_iterator<char>(InputFile)),
            std::istreambuf_iterator<char>()
        );
        //printf("파일 내용 : \n%s\n", FileTexts.c_str());
        InputFile.close();
        return FileTexts;
    }
    else
    {
        // 파일이 없거나 다른 이유로 열리지 않았다.
        printf("파일을 열 수 없습니다.\n");
    }

    //return "";  // 전통적인 방식
    return {};
}

MazeData ParseMaze(const std::string& StringData)
{
    if (StringData.empty())
    {
        return MazeData();  // 입력 데이터 없으면 그냥 종료
    }

    size_t FirstLinePosition = StringData.find('\n');      // 첫번째 엔터 찾기
    if (FirstLinePosition == std::string::npos)
    {
        printf("ERROR - 첫번째 줄을 찾을 수 없습니다!!!\n");
        return MazeData();
    }
    std::string FirstLine = StringData.substr(0, FirstLinePosition);    // 첫번째 엔터 위치 이용해서 첫줄 만들기
    size_t CommaPosition = FirstLine.find(',');
    if (CommaPosition == std::string::npos)
    {
        printf("ERROR - 콤마(,)를 찾을 수 없습니다!!!\n");
        return MazeData();
    }
    // 첫 줄 데이터로 가로 세로 크기 가져오기
    unsigned int Width = std::stoi(FirstLine.substr(0, CommaPosition)); // 처음 ~ 콤마앞까지
    unsigned int Height = std::stoi(FirstLine.substr(CommaPosition + 1)); // 콤마다음 ~ 끝까지

    // 동적 할당으로 배열 만들기
    int* MazeArray = new int[Width * Height];

    // 맵 데이터 파싱 시작 지점 설정
    size_t CurrentPosition = FirstLinePosition + 1; // 첫줄 다음 위치
    unsigned int X = 0;
    unsigned int Y = 0;
    while (CurrentPosition < StringData.length() && Y < Height)
    {
        size_t NextComma = StringData.find(',', CurrentPosition);       // 다음 콤마 위치
        size_t NextNewLine = StringData.find('\n', CurrentPosition);    // 다음 뉴라인 위치

        size_t TokenEndPosition = std::string::npos;
        bool IsLineEnd = false;

        if (NextComma < NextNewLine)
        {
            TokenEndPosition = NextComma;   // 콤마까지가 하나의 숫자다
        }
        else
        {
            TokenEndPosition = NextNewLine; // 줄의 마지막 숫자다
            IsLineEnd = true;
        }

        if (TokenEndPosition == std::string::npos)  // 데이터 마지막이다.
        {
            TokenEndPosition = StringData.length();
            IsLineEnd = true;
        }

        // 값부분만 잘라내기
        std::string ValueString = StringData.substr(CurrentPosition, TokenEndPosition - CurrentPosition);
        if (!ValueString.empty())
        {
            int Index = X + Y * Width;                      // X와 Y로 인덱스 계산해서
            *(MazeArray + Index) = std::stoi(ValueString);  // 데이터 설정
            X++;    // X 증가
        }
        else
        {
            printf("ERROR - 값을 확인 할 수 없습니다.\n");
        }

        CurrentPosition = TokenEndPosition + 1; // 현재 위치를 방금 처리한 토큰 다음 위치로 변경

        if (IsLineEnd)  // 줄이 끝났으면
        {
            Y++;        // Y 증가시키고
            X = 0;      // X 0으로 초기화
        }
    }

    return MazeData(MazeArray, Width, Height);
}

void CleanupMazeData(MazeData* InMazeData)
{
    // 명시적으로 MazeData를 리셋
    if (InMazeData->Data)
    {
        delete[] InMazeData->Data;
        InMazeData->Data = nullptr;
    }
    InMazeData->Width = 0;
    InMazeData->Height = 0;
}

bool IsValidMazeData(MazeData* InMazeData)
{
    // sizeof(배열)/sizeof(배열첫번째) : 동적할당은 안됨

    return (InMazeData != nullptr) && (InMazeData->Data != nullptr);
}

