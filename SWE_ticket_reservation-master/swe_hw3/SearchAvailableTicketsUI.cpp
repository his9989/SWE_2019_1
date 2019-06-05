#include "stdafx.h"
#include "SearchAvailableTicketsUI.h"
#include "SearchAvailableTickets.h"
#include "Buyer.h"
#include "Ticket.h"
#include "BookTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

SearchAvailableTicketsUI::SearchAvailableTicketsUI()
{
}


SearchAvailableTicketsUI::~SearchAvailableTicketsUI()
{
}

// Function : vector<Ticket *> SearchAvailableTicketsUI::startInterface(Buyer * buyer, string teamName)
// Description:
// 예약가능한 티켓을 검색하는 UI의 시작을 요청하는 함수
// Parameters : Buyer * buyer - 구매자 포인터
// string teamName - 팀 이름
// Return Value : 예약 가능한 티켓 포인터 벡터
// Created: 2019/05/30 21:30 pm
// Author: 김도현
vector<Ticket *> SearchAvailableTicketsUI::startInterface(Buyer * buyer, string teamName){ 
	HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
	return SearchAvailableTickets::getInstance()->showAvailableTickets(homeTeam);
}

// Function : Ticket * SearchAvailableTicketsUI::buyTicketInterface(Buyer * buyer, HomeTeam * homeTeam, string matchDate, string awayTeam, string seat, string currentTime)
// Description:
// 티켓을 구매할떄 거치는 함수
// Parameters : Buyer * buyer - 구매자 포인터
// HomeTeam * homeTeam - 예약을 원하는 홈팀
// string matchDate - 경기일시
// string awayTeam - 어웨이팀 이름
// string seat - 좌석위치
// Return Value : 예약된 티켓 포인터
// Created: 2019/05/30 22:30 pm
// Author: 김도현
Ticket * SearchAvailableTicketsUI::buyTicketInterface(Buyer * buyer, HomeTeam * homeTeam, string matchDate, string awayTeam, string seat, string currentTime) {
	map<string, string> ticketInfo;
	ticketInfo.insert(make_pair("matchDate", matchDate));
	ticketInfo.insert(make_pair("awayTeam", awayTeam));
	ticketInfo.insert(make_pair("seat", seat));
	return BookTicket::getInstance()->bookTicket(homeTeam, buyer, ticketInfo, currentTime);
}

SearchAvailableTicketsUI * SearchAvailableTicketsUI::inst;