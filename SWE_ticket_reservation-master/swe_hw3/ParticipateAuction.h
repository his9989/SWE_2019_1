//ParticipateAuction.h
#ifndef _PARTICIPATEAUCTION_H
#define _PARTICIPATEAUCTION_H
#include <string>
using namespace std;

class AuctionTicket;
class HomeTeamCollection;
class ParticipateAuction {
private:
	static ParticipateAuction *instance;
	ParticipateAuction();

	HomeTeamCollection *homeTeamCollection;
public:
	~ParticipateAuction();
	static ParticipateAuction *getInstance();

	void participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount);
	HomeTeamCollection* getHomeTeamCollection();
};

#endif // !_PARTICIPATEAUCTION_H