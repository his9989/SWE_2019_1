#pragma once
#include "stdafx.h"
class Buyer; 
class Ticket;

// Class : SearchBookedTickets
// Description: 바이어가 예약한 티켓을 볼수 있도록 하는 컨트롤 클래스
// Created: 2019/6/2 20:10 pm
// Author: 김도현, 
// mail: donsdevko@gmail.com
class SearchBookedTickets
{
private:
	static SearchBookedTickets * inst;
	SearchBookedTickets();
	~SearchBookedTickets();
public:
	static SearchBookedTickets * getInstance() { return inst; }
	vector<Ticket *> listBookedTickets(Buyer *);
};

