#include "Weekend0529_1.h"
#include <iostream>

using namespace std;


const char* Week[7] = { "월요일", "화요일", "수요일", "목요일", "금요일", "토요일","일요일" };

//윤년 확인 함수
bool IsLeap(int InYear)
{
	return (InYear % 4 == 0 && InYear % 100 != 0) || (InYear % 400 == 0);
}

// 총 몇일이 걸리는 지 리턴하는 함수
int GetTotalDay(int InYear, int InMonth, int InDay)
{
	const int DaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int Days = 0;

	for (int Y = 1; Y < InYear; Y++)
	{
		Days += IsLeap(Y) ? 366 : 365;
	}

	for (int M = 1; M < InMonth; M++)
	{
		if (M == 2 && IsLeap(InYear))
		{
			Days += 29;
		}

		else
		{
			Days += DaysInMonth[M - 1];
		}
	}

	Days += (InDay - 1);
	return Days;
}

const char* GetDayOfWeek(int InYear, int InMonth, int InDay)
{
	int Days = GetTotalDay(InYear, InMonth, InDay);
	return Week[Days % 7];
}

void DayCaculate()
{	
	int Year, Month, Day;
	printf("날짜를 입력하세요 (예 : 2026 05 30) : ");
	std::cin >> Year >> Month >> Day;
	printf("%d년 %d월 %d일은 [%s]입니다.\n", Year, Month, Day, GetDayOfWeek(Year, Month, Day));
	//요일은 7개가 반복된다. ( %7 사용)
	//1년 1월 1일에서 몇일이 지났는 지 확인해야함.
	// 윤년에 대한 처리가 필요

	//
	// 내가 작성한 코드
	//int Year = 0;
	//int Month = 0;
	//int MonthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//int Day = 0;
	//int TotalDay = 0;
	//int LeapYear = 0;
	//printf("현재 날짜(년,월,일)를 입력하세요. \n");
	//cin >> Year >> Month >> Day;
	//LeapYear = (Year - 1) / 4 - (Year - 1) / 100 + (Year - 1) / 400;
	//TotalDay = (Year - 1 - LeapYear) * 365 + LeapYear * 366; //년도 day로 환산
	//for (int i = 1; i < Month; i++)		//1월부터 11월까지만 돌아야함 12월은 day
	//{
	//	TotalDay += MonthDay[i - 1];
	//}
	//if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)	//윤년 계산
	//{
	//	if (Month > 2)	//윤년이면서 2월이 지났다면 day +1
	//	{
	//		TotalDay += 1;
	//	}
	//}
	//TotalDay += Day - 1;	//day는 1일부터 시작하므로 -1
	//printf("1년 1월 1일로부터 %d일이 지났습니다. \n", TotalDay);
	//
	//	if (TotalDay % 7 == 0)
	//	{
	//		printf("오늘은 월요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 1)
	//	{
	//		printf("오늘은 화요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 2)
	//	{
	//		printf("오늘은 수요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 3)
	//	{
	//		printf("오늘은 목요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 4)
	//	{
	//		printf("오늘은 금요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 5)
	//	{
	//		printf("오늘은 토요일입니다. \n");
	//	}
	//	else if (TotalDay % 7 == 6)
	//	{
	//		printf("오늘은 일요일입니다. \n");
	//	}
	//
}