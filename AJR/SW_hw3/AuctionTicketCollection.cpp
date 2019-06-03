//AuctionTicketCollection.cpp
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include <vector>
#include <iostream>
using namespace std;

AuctionTicketCollection::AuctionTicketCollection() {
}

AuctionTicketCollection::~AuctionTicketCollection() {
}

void AuctionTicketCollection::add(AuctionTicket *ticket) {
	this->tickets.push_back(ticket);
}

vector<AuctionTicket*> AuctionTicketCollection::getTickets() { return tickets; }

int AuctionTicketCollection::getSize() {
	return this->tickets.size();
	
}