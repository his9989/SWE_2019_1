#pragma once
#include "stdafx.h"
class Timer {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
public:
	Timer();
	~Timer();
	void checkToDeleteTicket(int, int, int, int, int);
	int getDate();
};