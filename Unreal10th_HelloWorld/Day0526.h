#pragma once

void Day0526();
void Day0526_PointerParameter(int* Data, int Size);

void Day0526_Practice1(int* a, int* b);
int Day0526_Practice2(int* Array, int Size);
void Day0526_Practice3(int* Array, int Size);
void Day0526_PrintArray(int* Array, int Size);

void MazeVer2();
void PrintMaze2(int** Maze, int Rows, int Cols, int PlayerPosX, int PlayerPosY);
int Battle(int* PlayerHp, int* EnemyHp);
void HealHp(int* PlayerHp, const int MaxHp);