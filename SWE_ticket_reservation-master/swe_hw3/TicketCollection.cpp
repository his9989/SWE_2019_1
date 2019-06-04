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

void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}


void TicketCollection::deleteTicket(Ticket* ticket) {
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();) {
		if ((*it) == ticket) {
			it = tickets.erase(it);
		}
		else {
			it++;
		}
	}
}

void TicketCollection::setAvailability(Ticket* ticket, bool availability) {
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();it++) {
		if ((*it) == ticket) {
			(*it)->setAvailability(availability);
		}
	}
}

bool TicketCollection::existTicket() {
	if (tickets.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

