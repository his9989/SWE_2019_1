//AuctionTicketCollection.cpp
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include "AuctionTicket.h"
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

void AuctionTicketCollection::deleteTicket(AuctionTicket* ticket) {
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end();) {
		if ((*it) == ticket) {
			it = tickets.erase(it);
		}
		else {
			it++;
		}
	}
}

void AuctionTicketCollection::updateBidAmount(AuctionTicket* ticket, int bidAmount) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBidAmount(bidAmount);
		}
	}
}

void AuctionTicketCollection::updateBuyerID(AuctionTicket* ticket, string buyerID) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBuyerID(buyerID);
		}
	}
}

vector<AuctionTicket*> AuctionTicketCollection::getTickets() { return tickets; }

int AuctionTicketCollection::getSize() {
	return this->tickets.size();

}