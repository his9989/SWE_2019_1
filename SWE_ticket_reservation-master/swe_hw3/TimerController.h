#pragma once
#include "stdafx.h"
#include "memberManagement.h"

// Class : TimerController
// Description: 입력받은 연, 월, 일, 시간, 분, MemberManagement 포인터 객체를 Timer에게 전달하는 컨트롤러 클래스
// Created: 2019/06/2 21:00 pm
// Author: 한인수
// mail: his9989@naver.com
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