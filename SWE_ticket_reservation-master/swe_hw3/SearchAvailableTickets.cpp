#include "stdafx.h"
#include "SearchAvailableTickets.h"
#include "SearchAvailableTicketsUI.h"
//#include "DataSetter.h"
#include "HomeTeam.h"

SearchAvailableTickets::SearchAvailableTickets()
{
}


SearchAvailableTickets::~SearchAvailableTickets()
{
}

vector<Ticket *> SearchAvailableTickets::showAvailableTickets(HomeTeam * homeTeam) {
	return homeTeam->listAvailableTickets();
}

SearchAvailableTickets * SearchAvailableTickets::inst;