#pragma once
#include "Enemy.h"
class Slime : public MazeEnemy
{
public:
	Slime()
		: MazeEnemy(5, 5, 2, 5, "슬라임", 30)
	{
	}
};

