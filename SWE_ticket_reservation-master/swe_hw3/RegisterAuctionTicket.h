//RegisterAuctionTicket.h
#ifndef _REGISTERAUCTIONTICKET_H
#define _REGISTERAUCTIONTICKET_H
#include <string>
using namespace std;

class HomeTeamCollection;

// Class : RegisterAuctionTicket
// Description: RegisterAuctionTicket클래스이다. 옥션티켓을 등록하기 위한 클래스.
// Created: 2019/06/29
// Author: 안재령
// mail: kn043143@naver.com
class RegisterAuctionTicket {
private:
	static RegisterAuctionTicket *instance;
	RegisterAuctionTicket();

	HomeTeamCollection *homeTeamCollection;
public:
	~RegisterAuctionTicket();
	static RegisterAuctionTicket *getInstance();

	string registerAuctionTickets(string currentTime);
};

#endif // !_REGISTERAUCTIONTICKET_H
