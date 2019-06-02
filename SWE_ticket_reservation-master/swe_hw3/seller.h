#pragma once
#include "stdafx.h"
#include "member.h"
#include "ticketCollection.h"

class Seller : public Member {

private:
	TicketCollection * registeredTickets;

public:
	Seller();
	Seller(string, string, string, string);
	bool existTicket();
	string getType();
	TicketCollection * getRegisteredTickets();

};
