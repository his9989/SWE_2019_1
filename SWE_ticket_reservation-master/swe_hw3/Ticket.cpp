#include "stdafx.h"
#include "Ticket.h"
#include "Buyer.h"

Ticket::Ticket() {
	// TODO Auto-generated constructor stub
}

// price / matchDate / homeTeam / awayTeam / seat / limitedTimeAuction
Ticket::Ticket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction, string sellerID, string buyerID, string currentTime) {
	this->price = price;
	this->matchDate = matchDate;
	this->limitedTimeAuction = limitedTimeAuction;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seat = seat;
	this->availability = true;
	// TODO : 현재시간으로 바꿔야 함
	this->registrationDate = currentTime;
	this->sellerID = sellerID;
	this->buyerID = buyerID;
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

string Ticket::getSellerID() {
	return sellerID;
}

string Ticket::getBuyerID() {
	return buyerID;
}

Ticket::~Ticket() {
	// TODO Auto-generated destructor stub
}

Ticket * Ticket::getTicket() {
	return this;
}

void Ticket::updateBuyerID(string buyerID) {
	this->buyerID = buyerID;
}

// [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
bool Ticket::bookTicket(Buyer * buyer, string currentTime) {
	buyer->getBookedTickets()->add(this);
	timeSold = currentTime; // TODO : 현재시간으로 바꿔야 함
	availability = false;
	this->buyerID = buyer->getID();
	return true;
}

void Ticket::setAvailability(bool availability) {
	this->availability = availability;
}

bool Ticket::compare(Ticket * me, Ticket * other) {
	string mmd = me->getMatchDate();
	string omd = other->getMatchDate();
	mmd.erase(remove(mmd.begin(), mmd.end(), ':'), mmd.end());
	omd.erase(remove(omd.begin(), omd.end(), ':'), omd.end());

	if (atoi(mmd.c_str()) < atoi(omd.c_str())) {
		return true;
	}
	else {
		return false;
	}
}


bool Ticket::isSame(Ticket *one, Ticket *other) {
	int onePrice = one->getPrice();
	int otherPrice = other->getPrice();
	string oneMatchDate = one->getMatchDate();
	string otherMatchDate = other->getMatchDate();
	string oneHomeTeam = one->getHomeTeam();
	string otherHomeTeam = other->getHomeTeam();
	string oneAwayTeam = one->getAwayTeam();
	string otherAwayTeam = other->getAwayTeam();
	string oneSeat = one->getSeat();
	string otherSeat = other->getSeat();

	oneMatchDate.erase(remove(oneMatchDate.begin(), oneMatchDate.end(), ':'), oneMatchDate.end());
	otherMatchDate.erase(remove(otherMatchDate.begin(), otherMatchDate.end(), ':'), otherMatchDate.end());

	if (onePrice==otherPrice && atoi(oneMatchDate.c_str()) == atoi(otherMatchDate.c_str()) && oneHomeTeam.compare(otherHomeTeam)==0 &&oneAwayTeam.compare(otherAwayTeam)==0 && oneSeat.compare(otherSeat)==0) {
		return true;
	}
	else {
		return false;
	}
}
