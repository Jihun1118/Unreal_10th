#pragma once

class Actor
{
public:
	Actor() = default;
	Actor(int InHealth, int InMaxHealth, int InAttackPowerMin, int InAttackPowerMax)
		:	Health(InHealth),
			MaxHealth(InMaxHealth),
			AttackPowerMin(InAttackPowerMin),
			AttackPowerMax(InAttackPowerMax)
	{
	}


	int Health = 0;
	int MaxHealth = 100;
	int AttackPowerMin = 0;
	int AttackPowerMax = 0;

	int ApplyDamage();
	void TakeDamage(int InDamage);


	virtual ~Actor() = default;
	
};


