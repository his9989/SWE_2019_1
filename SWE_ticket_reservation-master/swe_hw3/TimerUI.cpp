#include "stdafx.h"
#include<cstdio>
#include "TimerUI.h"
#include "TimerController.h"
#include "memberManagement.h"


TimerUI::TimerUI() {}
TimerUI::~TimerUI() {}

void TimerUI::checkTicket(string inputData, MemberManagement *mm) {
	// inputData를 자료형에 맞게 변환
	string year = inputData.substr(0, 4);
	string month = inputData.substr(5, 7);
	string day = inputData.substr(8, 10);
	string hour = inputData.substr(11, 13);
	string minute = inputData.substr(14, 17);
	TimerController timerC;
	// TimerController (Control 클래스)의 checkToDeleteTicket 함수 호출
	// 매개변수로 현재시간의 연, 월, 일, 시간, 분, MemberManagement의 포인터 객체를 전달.
	timerC.checkToDeleteTicket(stoi(year), stoi(month), stoi(day), stoi(hour), stoi(minute), mm);//여기는 매개변수 넘기지 말기
}