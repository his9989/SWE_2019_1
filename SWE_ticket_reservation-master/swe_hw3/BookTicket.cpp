#include "stdafx.h"
#include "BookTicket.h"
#include "Ticket.h"
#include "HomeTeam.h"
#include "SearchAvailableTicketsUI.h"

BookTicket::BookTicket()
{
}


BookTicket::~BookTicket()
{
}

// Function : Ticket * BookTicket::bookTicket(HomeTeam * homeTeam, Buyer * buyer, map<string, string> ticketInfo, string currentTime)
// Description:
// 티켓 정보와 현재시간 기반으로 티켓을 예약하는 함수입니다
// Parameters : HomeTeam * homeTeam - 예약하고 싶은 홈팀
// Buyer * buyer // 예약자
// map<string, string> ticketInfo // 구매하고싶은 티켓 정보
// string currentTime // 현재시간
// Return Value : 예약된 TIcket 포인터를 반환합니다.
//
// Created: 2019/05/28 21:10 pm
// Author: 김도현
// Revisions :
// 1. 김도현 2019/06/03 19:10 pm
// currentTime 파라미터 추가되었습니다.
Ticket * BookTicket::bookTicket(HomeTeam * homeTeam, Buyer * buyer, map<string, string> ticketInfo, string currentTime) {
	vector<Ticket *> homeTeamTickets = homeTeam->getTicketCollection()->getTickets();

	// 홈팀 티켓중 정보와 일치하는 티켓 있으면 예약 고
	for (int i = 0; i < homeTeamTickets.size(); i++) {
		if (homeTeamTickets[i]->getAvailability() && ticketInfo["matchDate"] == homeTeamTickets[i]->getMatchDate() && ticketInfo["awayTeam"] == homeTeamTickets[i]->getAwayTeam() && ticketInfo["seat"] == homeTeamTickets[i]->getSeat()) {
			homeTeamTickets[i]->bookTicket(buyer, currentTime);
			return homeTeamTickets[i];
		}
	}

	return NULL;
}

BookTicket * BookTicket::inst;