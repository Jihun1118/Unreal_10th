#include <iostream>
#include "Actor.h"
#include "Utils.h"
int Actor::ApplyDamage()
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);

	return Damage;
}

void Actor::TakeDamage(int InDamage)
{
	
    if (Health <= 0)
    {
        return;
    }

    Health -= InDamage;

    if (Health < 0)
    {
        Health = 0;
    }
}
