#pragma once

template <typename T>
struct TemplateListNode
{
	T Data{};			// 데이터 부분. 이 노드가 관리할 실제 데이터
	TemplateListNode<T>* Next = nullptr;	// 링크 부분. 다음 노드의 주소(null이면 이 노드는 Tail)

	TemplateListNode(const T& InData)
		: Data(InData)
	{
	}
};


template <typename T>
class LinkedListTemplate
{
public:
	LinkedListTemplate<T>() = default;
	~LinkedListTemplate<T>();

	void Add(const T& InData);						// 리스트의 마지막에 데이터를 추가하는 함수

	void InsertAt(const T& InData, size_t InPosition);	// 리스트의 중간에 데이터를 추가하는 함수


	void Remove(const T& InData);					// 특정 데이터를 가지는 노드를 제거하는 함수

	void RemoveAt(size_t InPosition);				// 특정 번째의 노드를 제거하는 함수

	TemplateListNode<T>* Search(const T& InData) const;			// 특정 데이터가 있는지 확인하는 함수. 리턴이 null이면 없다. null이 아니면 찾은 노드


	void Clear();								// 모든 노드를 제거하는 함수

	void PrintList() const;						// 리스트의 현재 상황을 출력하는 함수

private:
	TemplateListNode<T>* Head = nullptr;	// 시작 노드(null이면 리스트가 비어있다.)
	TemplateListNode<T>* Tail = nullptr;	// 마지막 노드
	int Size = 0;	// 해드부터 이어지는 전체 노드의 개수
};




template <typename T>
LinkedListTemplate<T>::~LinkedListTemplate()
{
	Clear();
}

template <typename T>
void LinkedListTemplate<T>::Add(const T& InData)
{
	TemplateListNode<T>* NewNode = new TemplateListNode<T>(InData);

	if (Head == nullptr)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		Tail->Next = NewNode;
		Tail = NewNode;
	}

	Size++;
}

template <typename T> void LinkedListTemplate<T>::InsertAt(const T& InData, size_t InPosition)
{
	if (InPosition > Size)
	{
		InPosition = Size;
	}
	if (InPosition == Size)
	{
		Add(InData);    // 어차피 마지막에 추가할거면 Tail을 활용하는게 빠르다.
		return;
	}
	// InData가 들어간 노드를 만든다
	TemplateListNode<T>* NewNode = new TemplateListNode<T>(InData);
	if (InPosition == 0)
	{
		NewNode->Next = Head;
		Head = NewNode;
	}
	else
	{
		// 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
		TemplateListNode<T>* PrevNode = Head;
		TemplateListNode<T>* Current = Head;
		for (int i = 0; i < InPosition; i++)
		{
			PrevNode = Current;
			Current = Current->Next;
		}
		PrevNode->Next = NewNode;   // 포지션 위치에 있는 노드의 앞노드의 Next 주소를 새로 만든 노드로 설정
		NewNode->Next = Current;    // 새 노드의 다음 주소를 포지션 위치에 있는 노드의 주소로 설정
	}
	Size++;
}

template <typename T> void LinkedListTemplate<T>::Remove(const T& InData)
{
	if (Head == nullptr)
		return;

	// InData를 가진 노드가 있는지 Head부터 찾는다.
	TemplateListNode<T>* NodeToDelete = nullptr;
	TemplateListNode<T>* PrevNode = nullptr;

	if (Head->Data == InData)
	{
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;
		}
	}
	else
	{
		PrevNode = Head;
		while (PrevNode->Next != nullptr && PrevNode->Next->Data != InData)
		{
			// 찾는 데이터를 가진 노드의 앞노드 찾기
			PrevNode = PrevNode->Next;
		}

		if (PrevNode->Next != nullptr)
		{
			// 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next에 저장된 주소로 변경한다.
			NodeToDelete = PrevNode->Next;
			PrevNode->Next = NodeToDelete->Next;
			if (NodeToDelete == Tail)
			{
				Tail = PrevNode;
			}
		}
	}

	if (NodeToDelete != nullptr)
	{
		// 찾은 노드를 delete
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;
	}
	else
	{
		printf("오류 : %d 값을 가진 노드가 없습니다.\n", InData);
	}
}


template <typename T> void LinkedListTemplate<T>::RemoveAt(size_t InPosition)
{
	if (InPosition >= Size)
	{
		printf("오류 : %d 위치는 리스트의 범위를 벗어납니다.(현재 크기:%zu))\n", InPosition, Size);
		return;     //위치가 없는 경우는 그냥 종료
	}

	TemplateListNode<T>* NodeToDelete = nullptr;
	if (InPosition == 0)
	{
		// 특수 처리(맨 앞이다)
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;
		}
	}
	else
	{
		// 위치 찾기
		TemplateListNode<T>* PrevNode = Head;
		int TargetIndex = InPosition - 1;       // 지울 노드의 앞쪽노드(PrevNode)까지 가기 위해서
		for (int i = 0; i < TargetIndex; i++)
		{
			PrevNode = PrevNode->Next;
		}
		NodeToDelete = PrevNode->Next;
		PrevNode->Next = NodeToDelete->Next;    // 찾은 노드 앞 노드의 Next를 찾은 노드의 Next로 변경
		if (NodeToDelete == Tail)
		{
			//PrevNode->Next = nullptr;
			Tail = PrevNode;
			Tail->Next = nullptr;
		}
	}
	// 찾은 노드 delete
	delete NodeToDelete;
	NodeToDelete = nullptr;
	Size--;
}


template <typename T> TemplateListNode<T>* LinkedListTemplate<T>::Search(const T& InData) const
{
	// InData와 같은 값을 가지는 노드 찾기
	TemplateListNode<T>* Current = Head;
	while (Current != nullptr)
	{
		if (Current->Data == InData)
		{
			break;
		}
		Current = Current->Next;
	}
	return Current;
}

template <typename T> void LinkedListTemplate<T>::Clear()
{
	// 동적할당이 된 노드를 모두 제거한다.
	while (Head)
	{
		RemoveAt(0);
	}
}

template <typename T> void LinkedListTemplate<T>::PrintList() const
{
	// 리스트 Head부터 Tail까지 출력하는 함수
	if (Head == nullptr && Size == 0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}

	printf("리스트(크기:%d) : ", Size);
	TemplateListNode<T>* Current = Head;
	while (Current != nullptr)
	{
		printf("%d -> ", Current->Data);
		Current = Current->Next;
	}
	printf("nullptr\n");
}