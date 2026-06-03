#pragma once
#include <string>

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

/// <summary>
/// Actor 클래스
/// Player, Monster 등의 부모
/// </summary>
class Actor
{
public:
	Actor();
    Actor(Position InPos, std::string InName, int InHealth, int InHealthMax, int InAttackPowerMin, int InAttackPowerMax);
    virtual ~Actor();

    inline Position GetPosition() { return Pos; }
    inline void SetPosition(const Position InPos)
    {
        Pos = InPos;
    }
    inline void SetPosition(const int InX, const int InY) 
    { 
        Pos.X = InX;
        Pos.Y = InY;
    }

    inline std::string GetName() { return Name; }

    inline int GetHealth() { return Health; }
    inline void SetHealth(const int InHealth) { Health = InHealth; }

    inline int GetHealthMax() { return HealthMax; }
    inline void SetHealthMax(const int InHealthMax) { HealthMax = InHealthMax; }

    inline int GetAttackPowerMin() { return AttackPowerMin; }
    inline void SetAttackPowerMin(const int InAttackPowerMin) { AttackPowerMin = InAttackPowerMin; }

    inline int GetAttackPowerMax() { return AttackPowerMax; }
    inline void SetAttackPowerMax(const int InAttackPowerMax) { AttackPowerMax = InAttackPowerMax; }

    
	virtual int ApplyDamage(Actor& InActor);
	virtual int TakeDamage(int Damage);


protected:
    Position Pos;
	std::string Name;
	int Health;
    int HealthMax;
	int AttackPowerMin;
	int AttackPowerMax;


private:

};

