#include "stdafx.h"
#include "SearchRegisteredTicket.h"

SearchRegisteredTicket* SearchRegisteredTicket::searchRegisteredTicketinst;

SearchRegisteredTicket::SearchRegisteredTicket() {}

SearchRegisteredTicket* SearchRegisteredTicket::getInstance()
{
	if (searchRegisteredTicketinst == nullptr)
		searchRegisteredTicketinst = new SearchRegisteredTicket;
	return searchRegisteredTicketinst;
}

vector<Ticket*> SearchRegisteredTicket::listTIcket(Seller* s)
{
	return s->getRegisteredTickets()->getTickets();
}

