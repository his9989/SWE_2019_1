//Ticket.h
#ifndef _TICKET_H
#define _TICKET_H
#include "stdafx.h"
#include <string>
#include <atltime.h>
using namespace std;

class Ticket {
private:
	int price;	
	string matchDate;		
	string homeTeam;
	string awayTeam;
	string seat;
	bool limitedTimeAuction;

	bool availability;
	string registrationDate;
	string timeSold;

public:
	Ticket();
	Ticket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction);
	virtual ~Ticket();

	int getPrice();
	string getMatchDate();
	string getHomeTeam();
	string getAwayTeam();
	string getSeat();
	bool getLimitedTimeAuction();

	bool getAvailability();
	string getRegistrationDate();
	string getTimeSold();

	
	static bool compare(Ticket * me, Ticket * other) {

		string mmd = me->getMatchDate();
		string omd = other->getMatchDate();
		mmd.erase(remove(mmd.begin(), mmd.end(), ':'), mmd.end());
		omd.erase(remove(omd.begin(), omd.end(), ':'), omd.end());

		if (atoi(mmd.c_str()) < atoi(omd.c_str())) {
			return true;
		}
		else {
			return false;
		}
	}
	
};

#endif // !_TICKET_H
