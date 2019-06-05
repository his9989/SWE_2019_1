//CloseAuctionTicket.h
#ifndef _CLOSEAUCTIONTICKET_H
#define _CLOSEAUCTIONTICKET_H
#include "memberManagement.h"
#include <string>
using namespace std;

class HomeTeamCollection;

// Class : CloseAuctionTicket
// Description:  CloseAuctionTicket클래스이다. 옥션 티켓을 마감하기 위한 클래스.
// Created: 2019/06/29
// Author: 안재령
// mail: kn043143@naver.com
class CloseAuctionTicket {
private:
	static CloseAuctionTicket *instance;
	CloseAuctionTicket();

	HomeTeamCollection *homeTeamCollection;
public:
	~CloseAuctionTicket();
	static CloseAuctionTicket *getInstance();

	string closeAuction(MemberManagement *mm, string currentTime);
};

#endif // !_CLOSEAUCTIONTICKET_H

