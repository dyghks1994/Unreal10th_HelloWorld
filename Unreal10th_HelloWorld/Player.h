#pragma once
#include "MazeCommon.h"
#include "Actor.h"

// class 스타일
class Player : public Actor
{
public:
    Player();
    Player(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax);
    virtual ~Player();

    inline int GetMoney() { return Money; }
    inline void SetMoney(const int InMoney) { Money = InMoney; }

    virtual int ApplyDamage(Actor& InActor) override;
    virtual int TakeDamage(int Damage) override;


protected:
    int Money;

private:
};


/*
//구 struch 스타일
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
//*/



