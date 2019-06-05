//AuctionTicket.h
#ifndef _AUCTIONTICKET_H
#define _AUCTIONTICKET_H
#include <atltime.h> //CTime
#include "Ticket.h"


// Class : AuctionTicket
// Description:  AuctionTicket클래스이다. 옥션티켓의 정보를 가진 entity 클래스.
// Created: 2019/06/29
// Author: 안재령
// mail: kn043143@naver.com
class AuctionTicket : public Ticket {
private:
	string startTime;
	string closingTime;
	int bidAmount;

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
