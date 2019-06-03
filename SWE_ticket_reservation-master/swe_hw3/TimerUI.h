#pragma once
#include "stdafx.h"
#include "memberManagement.h"
class TimerUI {
public:
	TimerUI();
	~TimerUI();
	void checkTicket(string inputData, MemberManagement *);
};