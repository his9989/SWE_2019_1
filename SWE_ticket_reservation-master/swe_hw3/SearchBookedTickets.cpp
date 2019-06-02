#include "stdafx.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"
#include "TicketCollection.h"

SearchBookedTickets::SearchBookedTickets()
{
}


SearchBookedTickets::~SearchBookedTickets()
{
}

vector<Ticket *> SearchBookedTickets::listBookedTickets(Buyer * buyer) {
	return buyer->getBookedTickets().getTickets();
}

SearchBookedTickets * SearchBookedTickets::inst;