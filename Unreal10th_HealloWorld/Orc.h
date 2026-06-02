#pragma once
#include "Enemy.h"


class Orc : public MazeEnemy
{
public:
	Orc()
		: MazeEnemy(30, 30, 8, 15, "오크", 200)
	{ }
};