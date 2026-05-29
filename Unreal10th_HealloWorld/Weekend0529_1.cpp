#include "Weekend0529_1.h"
#include <iostream>

using namespace std;

void DayCaculate()
{
	int Year = 0;
	int Month = 0;
	int MonthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int Day = 0;
	int TotalDay = 0;
	int LeapYear = 0;
	printf("현재 날짜(년,월,일)를 입력하세요. \n");
	cin >> Year >> Month >> Day;
	LeapYear = (Year - 1) / 4 - (Year - 1) / 100 + (Year - 1) / 400;
	TotalDay = (Year - 1 - LeapYear) * 365 + LeapYear * 366; //년도 day로 환산

	for (int i = 1; i < Month; i++)		//1월부터 11월까지만 돌아야함 12월은 day
	{
		TotalDay += MonthDay[i - 1];
	}

	if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)	//윤년 계산
	{
		if (Month > 2)	//윤년이면서 2월이 지났다면 day +1
		{
			TotalDay += 1;
		}
	}

	TotalDay += Day - 1;	//day는 1일부터 시작하므로 -1

	printf("1년 1월 1일로부터 %d일이 지났습니다. \n", TotalDay);

	for (int i = 0; i < 7; i++)
	{
		if (TotalDay % 7 == 0)
		{
			printf("오늘은 월요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 1)
		{
			printf("오늘은 화요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 2)
		{
			printf("오늘은 수요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 3)
		{
			printf("오늘은 목요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 4)
		{
			printf("오늘은 금요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 5)
		{
			printf("오늘은 토요일입니다. \n");
			break;
		}
		else if (TotalDay % 7 == 6)
		{
			printf("오늘은 일요일입니다. \n");
			break;
		}
	}
}