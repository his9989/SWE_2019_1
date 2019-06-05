//AuctionTicketCollection.h
#ifndef _AUCTIONTICKETCOLLECTION_H
#define _AUCTIONTICKETCOLLECTION_H
#include <vector>
using namespace std;

class AuctionTicket;

// Class : AuctionTicketCollection
// Description:  AuctionTicketCollection클래스이다. 옥션티켓들을 벡터로 모아놓은 콜렉션 클래스.
// Created: 2019/06/29
// Author: 안재령
// mail: kn043143@naver.com
class AuctionTicketCollection {
private:
	vector<AuctionTicket*> tickets;


public:
	AuctionTicketCollection();
	virtual ~AuctionTicketCollection();
	void add(AuctionTicket *ticket);
	void deleteTicket(AuctionTicket *);
	void updateBidAmount(AuctionTicket *, int);
	void updateBuyerID(AuctionTicket *, string);
	vector<AuctionTicket*> getTickets();
	int getSize();
};

#endif // !_AUCTIONTICKETCOLLECTION_H
