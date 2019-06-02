//AuctionTicketCollection.cpp
#include "AuctionTicketCollection.h"
#include <iostream>
using namespace std;

AuctionTicketCollection::AuctionTicketCollection() {

}

AuctionTicketCollection::~AuctionTicketCollection() {
}

/*
AuctionTicketCollection* AuctionTicketCollection::getInstance() {
	AuctionTicketCollection *newInstance;
	if (instance == nullptr) {
		instance = new AuctionTicketCollection();
	}
	newInstance = instance;
	return newInstance;
}
*/

void AuctionTicketCollection::add(AuctionTicket *ticket) {
	this->tickets.push_back(ticket);
}

vector<AuctionTicket*> AuctionTicketCollection::getTickets() { return this->tickets; }