#include "stdafx.h"
#include "SearchBookedTicketsUI.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"

SearchBookedTicketsUI::SearchBookedTicketsUI()
{
}


SearchBookedTicketsUI::~SearchBookedTicketsUI()
{
}

vector<Ticket *> SearchBookedTicketsUI::showBookedList(Buyer * buyer) {
	return SearchBookedTickets::getInstance()->listBookedTickets(buyer);
}

SearchBookedTicketsUI * SearchBookedTicketsUI::inst;