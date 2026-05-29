#pragma once
#include "MazeCommon.h"


struct Position
{
    int X = 0;
    int Y = 0;

    Position();
    Position(const int InX, const int InY);

    Position operator+(const Position& InPosition) const
    {
        Position Result;
        Result.X = this->X + InPosition.X;
        Result.Y = this->Y + InPosition.Y;

        return Result;
    }

    Position operator-(const Position& InPosition) const
    {
        Position Result;
        Result.X = this->X - InPosition.X;
        Result.Y = this->Y - InPosition.Y;

        return Result;
    }
};
struct Player
{
    Position Pos;
    //
    //int X = InvalidPosition;
    //int Y = InvalidPosition;
    int Health = InitHealth;
    int MaxHealth = InitHealth;
    int AttackPowerMin = 5;
    int AttackPowerMax = 15;
    int Money = InitMoney;
};


