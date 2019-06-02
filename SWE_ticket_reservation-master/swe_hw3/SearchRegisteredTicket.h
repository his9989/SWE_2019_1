#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"

#pragma once
class SearchRegisteredTicket
{
private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* searchRegisteredTicketinst;
public:
	static SearchRegisteredTicket* getInstance();
	vector<Ticket*> listTIcket(Seller *s);
};

