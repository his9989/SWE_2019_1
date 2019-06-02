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

Ticket * BookTicket::bookTicket(HomeTeam * homeTeam, Buyer * buyer, map<string,string> ticketInfo) {
	vector<Ticket *> homeTeamTickets = homeTeam->getTicketCollection()->getTickets();

	// 홈팀 티켓중 정보와 일치하는 티켓 있으면 예약 고
	for (int i = 0; i < homeTeamTickets.size(); i++) {
		if (homeTeamTickets[i]->getAvailability() && ticketInfo["matchDate"] == homeTeamTickets[i]->getMatchDate() && ticketInfo["awayTeam"] == homeTeamTickets[i]->getAwayTeam() && ticketInfo["seat"] == homeTeamTickets[i]->getSeat()) {
			homeTeamTickets[i]->bookTicket(buyer);
			return homeTeamTickets[i];
		}
	}

	return NULL;
}

BookTicket * BookTicket::inst;