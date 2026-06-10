#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// Unreal10th_HealloWorld.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
//#include <random>
#include "Day0521_2.h"
#include "Practice0521_1.h"
#include "Practice0521_2.h"
#include "Day0522.h"
#include "Weekend0523.h"
#include "Day0526.h"
#include "Day0527.h"
#include "Day0528.h"
#include "Weekend0529_1.h"
#include "Weekend0529_2.h"
#include "LinkedList.h"
#include "DArray.h"
#include "Day0605.h"
#include "Day0609.h"
#include "FixedStack.h"
#include "Day0610.h"
#include "LinkedListTemplate.h"
#include "FixedStackTemplate.h"

using namespace std;

int main()  // 코드의 시작점
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(493);

	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	//Day0609 day0609;
	//day0609.Day0609_Main();

	Day0605 day0605;
	day0605.TestListTemplate();


//	Day0610 day0610;
////	day0610.TestTemplateClass();
//	day0610.TestTree();
//	day0610.TestSet();

	//day0609.Day0609_Main();
	//Day0609 day0609;
	//day0609.Day0609_Main();
	//Weekend0523_Dungeon();
	//Day0529();

	//DayCaculate();
	//eekend0523_Dungeon();
	//Day0605 Day0605;

	//Day0605.TestList();

	//DArray DA;
	//DA.PushBack(10);
	//DA.Print();
	//DA.PushBack(20);
	//DA.Print();
	//DA.PushBack(30);
	//DA.Print();
	//DA.PushBack(40);
	//DA.Print();
	//DA.PushBack(50);
	//DA.Print();

	/*DA.Reserve(3);
	DA.PushBack(10);
	DA.Print();
	DA.PushBack(20);
	DA.Print();
	DA.PushBack(30);
	DA.Print();
	DA.PushBack(40);
	DA.Print();
	DA.PushBack(50);
	DA.Print();
	DA.PopBack();
	DA.Print();
	DA.PopBack();
	DA.Print();*/
	
}
