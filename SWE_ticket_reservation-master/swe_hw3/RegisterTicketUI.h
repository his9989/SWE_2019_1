#pragma once
#include "stdafx.h"
#include "RegisterTicket.h"

using namespace std;

class RegisterTicketUI
{
private:
	RegisterTicketUI();
	static RegisterTicketUI* registerTicketUIinst;
public:
	static RegisterTicketUI* getInstance();
	void putTicketInfo(string _price,
		string _matchDate,
		string _homeTeam,
		string _awayTeam,
		string _seat,
		bool _limitedTimeAuction,
		string ID,
		MemberManagement *mm,
		string currentTime);
	~RegisterTicketUI();
};

