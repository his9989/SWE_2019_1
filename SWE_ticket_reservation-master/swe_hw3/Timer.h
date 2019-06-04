#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"
#include "memberManagement.h"

class Timer {
public:
	Timer();
	~Timer();
	// 티켓의 매치 시간이 현재시간과 비교했을 때, 1년을 초과하면 삭제하기 위한 함수
	void checkDeleteTicket(int, int, int, int, int, MemberManagement*);
	// 티켓의 매치 시간과 현재 시간을 비교하기 위한 함수
	bool compare(int, int, int, int, int, string);
};