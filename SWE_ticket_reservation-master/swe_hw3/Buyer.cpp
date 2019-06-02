#include "stdafx.h"
#include "Buyer.h"

Buyer::Buyer()
{
}

Buyer::Buyer(string id, string password, string name, string identificationNumber)
{
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	bookedTickets = new TicketCollection();
}

Buyer::~Buyer()
{
}

TicketCollection Buyer::getBookedTickets() {
	return bookedTickets;
}

string Buyer::getType() {
	return "Buyer";
}

/* virtual existTicket() 구현 필요 */