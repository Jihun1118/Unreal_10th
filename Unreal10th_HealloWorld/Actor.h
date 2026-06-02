#pragma once

class Actor
{
public:
	Actor() = default;

	int AttackPowerMin = 0;
	int AttackPowerMax = 0;

	void ApplyDamage();
	void TakeDamage();
	

};