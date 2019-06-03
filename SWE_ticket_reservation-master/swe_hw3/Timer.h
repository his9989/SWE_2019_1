#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"
#include "memberManagement.h"
class Timer {
public:
	Timer();
	~Timer();
	void checkDeleteTicket(int, int, int, int, int, MemberManagement*);
	void compare(int, int, int, int, int, string);
};