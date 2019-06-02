#pragma once
#include "stdafx.h"
#include "TicketCollection.h"
class HomeTeam;

using namespace std;

class HomeTeam {
private:
	string name;
	string city;
	TicketCollection * ticketCollection;
	//AuctionTicketCollection *auctionTicketCollection;

public:

	HomeTeam();
	HomeTeam(string, string);
	virtual ~HomeTeam();

	HomeTeam getHomeTeam();
	vector<Ticket *> listAvailableTickets();
	string getName();
	string getCity();
	TicketCollection * getTicketCollection();
	//AuctionTicketCollection* getAuctionTicketCollection();

	// ADDED
	void setTicketCollection(TicketCollection *);
	//void setAuctionTicketCollection(TicketCollection *);
};