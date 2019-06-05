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

// Function : TicketCollection * HomeTeam::getTicketCollection()
// Description:
// 홈팀의 티켓 콜렉션 인스턴스 포인터를 반환합니다
// Return Value : 홈팀의 티켓 콜렉션 인스턴스 포인터
//
// Created: 2019/05/29 21:15 pm
// Author: 김도현
TicketCollection * HomeTeam::getTicketCollection() {
	return ticketCollection;
}

AuctionTicketCollection* HomeTeam::getAuctionTicketCollection() { 
	return this->auctionTicketCollection; 
}

// Function : void HomeTeam::setTicketCollection(TicketCollection * ticketCollection)
// Description:
// 홈팀에게 티켓 콜렉션을 세팅하는 함수입니다
// Parameter : TicketCollection * ticketCollection - 세팅할 티켓 콜렉션 인스턴스
//
// Created: 2019/05/29 21:20 pm
// Author: 김도현
void HomeTeam::setTicketCollection(TicketCollection * ticketCollection) {
	this->ticketCollection = ticketCollection;
}

void HomeTeam::setAuctionTicketCollection(AuctionTicketCollection * ticketCollection) {

	this->auctionTicketCollection = ticketCollection;

}

// Function : vector<Ticket *> HomeTeam::listAvailableTickets()
// Description:
// 홈팀에서 현재 예약 가능한 티켓을 반환합니다
// Return: 예약 가능한 티켓 포인터 벡터
// Created: 2019/05/29 21:40 pm
// Author: 김도현
vector<Ticket *> HomeTeam::listAvailableTickets() {
	return ticketCollection->getTickets();
}