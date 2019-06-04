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

void AuctionTicket::updateBidAmount(int bidAmount) {
	this->bidAmount = bidAmount;
}

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
