#include "stdafx.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

HomeTeamCollection::HomeTeamCollection() {
	// È¨ÆÀ ÃÊ±âÈ­
	TicketCollection* tc1 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc2 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc3 = new TicketCollection();// = new TicketCollection();
	
	AuctionTicketCollection * tc11 = new AuctionTicketCollection();
	AuctionTicketCollection * tc22 = new AuctionTicketCollection();
	AuctionTicketCollection * tc33 = new AuctionTicketCollection();
	
	HomeTeam* a = new HomeTeam("sk", "Seoul");
	HomeTeam* b = new HomeTeam("lg", "Ulsan");
	HomeTeam* c = new HomeTeam("doosan", "Gwangju");

	a->setTicketCollection(tc1);
	b->setTicketCollection(tc2);
	c->setTicketCollection(tc3);

	a->setAuctionTicketCollection(tc11);
	b->setAuctionTicketCollection(tc22);
	c->setAuctionTicketCollection(tc33);

	this->add(a);
	this->add(b);
	this->add(c);
}

HomeTeamCollection::~HomeTeamCollection() {
	// TODO Auto-generated destructor stub
}

vector<HomeTeam *> HomeTeamCollection::getHomeTeams() {
	return homeTeams;
}

void HomeTeamCollection::add(HomeTeam * homeTeam) {
	homeTeams.push_back(homeTeam);
}

HomeTeam * HomeTeamCollection::getHomeTeamByName(string teamName) {
	vector<HomeTeam *> homeTeams = this->getHomeTeams();
	for (int i = 0; i < homeTeams.size(); i++) {
		if (teamName.compare(homeTeams[i]->getName()) == 0) {
			return homeTeams[i];
		}
	}
	return NULL;
}

HomeTeamCollection* HomeTeamCollection::inst = nullptr;