#pragma once
#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"

class SearchRegisteredTicket
{
private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* searchRegisteredTicketinst;
public:
	static SearchRegisteredTicket* getInstance();
	vector<Ticket*> listTIcket(Seller *s);
};

