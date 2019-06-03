//HomeTeam.cpp
#include "HomeTeam.h"
#include "Ticket.h"
#include <vector>
#include <iostream>
#include "TicketCollection.h"

HomeTeam::HomeTeam() {

}

HomeTeam::~HomeTeam() {
}

//constructor overloading
HomeTeam::HomeTeam(string name, string city) {
	this->name = name;
	this->city = city;
}

string HomeTeam::getName() {return this->name;}
string HomeTeam::getCity() { return this->city; }
TicketCollection* HomeTeam::getTicketCollection() { return this->ticketCollection; }
AuctionTicketCollection* HomeTeam::getAuctionTicketCollection() { return this->auctionTicketCollection; }

void HomeTeam::setTicketCollection(TicketCollection * ticketCollection) {

	this->ticketCollection = ticketCollection;

}

void HomeTeam::setAuctionTicketCollection(AuctionTicketCollection * ticketCollection) {

	this->auctionTicketCollection = ticketCollection;

}



vector<Ticket *> HomeTeam::listAvailableTickets() {

	return this->ticketCollection->getTickets();

}