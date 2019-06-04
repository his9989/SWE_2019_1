#pragma once
#include "stdafx.h"
class Buyer;

using namespace std;

class Ticket {
private: 
	int price;
	string matchDate; // 파싱 필요 (추가로 제가 date type확인할게요..)
	string homeTeam;
	string awayTeam;
	string seat;
	bool limitedTimeAuction;
	string timeSold;
	string registrationDate;
	bool availability;
	string sellerID;
	string buyerID;

public:
	Ticket();
	// TODO : registrationDate 현재시간 기준으로 생성자에서 해주어야 하는 것은 아닌지
	// price / matchDate / homeTeam / awayTeam / seat / limitedTimeAuction / sellerID / buyerID / currentTime
	Ticket(int, string, string, string, string, bool,string,string,string);

	virtual ~Ticket();

	bool bookTicket(Buyer *, string);
	Ticket * getTicket();

	// getter / setter
	int getPrice();

	string getMatchDate();

	string getHomeTeam();

	string getAwayTeam();

	string getSeat();

	bool getLimitedTimeAuction();

	bool getAvailability();

	string getRegistrationDate();

	string getTimeSold();
	
	string getSellerID();

	string getBuyerID();

	void updateBuyerID(string buyerID);

	void setAvailability(bool availability);

	// algorithm sorting 시 커스텀 비교용 function 구현
	static bool compare(Ticket * me, Ticket * other);

	bool isSame(Ticket *one, Ticket *other);

};