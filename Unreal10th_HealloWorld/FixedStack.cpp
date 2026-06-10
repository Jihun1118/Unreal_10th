#include "FixedStack.h"
#include <iostream>

void FixedStack::Push(int InValue)
{
	if (!IsFull())
	{
		TopIndex++;
		Data[TopIndex] = InValue;
	}
	else
		return;
}

int FixedStack::Pop()
{
	if (!IsEmpty())
	{
		int BData = Data[TopIndex];
		TopIndex--;
		return BData;
	}
	else
	{
		printf("유효하지 않은 인덱스입니다.");
		return Empty;
	}
}

int FixedStack::Top() const
{
	if (!IsEmpty())
	{
		return Data[TopIndex];
	}
	else
	{
		printf("유효하지 않은 인덱스입니다.");
		return Empty;
	}
}

bool FixedStack::IsFull() const
{
	return TopIndex + 1 >= StackCapacity;
}

bool FixedStack::IsEmpty() const
{
	return TopIndex <= Empty;
}

int FixedStack::GetSize() const
{
	return TopIndex + 1;
}

void FixedStack::ReverseString()
{
	for (int i = TopIndex; i >= 0; i--)
	{
		printf("%c", Data[i]);
	}
}
