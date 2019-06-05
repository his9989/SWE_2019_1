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

// Function : ParticipateAuction* ParticipateAuction::getInstance()
// Description: 싱글턴 구현을 위한 함수 
// Parameters :   None
// Return Value :  ParticipateAuction의 포인터
// Created: 2019/06/29  
// Author: 안재령
ParticipateAuction* ParticipateAuction::getInstance() {
	ParticipateAuction *newInstance;
	if (instance == nullptr) {
		instance = new ParticipateAuction();
	}
	newInstance = instance;
	return newInstance;
}

// Function : void ParticipateAuction::participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount)
// Description: 경매에 참여하기 위해 옥션 티켓을 검색해 입찰 금액과 구매자 아이디를 업데이트하는 함수.(유효성 검사 제외 - 현재 입찰액보다 높은 금액만을 입력한다고 가정)
// Parameters :  string teamName - 홈팀의 이름
//					AuctionTicket *auctionTicket - 옥션티켓 객체 포인터
//					string buyerID - 경매에 참여하는 구매자의ID
//					int bidAmount - 입찰금액
// Return Value :  None
// Created: 2019/06/29
// Author: 안재령
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