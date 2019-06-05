#pragma once
#include "stdafx.h"
#include "RegisterTicket.h"

using namespace std;

// Class : RegisterTicketUI
// Description: boundary class로 티켓을 등록하기 위한 정보를 받고, membermanagement 와 curSessionID로 특정 Seller Instance를 받아온다.
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
// mail: minseob17@naver.com
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

