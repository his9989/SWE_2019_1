//AuctionTicket.cpp
#include "AuctionTicket.h"
#include "Ticket.h"

AuctionTicket::AuctionTicket()
	:Ticket() {
}

AuctionTicket::AuctionTicket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction, string sellerID, string buyerID, string currentTime, string startTime, string closingTime, int bidAmount)
	: Ticket(price, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction, sellerID, buyerID, currentTime) {
	this->startTime = startTime;
	this->closingTime = closingTime;
	this->bidAmount = bidAmount;
}

// Function : void AuctionTicket::updateBidAmount(int bidAmount) 
// Description: 옥션 티켓의 입찰액 업데이트 함수 
// Parameters :   int bidAmount - 입찰 금액
// Return Value :  None
// Created: 2019/06/29  
// Author: 안재령
void AuctionTicket::updateBidAmount(int bidAmount) {
	this->bidAmount = bidAmount;
}

// Function : bool AuctionTicket::compareAuction(AuctionTicket * me, AuctionTicket * other)
// Description: 옥션 티켓의 경기날짜-시간 비교 함수
// Parameters :  AuctionTicket * me - 옥션 티켓 포인터1
//					AuctionTicket * other - 옥션 티켓 포인터2
// Return Value :  bool - me의 경기 날짜-시간이 작으면 true, 크거나 같으면 false
// Created: 2019/06/29  
// Author: 안재령
bool AuctionTicket::compareAuction(AuctionTicket * me, AuctionTicket * other) {
	string mmd = me->getClosingTime();
	string omd = other->getClosingTime();
	mmd.erase(remove(mmd.begin(), mmd.end(), ':'), mmd.end());
	omd.erase(remove(omd.begin(), omd.end(), ':'), omd.end());

	if (atoi(mmd.c_str()) < atoi(omd.c_str())) {
		return true;
	}
	else {
		return false;
	}
}

string AuctionTicket::getStartTime() { return this->startTime; }
string AuctionTicket::getClosingTime() { return this->closingTime; }
int AuctionTicket::getBidAmount() { return this->bidAmount; }
