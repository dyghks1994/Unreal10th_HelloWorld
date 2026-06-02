#pragma once
#include <string>
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	virtual ~Monster();

	virtual void Initialize();

protected:
	int Reward;

private:
};


class Slime : public Monster
{
public:
	Slime();
	Slime(Position InPos, std::string InName = "슬라임", int InHealth = 20, int InHealthMax = 20, int InAttackPowerMin = 2, int InAttackPowerMax = 5);
	virtual ~Slime();

	virtual void Initialize() override;
	virtual void ApplyDamage(Actor& InActor) override;
	virtual void TakeDamage(int Damage) override;

protected:

private:
	const int SlimeHealthMax = 20;
	
}



/*
구 struct 버전 코드
struct MazeEnemy
{
	std::string Name = "고블린";
	int Health = 20;
	int AttackPowerMin = 5;
	int AttackPowerMax = 10;
	int Reward = 100;

	MazeEnemy();
	MazeEnemy(const std::string& InName, int InLevel);
		

	// +연산자를 오버로딩 한다.
	// 결과는 MazeEnemy타입으로 나온다.
	// 계산 대상은 나와 InOther다.
	MazeEnemy operator+(const MazeEnemy& InOther) const	// 이 const는 맴버를 수정하지 않는다.(읽기 전용이다.)
	{
		//	Health = 20; // const 때문에 안된다.

		MazeEnemy Result;
		Result.Name = this->Name + InOther.Name;	// this : 자기 자신의 주소
		Result.AttackPowerMin = (AttackPowerMin + InOther.AttackPowerMin) / 2;
		Result.AttackPowerMax = AttackPowerMax + InOther.AttackPowerMax;
		Result.Reward = Reward + InOther.Reward;

		return Result;
	}

	MazeEnemy operator-(const MazeEnemy& InOther) const
	{
		MazeEnemy Result;
		Result.Name = "약화된 " + this->Name;	// this : 자기 자신의 주소
		
		Result.AttackPowerMin = (AttackPowerMin - InOther.AttackPowerMin) / 2;
		if (Result.AttackPowerMin < 1)
		{
			Result.AttackPowerMin = 1;
		}
		
		Result.AttackPowerMax = AttackPowerMax - InOther.AttackPowerMax;
		if (Result.AttackPowerMax < 1)
		{
			Result.AttackPowerMax = 1;
		}

		if (Result.AttackPowerMax < Result.AttackPowerMin)
		{
			Result.AttackPowerMax = Result.AttackPowerMin;
		}

		Result.Reward = Reward - InOther.Reward;

		return Result;
	}

	MazeEnemy operator*(float InOther) const
	{
		MazeEnemy Result;
		Result.Name = this->Name;
		Result.Health = static_cast<int>(this->Health * InOther);
		Result.AttackPowerMin = static_cast<int>(this->AttackPowerMin * InOther);
		Result.AttackPowerMax = static_cast<int>(this->AttackPowerMax * InOther);
		Result.Reward = static_cast<int>(this->Reward * InOther);

		return Result;
	}

	MazeEnemy& operator*=(float InOther) 
	{
		Name = this->Name;
		Health = static_cast<int>(this->Health * InOther);
		AttackPowerMin = static_cast<int>(this->AttackPowerMin * InOther);
		AttackPowerMax = static_cast<int>(this->AttackPowerMax * InOther);
		Reward = static_cast<int>(this->Reward * InOther);

		return *this;
	}

};
*/