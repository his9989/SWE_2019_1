//SearchAuctionTicketsUI.h
#ifndef _SEARCHAUCTIONTICKETSUI_H
#define _SEARCHAUCTIONTICKETSUI_H
#include <vector>
#include <string>
using namespace std;

class HomeTeam;
class AuctionTicket;

// Class : SearchAuctionTicketsUI
// Description: SearchAuctionTicketsUI이다. AuctionTicket 객체들을 검색하기 위한 UI이다.
// Created: 2019/06/29  
// Author: 안재령
// mail: kn043143@naver.com
class SearchAuctionTicketsUI {
private:
	static SearchAuctionTicketsUI *instance;
	SearchAuctionTicketsUI();
	string teamName;
public:
	~SearchAuctionTicketsUI();
	static SearchAuctionTicketsUI *getInstance();

	string selectHomeTeam(string teamName, string currentTime);
	string selectParticipateAuction(string buyerID, string matchDate, string awayTeam, string seat, string bidAmount);	// 구매자아이디 [날짜-시간] [어웨이팀] [좌석위치] [입찰금액] 

	string getTeamName();
};

#endif // !_SEARCHAUCTIONTICKETSUI_H