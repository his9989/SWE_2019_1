//ParticipateAuction.h
#ifndef _PARTICIPATEAUCTION_H
#define _PARTICIPATEAUCTION_H
#include <string>
using namespace std;

class AuctionTicket;
class HomeTeamCollection;

// Class : ParticipateAuction
// Description: ParticipateAuction클래스이다. 옥션티켓을 대상으로 입찰에 참여하기 위한 클래스.
// Created: 2019/06/29
// Author: 안재령
// mail: kn043143@naver.com
class ParticipateAuction {
private:
	static ParticipateAuction *instance;
	ParticipateAuction();

	HomeTeamCollection *homeTeamCollection;
public:
	~ParticipateAuction();
	static ParticipateAuction *getInstance();

	void participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount);
	HomeTeamCollection* getHomeTeamCollection();
};

#endif // !_PARTICIPATEAUCTION_H