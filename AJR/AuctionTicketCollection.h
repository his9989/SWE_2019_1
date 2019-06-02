//AuctionTicketCollection.h
#ifndef _AUCTIONTICKETCOLLECTION_H
#define _AUCTIONTICKETCOLLECTION_H
#include <vector>
using namespace std;

class AuctionTicket;
class AuctionTicketCollection {
private:
	vector<AuctionTicket*> tickets;
	

public:
	AuctionTicketCollection();
	virtual ~AuctionTicketCollection();
	void add(AuctionTicket *ticket);

	vector<AuctionTicket*> getTickets();
};

#endif // !_AUCTIONTICKETCOLLECTION_H
