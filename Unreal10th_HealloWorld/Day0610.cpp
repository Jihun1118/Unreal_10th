#include "Day0610.h"
#include "BitFlag.h"
#include "Calculator.h"
#include <iostream>
#include <set>
void Day0610::TestMain()
{
}

void Day0610::TestTemplateClass()
{
	TestEnumClass Test1 = TestEnumClass::Up;
	TestEnumClass Test2 = TestEnumClass::Down;
	TestEnumClass Test3 = Test1 | Test2;
	//TestEnumClass Test4 = Test1 & Test2;

	Calculator Calc;
	auto Sum = Calc.Add(10, 2.5);
	std::cout << Sum;
	int i = 0;

}

void Day0610::TestTree()
{
	BinarySearchTree bst;
	bst.Insert(30);
	bst.Insert(50);
	bst.Insert(10);
	bst.PrintPreOrder();
}

void Day0610::TestSet()
{
	std::set<int> MySet;	
	MySet.insert(10);
	MySet.insert(50);
	MySet.insert(30);
	MySet.insert(10);		// 이미 저장되어 있기 때문에 삽입 실패
	PrintSet(MySet);

	//MySet.size(); // 크기

	std::set<int>::iterator iter = MySet.find(50);		// 값이 아니라 이터레이터를 리턴한다.
	int findValue = (*iter);

	MySet.erase(30);		//특정 값을 삭제
	PrintSet(MySet);		

	MySet.clear();			// 모두 삭제
	PrintSet(MySet);


	// MySet.empty();		// 비어 있는 지 아닌 지 확인 (bool) 
}

void Day0610::PrintSet(const std::set<int>& InTarget)
{
	printf("Set 출력 : ");
	for (int Element : InTarget)
	{
		printf("%d ", Element);
	}
	printf("\n");
}


void Day0610::TestMap()
{
	std::map<CharacterType, CharacterData> Characters;
	Characters[CharacterType::Warrior] = { 12,150,0 };

	CharacterData& WarriorData = Characters[CharacterType::Warrior];
	WarriorData.Hp = 200;

	CharacterData& Mage = Characters[CharacterType::Mage];
	Mage.Level = 20;

	CharacterData& Bug = Characters[(CharacterType)35];
	int i = 0;

	//std::map<CharacterType, CharacterData>::iterator iter = Characters.find(CharacterType::Cheif);
	auto iter = Characters.find(CharacterType::Cheif);
	if (iter != Characters.end())
	{
		printf("있다.\n");
	}
	else
	{
		printf("없다.\n");
	}

	Characters.insert(std::pair< CharacterType, CharacterData>(CharacterType::Mage, { 12,150,0 }));

	//for (const auto& pair : Characters)
	//{
	//    pair.first;//키
	//    pair.second;//value
	//}
}

