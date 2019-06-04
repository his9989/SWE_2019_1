//AuctionTicket.h
#ifndef _AUCTIONTICKET_H
#define _AUCTIONTICKET_H
#include <atltime.h> //CTime
#include "Ticket.h"

class AuctionTicket : public Ticket {
private:
	string startTime;
	string closingTime;
	int bidAmount;

	string buyerID;

public:
	AuctionTicket();
	AuctionTicket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction,string sellerID, string buyerID, string currentTime, string startTime, string closingTime, int bidAmount);
	void updateBidAmount(int bidAmount);

	string getStartTime();
	string getClosingTime();
	int getBidAmount();


	static bool compareAuction(AuctionTicket * me, AuctionTicket * other);
};

#endif // !_AUCTIONTICKET_H
