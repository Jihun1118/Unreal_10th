#pragma once
#include "MazeCommon.h"
#include "Actor.h"


class Player : public Actor
{
public:
    Player()
        : Actor(100, 100, 5, 15)
    {}
    Position Pos = Position(InvalidPosition, InvalidPosition);
    //int AttackPowerMin = 5;
    //int AttackPowerMax = 15;

    int Money = InitMoney;
};