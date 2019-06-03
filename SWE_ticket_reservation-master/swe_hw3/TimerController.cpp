#include "stdafx.h"
#include "TimerController.h"
#include "Timer.h"
#include "memberManagement.h"

TimerController::TimerController() {}
TimerController::~TimerController() {}

void TimerController::checkToDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	Timer timer;
	timer.checkDeleteTicket(year, month, day, hour, minute, mm);
}