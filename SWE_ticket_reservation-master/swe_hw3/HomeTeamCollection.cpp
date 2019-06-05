#include "stdafx.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

// Function : HomeTeamCollection::HomeTeamCollection()
// Description:
// 홈팀 콜렉션 생성자입니다. 홈팀의 티켓콜렉션을 할당해 줍니다
//
// Created: 2019/05/28 15:23 pm
// Author: 안재령, 김도현
//
// Revisions :
// 1. 2019/06/01 15:23 pm 안재령 : 옥션티켓 콜렉션 할당 추가
HomeTeamCollection::HomeTeamCollection() {
	// 홈팀 초기화
	TicketCollection* tc1 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc2 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc3 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc4 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc5 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc6 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc7 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc8 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc9 = new TicketCollection();// = new TicketCollection();
	TicketCollection* tc10 = new TicketCollection();// = new TicketCollection();
	
	AuctionTicketCollection * tc11 = new AuctionTicketCollection();
	AuctionTicketCollection * tc22 = new AuctionTicketCollection();
	AuctionTicketCollection * tc33 = new AuctionTicketCollection();
	AuctionTicketCollection * tc44 = new AuctionTicketCollection();
	AuctionTicketCollection * tc55 = new AuctionTicketCollection();
	AuctionTicketCollection * tc66 = new AuctionTicketCollection();
	AuctionTicketCollection * tc77 = new AuctionTicketCollection();
	AuctionTicketCollection * tc88 = new AuctionTicketCollection();
	AuctionTicketCollection * tc99 = new AuctionTicketCollection();
	AuctionTicketCollection * tc1010 = new AuctionTicketCollection();
	
	HomeTeam* a = new HomeTeam("sk", "Incheon");
	HomeTeam* b = new HomeTeam("doosan", "Seoul");
	HomeTeam* c = new HomeTeam("lg", "Seoul");
	HomeTeam* d = new HomeTeam("nc", "Changwon");
	HomeTeam* e = new HomeTeam("kiwoom", "Seoul");
	HomeTeam* f = new HomeTeam("hanwha", "Daejeon");
	HomeTeam* g = new HomeTeam("samsung", "Daegu");
	HomeTeam* h = new HomeTeam("lotte", "Busan");
	HomeTeam* i = new HomeTeam("kt", "Suwon");
	HomeTeam* j = new HomeTeam("kia", "Gwangju");

	a->setTicketCollection(tc1);
	b->setTicketCollection(tc2);
	c->setTicketCollection(tc3);
	d->setTicketCollection(tc4);
	e->setTicketCollection(tc5);
	f->setTicketCollection(tc6);
	g->setTicketCollection(tc7);
	h->setTicketCollection(tc8);
	i->setTicketCollection(tc9);
	j->setTicketCollection(tc10);

	a->setAuctionTicketCollection(tc11);
	b->setAuctionTicketCollection(tc22);
	c->setAuctionTicketCollection(tc33);
	d->setAuctionTicketCollection(tc44);
	e->setAuctionTicketCollection(tc55);
	f->setAuctionTicketCollection(tc66);
	g->setAuctionTicketCollection(tc77);
	h->setAuctionTicketCollection(tc88);
	i->setAuctionTicketCollection(tc99);
	j->setAuctionTicketCollection(tc1010);

	this->add(a);
	this->add(b);
	this->add(c);
	this->add(d);
	this->add(e);
	this->add(f);
	this->add(g);
	this->add(h);
	this->add(i);
	this->add(j);
}

HomeTeamCollection::~HomeTeamCollection() {
	// TODO Auto-generated destructor stub
}

// Function : vector<HomeTeam *> HomeTeamCollection::getHomeTeams()
// Description:
// 현재 등록되어있는 모든 홈팀의 목록을 벡터로 반환합니다
// Return Value : 홈팀의 포인터가 담긴 벡터
//
// Created: 2019/05/28 18:01 pm
// Author: 김도현
vector<HomeTeam *> HomeTeamCollection::getHomeTeams() {
	return homeTeams;
}


// Function : vector<HomeTeam *> HomeTeamCollection::add(HomeTeam * homeTeam)
// Description:
// 홈팀을 추가합니다.
//
// Created: 2019/05/28 17:30 pm
// Author: 김도현
void HomeTeamCollection::add(HomeTeam * homeTeam) {
	homeTeams.push_back(homeTeam);
}

// Function : HomeTeam * HomeTeamCollection::getHomeTeamByName(string teamName)
// Description:
// 홈팀의 이름을 파라미터로 전달하면, 해당되는 홈팀을 가리키는 포인터를 반환합니다.
// Return Value : 홈팀 포인터
// Parameters : string teamName - 홈팀의 이름
// Created: 2019/05/28 18:30 pm
// Author: 김도현
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