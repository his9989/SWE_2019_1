//HomeTeamCollection.cpp
#include "HomeTeamCollection.h"
#include "HomeTeam.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"
#include "DataSetter.h"

HomeTeamCollection* HomeTeamCollection::instance;
HomeTeamCollection::HomeTeamCollection() {
	TicketCollection * tc1 = new TicketCollection();
	TicketCollection * tc2 = new TicketCollection();
	TicketCollection * tc3 = new TicketCollection();

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
}


HomeTeamCollection* HomeTeamCollection::getInstance() {
	HomeTeamCollection *newInstance;
	if (instance == nullptr) {
		instance = new HomeTeamCollection();
	}
	newInstance = instance;
	return newInstance;
}

void HomeTeamCollection::add(HomeTeam *homeTeam) {
	this->homeTeams.push_back(homeTeam);
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

vector<HomeTeam*> HomeTeamCollection::getHomeTeams() { return this->homeTeams; }