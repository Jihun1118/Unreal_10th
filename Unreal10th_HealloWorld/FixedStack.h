#pragma once
// 데이터는 int로 가정, 크기가 정해진 스택이다.

class FixedStack
{
public:
	// 스택에 InValue를 추가

	void Push(int InValue);

	// 스택의 Top 위치에 있는 값을 꺼내기
	int Pop();

	// Top에 있는 값을 확인하는 함수, 꺼내지는 않는다. ( Peek이라고도 함 ) 
	int Top() const;

	// 스택이 가득 찼는 지 확인하는 함수, Stack OverFlow 방지를 위해 사용
	bool IsFull() const;

	// 스택이 비어있는 지 확인하는 함수, Stack UnderFlow 방지를 위해 사용
	bool IsEmpty() const;

	// 스택의 현재 크기를 반환하는 함수 ( 실제 들어와 있는 데이터 개수)
	int GetSize() const;

	void ReverseString();

	inline int* GetData() { return Data; }
private:
	static constexpr int StackCapacity = 10;
	static constexpr int Empty = -1;


	int TopIndex = -1;
	int Data[StackCapacity];
};
