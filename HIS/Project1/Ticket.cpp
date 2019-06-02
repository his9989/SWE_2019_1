#include "stdafx.h"
#include"Ticket.h"
#include"Timer.h"
using namespace std;

Ticket::Ticket(){}
Ticket::~Ticket(){}

// 임시
struct TicketData {
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

void compare(TicketData, int, int, int, int, int);

void Ticket::deleteTicket(int year, int month, int day, int hour, int minute) {
	// 멤버 콜렉터와 홈팀 콜렉터를 불러오는 호출부 구현 필요
	// 현재는 임시로 티켓데이터라는 구조체 사용
	// ★멤버 콜렉터와 홈팀 콜렉터 방문해야됨
	TicketData t1, t2;
	t1.year = 2018, t1.month = 01, t1.day = 01, t1.hour = 11, t1.minute = 00;
	t2.year = 2019, t2.month = 05, t2.day = 11, t2.hour = 10, t2.minute = 00;
	for (int i = 0; i < 1; i++) { // member 콜렉터 내에 이터레이터로 방문하는 과정
		for (int j = 0; j < 1; j++) { // member 원소 하나의 티켓 콜랙터 내에 이터레이터로 방문하는 과정
			compare(t1, year, month, day, hour, minute);
		}
	}
	for (int i = 0; i < 1; i++) { // 홈팀 콜렉터 내에 이터레이터로 방문하는 과정
		for (int j = 0; j < 1; j++) { // 홈팀 원소 하나의 티켓 콜랙터 내에 이터레이터로 방문하는 과정
			compare(t2, year, month, day, hour, minute);
		}
	}
}

// ★티켓 삭제부 구현 필요
void compare(TicketData s, int year, int month, int day, int hour, int minute) {
	cout << s.year << " " << s.month << " " << s.day << " " << s.hour << " " << s.minute << endl;
	if (year > s.year + 1) {
		cout << "delete " << endl;
	}
	else if (year == s.year+ 1) {
		if (month > s.month) {
			cout << "delete : " << endl;
		}
		else if (month == s.month) {
			if (day > s.day) {
				cout << "delete : " << endl;
			}
			else if (day == s.day) {
				if (hour > s.hour) {
					cout << "delete : " << endl;
				}
				else if (hour == s.hour) {
					if (minute > s.minute) {
						cout << "delete : " << endl;
					}
				}
			}
		}
	}
	cout << endl;
}