#pragma once
#include "Calculator.h"
#include "BinarySearchTree.h"
#include <set>
#include <map>

class Day0610
{
public:
	void TestMain();

	void TestTemplateClass();

	void TestTree();
	void TestSet();

	void PrintSet(const std::set<int>& InTarget);

	void TestMap();
};


struct SetTestData
{
	int a = 0;
	float b = 0;

	SetTestData(int InA, float InB) : a(InA), b(InB) {};

	bool operator<(const SetTestData& InOther)const
	{
		return a < InOther.a;
	}
};

enum class CharacterType
{
	Warrior,
	Mage,
	Cheif
};

struct CharacterData
{
	int Level;
	int Hp;
	int Exp;
};



// 트리
// - 특징
//   - 부모-자식 관계를 가지는 계층적 구조를 나타내는 자료구조
//   - 하나의 Root(뿌리)에서 시작하여 가지가 뻗어나가는 형태
//   - 순환이 없는 그래프의 한 종류
//   - 대표적인 비선형 자료구조
//
// - 장점
//   - 계층적인 데이터를 표현하기에 최적화 되어 있다.
//   - 탐색과 정렬에 매우 효율적인 성능을 보인다. (이진 탐색 트리 계열)
//   - 배열과 리스트의 장점을 둘 다 가지고 있다. (탐색이 빠르면서 삽입 삭제도 빠르고 크기도 동적이다)
//
// - 단점
//   - 구조가 복잡하고 구현이 어려울 수 있다.
//   - 데이터를 추가/삭제하는 과정이 복잡할 수 있다. (균형을 맞춰야 할 때)
//
// - 트리의 순회
//   - 트리의 모든 노드를 한번씩 방문하는 방법
//   - 깊이 우선 탐색 : 일단 아래쪽으로 가는 것을 우선. 이쪽을 많이 사용.
//     - 전위 순회 : 루트->왼쪽->오른쪽
//     - 중위 순회 : 왼쪽->루트->오른쪽
//     - 후위 순회 : 왼쪽->오른쪽->루트
//   - 너비 우선 탐색 : 일단 옆으로 가는 것을 우선. 레벨 순서대로 탐색.

// set (집합)
//	- 자동정렬 , 중복 안됨, 빠른 탐색(레드 - 블랙트리 알고리즘 O(LogN))
//	- 사용처
//		- 데이터의 유일성, 정렬, 빠른 검색이 필요할 때 유용

// map
//	- Key와 Value를 쌍으로 묶어 저장, 키는 중복 금지, 자동 정렬, 빠른 탐색
//	- 사용처
//		- 데이터에 중복이 없는 키 값이 설정되어 있고 필요할 때 빠르게 찾아야 하는 경우 유용
//		- 리소스 관리자, 데이터 드리븐, 다국어 지원 등

// unordered_map
//	- Key와 Value를 쌍으로 묶어서 저장, 키는 중복 금지, 빠른 탐색 ( 해시 테이블 O(1) )
//	- 사용처
//		- map을 써야 하는데 정렬이 필요없는 경우(무조건)
//		- 리소스 관리자, 데이터 드리븐, 다국어 지원 등
// 
// 간단실습
// 1. 템플릿을 이용한 계산기 클래스 만들기
//	- Add, Sub, Multiple, Divide
//	- int * int, float * int, int * float, float * float 가능해야함
// 2. Bitflag용 비트 연산자 추가하기
//	- &, |=, &=, 
