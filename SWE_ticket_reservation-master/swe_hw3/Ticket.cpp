#include "stdafx.h"
#include "Ticket.h"
#include "Buyer.h"

Ticket::Ticket() {
	// TODO Auto-generated constructor stub
}

// price / matchDate / homeTeam / awayTeam / seat / limitedTimeAuction
Ticket::Ticket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction) {
	this->price = price;
	this->matchDate = matchDate;
	this->limitedTimeAuction = limitedTimeAuction;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seat = seat;
	this->availability = true;
	// TODO : 현재시간으로 바꿔야 함
	this->registrationDate = "2019:05:01:18:00";
}

// getter / setter
int Ticket::getPrice() {
	return price;
}

string Ticket::getMatchDate() {
	return matchDate;
}

string Ticket::getHomeTeam() {
	return homeTeam;
}

string Ticket::getAwayTeam() {
	return awayTeam;
}

string Ticket::getSeat() {
	return seat;
}

bool Ticket::getLimitedTimeAuction() {
	return limitedTimeAuction;
}

bool Ticket::getAvailability() {
	return availability;
}

string Ticket::getRegistrationDate() {
	return registrationDate;
}

string Ticket::getTimeSold() {
	return timeSold;
}

Ticket::~Ticket() {
	// TODO Auto-generated destructor stub
}

Ticket * Ticket::getTicket() {
	return this;
}

// [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
bool Ticket::bookTicket(Buyer * buyer) {
	buyer->bookedTickets.add(this);
	timeSold = "1111"; // TODO : 현재시간으로 바꿔야 함
	availability = false;
	return true;
}