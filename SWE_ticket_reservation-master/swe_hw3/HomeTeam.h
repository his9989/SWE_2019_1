#pragma once
#include "stdafx.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

using namespace std;

// Class : HomeTeam
// Description: È¨ÆÀÀ» ³ªÅ¸³»´Â entity class
// Created: 2019/5/29 18:10 pm
// Author: ±èµµÇö
// mail: donsdevko@gmail.com
class HomeTeam {
private:
	string name;
	string city;
	TicketCollection * ticketCollection;
	AuctionTicketCollection *auctionTicketCollection;

public:

	HomeTeam();
	HomeTeam(string, string);
	virtual ~HomeTeam();

	HomeTeam getHomeTeam();
	vector<Ticket *> listAvailableTickets();
	string getName();
	string getCity();
	TicketCollection * getTicketCollection();
	AuctionTicketCollection* getAuctionTicketCollection();

	// ADDED
	void setTicketCollection(TicketCollection *);
	void setAuctionTicketCollection(AuctionTicketCollection *);
};