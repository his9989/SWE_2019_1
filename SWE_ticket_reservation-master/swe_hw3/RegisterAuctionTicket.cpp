//RegisterAuctionTicket.cpp
#include "RegisterAuctionTicket.h"
#include "SearchAuctionTicketsUI.h"
#include "HomeTeamCollection.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"
#include "HomeTeam.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include "HomeTeam.h"
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

RegisterAuctionTicket* RegisterAuctionTicket::instance;

RegisterAuctionTicket::RegisterAuctionTicket() {
	this->homeTeamCollection = HomeTeamCollection::getInstance();
}

RegisterAuctionTicket::~RegisterAuctionTicket() {
}

// Function : RegisterAuctionTicket* RegisterAuctionTicket::getInstance()
// Description: 싱글턴 구현을 위한 함수 
// Parameters :   None
// Return Value :  RegisterAuctionTicket의 포인터
// Created: 2019/06/29  
// Author: 안재령
RegisterAuctionTicket* RegisterAuctionTicket::getInstance() {
	RegisterAuctionTicket *newInstance;
	if (instance == nullptr) {
		instance = new RegisterAuctionTicket();
	}
	newInstance = instance;
	return newInstance;
}

// Function : string RegisterAuctionTicket::registerAuctionTickets(string currentTime) 
// Description: 현재시간과 티켓의 경기시간을 비교하여 옥션티켓 객체를 생성하는 함수
// Parameters :  string currentTime - 현재 시간
// Return Value :  string - 새로 옥션티켓으로 등록된 티켓들의 정보 문자열
// Created: 2019/06/29
// Author: 안재령
vector<string> split(string str, char delimiter);
string RegisterAuctionTicket::registerAuctionTickets(string currentTime) {
	string out;

	vector<string> current = split(currentTime, ':');
	int year = stoi(current[0]);
	int month = stoi(current[1]);
	int day = stoi(current[2]);
	int hour = stoi(current[3]);
	int min = stoi(current[4]);

	struct tm currentDate = {};
	currentDate.tm_year = year - 1900;
	currentDate.tm_mon = month - 1;
	currentDate.tm_mday = day;
	currentDate.tm_hour = hour;
	currentDate.tm_min = min;
	time_t currentDateT = mktime(&currentDate);

	vector<HomeTeam*> homeTeams = homeTeamCollection->getHomeTeams();
	vector<Ticket*> tickets;

	int i = 0;
	bool flag;
	for (i = 0; i < homeTeams.size(); i++) {

		tickets = homeTeams[i]->getTicketCollection()->getTickets();

		for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();it++) {

			flag = false;
			string matchDate = (*it)->getMatchDate();
			vector<string> vMatchDate = split(matchDate, ':');
			year = stoi(vMatchDate[0]);
			month = stoi(vMatchDate[1]);
			day = stoi(vMatchDate[2]);
			hour = stoi(vMatchDate[3]);
			min = stoi(vMatchDate[4]);

			struct tm ticketDate = {};
			ticketDate.tm_year = year - 1900;
			ticketDate.tm_mon = month - 1;
			ticketDate.tm_mday = day;
			ticketDate.tm_hour = hour;
			ticketDate.tm_min = min;
			time_t ticketDateT = mktime(&ticketDate);

			//현재시간-티켓시간 시간차 구하기
			double     d_diff;
			d_diff = difftime(ticketDateT, currentDateT);		//double difftime( time_t timeEnd, time_t timeStart );

			if (d_diff < (double)86400 && d_diff > (double)21600) {		//시간차가 6시간 이상 24시간 이내 (옥션 마감시간이 ticket의 matchDate - 6 시간이므로)
				flag = true;
			}

			if ((*it)->getLimitedTimeAuction() == true && flag == true) {
				struct tm startTime = {};		//옥션 시작시간
				startTime.tm_year = year - 1900;
				startTime.tm_mon = month - 1;
				startTime.tm_mday = day;
				startTime.tm_hour = hour - 24;		//경기시작 24시간 전
				startTime.tm_min = min;
				time_t startTimeT = mktime(&startTime);

				int printYear = startTime.tm_year + 1900;
				int printMonth = startTime.tm_mon + 1;
				int printDay = startTime.tm_mday;
				int printHour = startTime.tm_hour;		//경기시작 24시간 전
				int printMin = startTime.tm_min;

				string startTimeString;
				startTimeString.append(to_string(printYear)); startTimeString.append(":");
				startTimeString.append(to_string(printMonth)); startTimeString.append(":");
				startTimeString.append(to_string(printDay)); startTimeString.append(":");
				startTimeString.append(to_string(printHour)); startTimeString.append(":");
				startTimeString.append(to_string(printMin));


				struct tm closingTime = {};	//옥션 마감시간
				closingTime.tm_year = year - 1900;
				closingTime.tm_mon = month - 1;
				closingTime.tm_mday = day;
				closingTime.tm_hour = hour - 6;	//경기 시간 6시간 전
				closingTime.tm_min = min;
				time_t closingTimeT = mktime(&closingTime);

				printYear = closingTime.tm_year + 1900;
				printMonth = closingTime.tm_mon + 1;
				printDay = closingTime.tm_mday;
				printHour = closingTime.tm_hour;		//경기시작 6시간 전
				printMin = closingTime.tm_min;

				string closingTimeString;
				closingTimeString.append(to_string(printYear)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMonth)); closingTimeString.append(":");
				closingTimeString.append(to_string(printDay)); closingTimeString.append(":");
				closingTimeString.append(to_string(printHour)); closingTimeString.append(":");
				closingTimeString.append(to_string(printMin));

				//옥션 티켓 생성
				AuctionTicket *auctionTicket = new AuctionTicket((*it)->getPrice(), (*it)->getMatchDate(), (*it)->getHomeTeam(), (*it)->getAwayTeam(), (*it)->getSeat(), (*it)->getLimitedTimeAuction(),(*it)->getSellerID(),(*it)->getBuyerID(),currentTime , startTimeString, closingTimeString, (int)0.5*((*it)->getPrice()));
				homeTeams[i]->getAuctionTicketCollection()->add(auctionTicket);		//옥션 티켓 추가

				//it = homeTeams.at(i)->getTicketCollection()->getTickets().erase(it);	//원래 있던 티켓 지우기
				homeTeams[i]->getTicketCollection()->deleteTicket(*it);

				out.append(to_string(auctionTicket->getPrice())); out.append(" ");
				out.append(auctionTicket->getMatchDate()); out.append(" ");
				out.append(auctionTicket->getHomeTeam()); out.append(" ");
				out.append(auctionTicket->getAwayTeam()); out.append(" ");
				out.append(auctionTicket->getSeat()); out.append(" ");
				out.append(auctionTicket->getClosingTime());
				out.append("\n");
			}

		}
	}
	return out;
}
