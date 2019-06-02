#include "stdafx.h"
#include "Timer.h"
#include "Ticket.h"

Timer::Timer(){}
Timer::~Timer(){}

void Timer::checkToDeleteTicket(int year, int month, int day, int hour, int minute) {
	// Timer안에 언제든 가져다 쓸수 있도록 얘네를 저장해야된다.
	// Ticket은 굳이 이걸 매개변수로 던지지 않고, 티켓쪽에서 타이머에 접근해서 가져다 써야된다.
	Ticket ticket;
	ticket.deleteTicket(year, month, day, hour, minute);
}

int Timer::getDate() {
	return this->year, this->month, this->day, this->hour, this->minute;
}