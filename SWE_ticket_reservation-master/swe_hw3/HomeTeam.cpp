#include "stdafx.h"
#include "HomeTeam.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

HomeTeam::HomeTeam() {

}

HomeTeam::~HomeTeam() {

}

//constructor overloading
HomeTeam::HomeTeam(string name, string city) {
	this->name = name;
	this->city = city;
}


HomeTeam HomeTeam::getHomeTeam() {
	return * this;
}

string HomeTeam::getName() {
	return this->name;
}

string HomeTeam::getCity() {
	return this->city;
}


TicketCollection * HomeTeam::getTicketCollection() {
	return ticketCollection;
}

AuctionTicketCollection* HomeTeam::getAuctionTicketCollection() { 
	return this->auctionTicketCollection; 
}

void HomeTeam::setTicketCollection(TicketCollection * ticketCollection) {
	this->ticketCollection = ticketCollection;
}

void HomeTeam::setAuctionTicketCollection(AuctionTicketCollection * ticketCollection) {

	this->auctionTicketCollection = ticketCollection;

}

vector<Ticket *> HomeTeam::listAvailableTickets() {
	return ticketCollection->getTickets();
}