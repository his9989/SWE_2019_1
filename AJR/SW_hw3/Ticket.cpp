//Ticket.cpp
#include "Ticket.h"

Ticket::Ticket() {
}

Ticket::Ticket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction) {
	this->price = price;
	this->matchDate = matchDate;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seat = seat;
	this->limitedTimeAuction = limitedTimeAuction;
}

Ticket::~Ticket() {
}

int Ticket::getPrice() { return this->price; }
string Ticket::getMatchDate() { return this->matchDate; }
string Ticket::getHomeTeam() { return this->homeTeam; }
string Ticket::getAwayTeam() { return this->awayTeam; }
string Ticket::getSeat() { return this->seat; }
bool Ticket::getLimitedTimeAuction() { return this->limitedTimeAuction; }

bool Ticket::getAvailability() { return this->availability; }
string Ticket::getRegistrationDate() { return this->registrationDate; }
string Ticket::getTimeSold() { return this->timeSold; }