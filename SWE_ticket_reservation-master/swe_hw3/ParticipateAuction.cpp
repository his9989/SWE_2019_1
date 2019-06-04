//ParticipateAuction.cpp
#include "ParticipateAuction.h"
#include "AuctionTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

ParticipateAuction* ParticipateAuction::instance;

ParticipateAuction::ParticipateAuction() {
	homeTeamCollection = HomeTeamCollection::getInstance();
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

void ParticipateAuction::participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount) {
	vector<HomeTeam*> homeTeams = this->homeTeamCollection->getHomeTeams();

	int i = 0;
	while (i < homeTeams.size() && teamName.compare(homeTeams.at(i)->getName()) != 0) {		//홈팀 이름으로 검색
		i++;
	}

	homeTeams.at(i)->getAuctionTicketCollection()->updateBidAmount(auctionTicket, bidAmount);
	homeTeams.at(i)->getAuctionTicketCollection()->updateBuyerID(auctionTicket, buyerID);
}

HomeTeamCollection* ParticipateAuction::getHomeTeamCollection() { return this->homeTeamCollection; }