#include "stdafx.h"
#include "TicketCollection.h"
#include "Ticket.h"

TicketCollection::TicketCollection() {
	// TODO Auto-generated constructor stub

}

TicketCollection::~TicketCollection() {
	// TODO Auto-generated destructor stub
}

vector<Ticket *> TicketCollection::getTickets() {
	return tickets;
}

void TicketCollection::deleteTicket(Ticket* ticket) {
	int i = 0;
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			it = tickets.erase(it);
		}
	}
}

void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}

bool TicketCollection::existTicket() {
	if (tickets.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

