//ParticipateAuction.h
#ifndef _PARTICIPATEAUCTION_H
#define _PARTICIPATEAUCTION_H

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

	void participateAuction(AuctionTicket *auctionTicket, int bidAmount);
	HomeTeamCollection* getHomeTeamCollection();
};

#endif // !_PARTICIPATEAUCTION_H