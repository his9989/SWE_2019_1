#pragma once
#include "stdafx.h"
class Buyer;
class Ticket;

// Class : SearchBookedTicketUI
// Description: 자신이 예약한 티켓을 확인할수 있는 바운더리 클래스
// Created: 2019/6/2 19:20 pm
// Author: 김도현, 
// mail: donsdevko@gmail.com
class SearchBookedTicketsUI
{
private:
	static SearchBookedTicketsUI * inst;
	SearchBookedTicketsUI();
public:
	~SearchBookedTicketsUI();
	vector<Ticket *> showBookedList(Buyer *);
	static SearchBookedTicketsUI * getInstance() { return inst; }
};

