#pragma once

void DayCaculate();

bool IsLeap(int InYear);
int GetTotalDay(int InYear, int InMonth, int InDay);
const char* GetDayOfWeek(int InYear, int InMonth, int InDay);