//SearchAuctionTickets.cpp
#include "SearchAuctionTickets.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include <algorithm>


SearchAuctionTickets* SearchAuctionTickets::instance;

SearchAuctionTickets::SearchAuctionTickets() {
	homeTeamCollection = HomeTeamCollection::getInstance();
}

SearchAuctionTickets::~SearchAuctionTickets() {
}

// Function : SearchAuctionTickets* SearchAuctionTickets::getInstance() 
// Description: 싱글턴 구현을 위한 함수 
// Parameters :   None
// Return Value :  SearchTickets에 대한 포인터
// Created: 2019/06/29  
// Author: 안재령
SearchAuctionTickets* SearchAuctionTickets::getInstance() {
	SearchAuctionTickets *newInstance;
	if (instance == nullptr) {
		instance = new SearchAuctionTickets();
	}
	newInstance = instance;
	return newInstance;
}

// Function : vector<AuctionTicket*> SearchAuctionTickets::showHomeTeamAuctionTickets(string name)
// Description: 홈팀의 이름과 시간을 받아 옥션티켓들을 검색하는함수
// Parameters :  string name - 홈팀의 이름
// Return Value :  vector<AuctionTicket*> 옥션티켓 포인터 벡터
// Created: 2019/06/29  
// Author: 안재령
vector<AuctionTicket*> SearchAuctionTickets::showHomeTeamAuctionTickets(string name) {
	vector<HomeTeam*> homeTeams = this->homeTeamCollection->getHomeTeams();

	int i = 0;
	while (i < homeTeams.size() && name.compare(homeTeams.at(i)->getName()) != 0) {		//홈팀 이름으로 검색
		i++;
	}

	//옥션티켓 받아오기
	vector<AuctionTicket*> auctionTickets = homeTeams.at(i)->getAuctionTicketCollection()->getTickets();

	//경기날짜 및 시각이 빠른 티켓부터 정렬
	sort(auctionTickets.begin(), auctionTickets.end(), AuctionTicket::compareAuction);

	return auctionTickets;
}

HomeTeamCollection* SearchAuctionTickets::getHomeTeamCollection() { return this->homeTeamCollection; }
