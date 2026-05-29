#pragma once
#include "MazeCommon.h"
#include "Position.h"

struct Player
{
    /*int X = InvalidPosition;
    int Y = InvalidPosition;*/
    Position Pos = Position(InvalidPosition, InvalidPosition);
    int Health = InitHealth;
    int MaxHealth = InitHealth;
    int AttackPowerMin = 5;
    int AttackPowerMax = 15;
    int Money = InitMoney;
};