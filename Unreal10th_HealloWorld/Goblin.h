#pragma once
#include "Enemy.h"
class RandomMazeEnemy : public MazeEnemy
{
public:
	RandomMazeEnemy()
		: MazeEnemy(20, 20, 4, 8, "고블린", 100)
	{
	}
};
