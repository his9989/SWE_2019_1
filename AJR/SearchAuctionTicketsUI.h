//SearchAuctionTicketsUI.h
#ifndef _SEARCHAUCTIONTICKETSUI_H
#define _SEARCHAUCTIONTICKETSUI_H
#include <vector>
#include <string>
using namespace std;

class HomeTeam;
class AuctionTicket;
class SearchAuctionTicketsUI {
private:
	static SearchAuctionTicketsUI *instance;
	SearchAuctionTicketsUI();
public:
	~SearchAuctionTicketsUI();
	static SearchAuctionTicketsUI *getInstance();

	void startInterface(vector<HomeTeam*> homeTeams);
	void selectParticipateAuction(AuctionTicket *auctionTicket);
	string selectHomeTeam(string teamName);
};

#endif // !_SEARCHAUCTIONTICKETSUI_H
