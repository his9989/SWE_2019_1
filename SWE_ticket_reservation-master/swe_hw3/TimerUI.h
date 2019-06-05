#pragma once
#include "stdafx.h"
#include "memberManagement.h"

class TimerUI {
public:
	// 생성자와 소멸자는 사용되지 않습니다.
	TimerUI();
	~TimerUI();
	// 시간 데이터(string)를 파싱하고 int타입으로 형변환
	void checkTicket(string inputData, MemberManagement *);
};