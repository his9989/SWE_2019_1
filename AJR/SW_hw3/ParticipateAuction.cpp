//ParticipateAuction.cpp
#include "ParticipateAuction.h"
#include "AuctionTicket.h"

ParticipateAuction* ParticipateAuction::instance;

ParticipateAuction::ParticipateAuction() {
}

ParticipateAuction::~ParticipateAuction() {
}

ParticipateAuction* ParticipateAuction::getInstance() {
	ParticipateAuction *newInstance;
	if (instance == nullptr) {
		instance = new ParticipateAuction();
	}
	newInstance = instance;
	return newInstance;
}

void ParticipateAuction::participateAuction(AuctionTicket *auctionTicket, int bidAmount) {
	auctionTicket->updateBidAmount(bidAmount);
}

HomeTeamCollection* ParticipateAuction::getHomeTeamCollection() { return this->homeTeamCollection; }