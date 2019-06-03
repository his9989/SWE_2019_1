#pragma once
#include "stdafx.h"
#include "memberManagement.h"
class TimerController {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
public:
	TimerController();
	~TimerController();
	void checkToDeleteTicket(int, int, int, int, int, MemberManagement*);
};