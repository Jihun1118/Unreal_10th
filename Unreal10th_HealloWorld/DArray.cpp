#include "DArray.h"
#include <iostream>


DArray::DArray()
{
		Reserve(4);	
}

void DArray::Reserve(int InNumber)
{
	if (InNumber <= Capacity)
	{
		return;
	}
	else 
	{
		int* NewData = new int[InNumber];
		for (int i = 0; i < Size; i++)
		{
			NewData[i] = Data[i];
		}
		delete[] Data;

		Data = NewData;
		Capacity = InNumber;
	}
}

void DArray::PushBack(int InNumber)
{

	if (Size < Capacity)
	{
		Data[Size] = InNumber;
		Size++;
	}
	else if (Size >= Capacity)
	{
		Reserve(Size * 2);
		Data[Size] = InNumber;
		Size++;
	} 
}

void DArray::PopBack()
{

	if (Size == 0)
	{
		return;
	}
	Size--;
}

void DArray::Print()
{
	printf("Capacity : %d\n", Capacity);
	printf("Size : %d\n", Size);
	for (int i = 0; i < Size; i++)
	{
		printf("%d\n", Data[i]);
	}
	printf("\n\n");
}
