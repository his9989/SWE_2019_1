//AuctionTicket.h
#ifndef _AUCTIONTICKET_H
#define _AUCTIONTICKET_H
#include "Ticket.h"
#include <atltime.h> //CTime

class AuctionTicket : public Ticket{
private:
	string startTime;
	string closingTime;
	int bidAmount;

public:
	AuctionTicket();
	AuctionTicket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction, string startTime, string closingTime, int bidAmount);
	void updateBidAmount(int bidAmount);

	string getStartTime();
	string getClosingTime();
	int getBidAmount();
};

#endif // !_AUCTIONTICKET_H
