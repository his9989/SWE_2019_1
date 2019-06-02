#include "stdafx.h"
#include "SearchAvailableTicketsUI.h"
#include "SearchAvailableTickets.h"
//#include "DataSetter.h"
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

vector<Ticket *> SearchAvailableTicketsUI::startInterface(Buyer * buyer, string teamName){ 
	HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
	return SearchAvailableTickets::getInstance()->showAvailableTickets(homeTeam);
}

Ticket * SearchAvailableTicketsUI::buyTicketInterface(Buyer * buyer, HomeTeam * homeTeam, string matchDate, string awayTeam, string seat) {
	map<string, string> ticketInfo;
	ticketInfo.insert(make_pair("matchDate", matchDate));
	ticketInfo.insert(make_pair("awayTeam", awayTeam));
	ticketInfo.insert(make_pair("seat", seat));
	return BookTicket::getInstance()->bookTicket(homeTeam, buyer, ticketInfo);
}

SearchAvailableTicketsUI * SearchAvailableTicketsUI::inst;