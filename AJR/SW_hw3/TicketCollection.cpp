//TicketCollection.cpp
#include "TicketCollection.h"

TicketCollection::TicketCollection() {
}

TicketCollection::~TicketCollection() {
}

/*
TicketCollection* TicketCollection::getInstance() {
	TicketCollection *newInstance;
	if (instance == nullptr) {
		instance = new TicketCollection();
	}
	newInstance = instance;
	return newInstance;
}
*/

void TicketCollection::add(Ticket *ticket) {
	this->tickets.push_back(ticket);
}

vector<Ticket*> TicketCollection::getTickets() { return this->tickets; }