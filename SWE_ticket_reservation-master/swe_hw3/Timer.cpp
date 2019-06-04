#include "stdafx.h"
#include "Timer.h"
#include "memberManagement.h"
#include "member.h"
#include "memberCollection.h"
#include "Ticket.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"

Timer::Timer() {}
Timer::~Timer() {}

// 티켓의 매치 시간이 현재시간과 비교했을 때, 1년을 초과하면 삭제하기 위한 함수
void Timer::checkDeleteTicket(int year, int month, int day, int hour, int minute, MemberManagement *mm) {
	// Membermanagement에서 모든 Seller의 객체 포인터를 vector로 가져옴
	vector<Seller*> sellers = mm->getMembers()->getAllSeller();
	// 가입한 모든 Seller가 저장되어 있는 vector에서 iterator를 이용하여 각각의 Seller 객체 포인터에 접근
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		// 각 Seller 포인터 객체가 등록한 티켓의 객체 포인터를 getTickets()를 이용하여 vector로 가져옴
		vector<Ticket*> temp = (*it)->getRegisteredTickets()->getTickets();
		// 각 Seller의 티켓 vector에서 iterator를 이용하여 각각의 Seller의 티켓 객체 포인터에 접근
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			// 각각의 Seller의 티켓 객체 포인터의 매치 시간을 가져와서 compare를 통해 비교
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				// 1년을 초과하는 경우
				// 등록된 티켓을 관리하는 getRegisteredTickets()의 deleteTicket(Ticket*)를 호출
				(*it)->getRegisteredTickets()->deleteTicket(*itt);
			}
		}
	}

	// Membermanagement에서 모든 Buyer의 객체 포인터를 vector로 가져옴
	vector<Buyer*> buyers = mm->getMembers()->getAllBuyer();
	// 가입한 모든 Buyer가 저장되어 있는 vector에서 iterator를 이용하여 각각의 Buyer 객체 포인터에 접근
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		// 각 Buyer 포인터 객체가 등록한 티켓의 객체 포인터를 getTickets()를 이용하여 vector로 가져옴
		vector<Ticket*> temp = (*it)->getBookedTickets()->getTickets();
		// 각 Buyer의 티켓 vector에서 iterator를 이용하여 각각의 Buyer의 티켓 객체 포인터에 접근
		for (vector<Ticket*>::iterator itt = temp.begin(); itt != temp.end(); itt++) {
			bool check = true;
			// 각각의 Buyer의 티켓 객체 포인터의 매치 시간을 가져와서 compare를 통해 비교
			check = compare(year, month, day, hour, minute, (*itt)->getMatchDate());
			if (check == false) {
				// 1년을 초과하는 경우
				// 등록된 티켓을 관리하는 getBookedTickets()의 deleteTicket(Ticket*)를 호출
				(*it)->getBookedTickets()->deleteTicket(*itt);
			}
		}
	}

	// HomeTeamCollection에서 모든 홈팀의 객체 포인터를 vector로 가져옴
	vector<HomeTeam *> homeTeams = HomeTeamCollection::getInstance()->getHomeTeams();
	// 모든 홈팀이 저장되어 있는 vector에서 iterator를 이용하여 각각의 홈팀 객체 포인터에 접근
	for (int i = 0; i < homeTeams.size(); i++) {
		// 각 홈팀 포인터 객체에 등록된 티켓의 객체 포인터를 getTickets()를 이용하여 vector로 가져옴
		vector<Ticket*> temp = homeTeams[i]->getTicketCollection()->getTickets();
		// 각 홈팀의 티켓 vector에서 iterator를 이용하여 각각의 홈팀의 티켓 객체 포인터에 접근
		for (vector<Ticket*>::iterator it = temp.begin(); it != temp.end(); it++) {
			bool check = true;
			// 각각의 홈팀의 티켓 객체 포인터의 매치 시간을 가져와서 compare를 통해 비교
			check = compare(year, month, day, hour, minute, (*it)->getRegistrationDate());
			if (check == false) {
				// 1년을 초과하는 경우
				// 등록된 티켓을 관리하는 getTicketCollection()의 deleteTicket(Ticket*)를 호출
				homeTeams[i]->getTicketCollection()->deleteTicket(*it);
			}
		}
	}
}

// 티켓의 매치 시간과 현재 시간을 비교하기 위한 함수
bool Timer::compare(int year, int month, int day, int hour, int minute, string MatchDate) {
	int matchYear = stoi(MatchDate.substr(0, 4));
	int matchMonth = stoi(MatchDate.substr(5, 7));
	int matchDay = stoi(MatchDate.substr(8, 10));
	int matchHour = stoi(MatchDate.substr(11, 13));
	int matchMinute = stoi(MatchDate.substr(14, 17));
	if (year > matchYear + 1) {
		return false;
	}
	else if (year == matchYear + 1) {
		if (month > matchMonth) {
			return false;
		}
		else if (month == matchMonth) {
			if (day > matchDay) {
				return false;
			}
			else if (day == matchDay) {
				if (hour > matchHour) {
					return false;
				}
				else if (hour == matchHour) {
					if (minute > matchMinute) {
						return false;
					}
				}
			}
		}
	}
	return true;
}