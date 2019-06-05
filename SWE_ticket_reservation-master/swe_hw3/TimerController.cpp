#include "stdafx.h"
#include "TimerController.h"
#include "Timer.h"
#include "memberManagement.h"

TimerController::TimerController() {}
TimerController::~TimerController() {}

// Function : void TimerController::checkToDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm)
// Description : 매개변수로 받은 [연, 월, 일, 시간, 분]과 MemberManagement 객체 포인터를 타이머에게 전달한다.
// Parameters : int year, int month, int day, int hour, int minute, MemberManagement *mm
// Return Value : None
// Created: 2019/06/2 21:00 pm
// Author: 한인수
// mail: his9989@naver.com
void TimerController::checkToDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	Timer timer;
	timer.checkDeleteTicket(year, month, day, hour, minute, mm);
}