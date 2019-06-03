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
	int getSize();
};

#endif // !_AUCTIONTICKETCOLLECTION_H
