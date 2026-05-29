#pragma once

struct Position
{
	int X = 0;
	int Y = 0;

	Position() = default;
	Position(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
	}
	Position operator+(const Position& InOther) const	// 이 const는 맴버를 수정하지 않는다.(읽기 전용이다.)
	{
		//	Health = 20; // const 때문에 안된다.

		Position Result;
		Result.X = this->X + InOther.X;	//
		Result.Y = this->Y + InOther.Y;

		return Result;
	}

	Position operator-(const Position& InOther) const
	{
		Position Result;
		Result.X = this->X - InOther.X;
		Result.Y = this->Y - InOther.Y;
		return Result;
	}
};