//AuctionTicket.cpp
#include "AuctionTicket.h"
#include "Ticket.h"

AuctionTicket::AuctionTicket()
	:Ticket(){
}

AuctionTicket::AuctionTicket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction, string startTime, string closingTime, int bidAmount)
	: Ticket(price, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction) {
	this->startTime = startTime;
	this->closingTime = closingTime;
	this->bidAmount = bidAmount;
}

void AuctionTicket::updateBidAmount(int bidAmount) {
	this->bidAmount = bidAmount;
}

string AuctionTicket::getStartTime() { return this->startTime; }
string AuctionTicket::getClosingTime() { return this->closingTime; }
int AuctionTicket::getBidAmount() { return this->bidAmount; }