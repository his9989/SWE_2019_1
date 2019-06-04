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
	// 생성자와 소멸자는 사용되지 않습니다.
	TimerController();
	~TimerController();
	void checkToDeleteTicket(int, int, int, int, int, MemberManagement*);
};