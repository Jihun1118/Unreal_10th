#pragma once
class DArray
{
		// std::vector 비슷하게 구현
		// Integer 저장
		// - Reserve, PushBack, PopBack, Print 구현
		// (Capacity 설정), (뒤에 추가) , (뒤에 제거), (내용 출력) 
		// - Reallocate(PushBack으로 Capacity가 넘칠 때 처리하는 함수)


public:
	int& operator[](size_t Index)
	{
		return Data[Index];
	}
	DArray();
	void Reserve(int InNumber);
	void PushBack(int InNumber);
	void PopBack();
	void Print();

private:
	int* Data;
	size_t Size = 0;
	size_t Capacity = 0;

};

