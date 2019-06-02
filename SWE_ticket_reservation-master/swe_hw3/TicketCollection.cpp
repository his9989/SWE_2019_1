#include"stdafx.h"
#include "TicketCollection.h"

TicketCollection::TicketCollection() {
	// TODO Auto-generated constructor stub

}

TicketCollection::~TicketCollection() {
	// TODO Auto-generated destructor stub
}

vector<Ticket *> TicketCollection::getTickets() {
	return tickets;
}

void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}