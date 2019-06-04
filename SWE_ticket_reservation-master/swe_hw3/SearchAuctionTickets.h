//SearchAuctionTickets.h
#ifndef _SEARCHAUCTIONTICKETS_H
#define _SEARCHAUCTIONTICKETS_H
#include <vector>
using namespace std;

class HomeTeamCollection;
class AuctionTicket;
class SearchAuctionTickets {
private:
	static SearchAuctionTickets *instance;
	SearchAuctionTickets();

	HomeTeamCollection *homeTeamCollection;
public:
	~SearchAuctionTickets();
	static SearchAuctionTickets *getInstance();
	vector<AuctionTicket*> showHomeTeamAuctionTickets(string name);

	HomeTeamCollection* getHomeTeamCollection();
};

#endif //!_SEARCHAUCTIONTICKETS_H