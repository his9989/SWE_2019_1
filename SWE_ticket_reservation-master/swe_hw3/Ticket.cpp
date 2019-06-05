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

// Function : Ticket * Ticket::getTicket()
// Description:
// 해당 인스턴스의 포인터 반환
// Return Value : Ticket Pointer
// Created: 2019/05/29 21:30 pm
// Author: 김도현
Ticket * Ticket::getTicket() {
	return this;
}

void Ticket::updateBuyerID(string buyerID) {
	this->buyerID = buyerID;
}

// Function : bool Ticket::bookTicket(Buyer * buyer, string currentTime)
// Description:
// 티켓을 예약하고 availability 변경
// Parameters : Buyer * buyer - 구매자
// string currentTime - 현재시간
// Return Value : 예약 성공 여부
// Created: 2019/05/29 21:30 pm
// Author: 김도현
bool Ticket::bookTicket(Buyer * buyer, string currentTime) {
	// [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
	buyer->getBookedTickets()->add(this);
	timeSold = currentTime; // TODO : 현재시간으로 바꿔야 함
	availability = false;
	this->buyerID = buyer->getID();
	return true;
}

void Ticket::setAvailability(bool availability) {
	this->availability = availability;
}

// Function : bool Ticket::compare(Ticket * me, Ticket * other)
// Description:
// 티켓 포인터 벡터 sort 전용 비교 함수
// Parameters : Ticket * me - 비교 요청 티켓 포인터
// Ticket * other - 비교 대상 티켓 포인터
// Return Value : 오른쪽 파라미터가 더 큰지 여부
// Created: 2019/05/29 23:30 pm
// Author: 김도현
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

// Function : bool Ticket::isSame(Ticket *one, Ticket *other) 
// Description: 두 티켓객체의 정보가 같은지 다른지 검사하는 함수
// Parameters :   Ticket *one - 티켓 객체 포인터1
//					Ticket *other - 티켓 객체 포인터2
// Return Value :  bool - 같으면 true, 다르면 false
// Created: 2019/06/29  
// Author: 안재령
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
