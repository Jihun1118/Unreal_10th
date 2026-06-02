#define _CRT_SECURE_NO_WARNINGS
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
#include "Day0529.h"
#include "Weekend0529_1.h"
#include "Weekend0529_2.h"

using namespace std;

int main()  // 코드의 시작점
{	
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	//Weekend0523_Dungeon();
	//Day0529();

	//DayCaculate();
	Weekend0523_Dungeon();
}
