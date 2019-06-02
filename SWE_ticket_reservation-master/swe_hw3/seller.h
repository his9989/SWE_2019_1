#include "member.h"
#include "ticketCollection.h"
using namespace std;

#ifndef SELLER_H
#define SELLER_H

class Seller : public Member {

private:
	TicketCollection registeredTickets;

public:
	Seller();
	Seller(string, string, string, string);
	bool existTicket();
	string getType();
	TicketCollection getRegisteredTickets();

};

#endif