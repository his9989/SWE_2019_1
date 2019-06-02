#include "stdafx.h"
#include "HomeTeam.h"
#include "Ticket.h"
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

void HomeTeam::setTicketCollection(TicketCollection * ticketCollection) {
	this->ticketCollection = ticketCollection;
}

vector<Ticket *> HomeTeam::listAvailableTickets() {
	return ticketCollection->getTickets();
}