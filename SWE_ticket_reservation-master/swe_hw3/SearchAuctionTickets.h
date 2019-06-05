//SearchAuctionTickets.h
#ifndef _SEARCHAUCTIONTICKETS_H
#define _SEARCHAUCTIONTICKETS_H
#include <vector>
using namespace std;

class HomeTeamCollection;
class AuctionTicket;

// Class : SearchAuctionTickets
// Description: SearchAuctionTickets 클래스 이다. 옥션티켓 리스트를 출력하기 위한 Control이다.
// Created: 2019/06/29  
// Author: 안재령
// mail: kn043143@naver.com
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