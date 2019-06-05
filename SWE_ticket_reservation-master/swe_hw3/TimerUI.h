#pragma once
#include "stdafx.h"
#include "memberManagement.h"

// Class : TimerUI
// Description: 입력받은 현재시간과 MemberManagement 포인터 객체를 TimerController에게 전달하는 바운더리 클래스
// Created: 2019/06/2 21:00 pm
// Author: 한인수
// mail: his9989@naver.com
class TimerUI {
public:
	// 생성자와 소멸자는 사용되지 않습니다.
	TimerUI();
	~TimerUI();
	// 시간 데이터(string)를 파싱하고 int타입으로 형변환
	void checkTicket(string inputData, MemberManagement *);
};