#pragma once
#include "stdafx.h"
class HomeTeam;
class Buyer;
class Ticket;

// Class : SearchAvailableTickets
// Description: 티켓 검색을 제어하는 컨트롤 클래스
// Created: 2019/5/28 22:10 pm
// Author: 김도현, 
// mail: donsdevko@gmail.com
class SearchAvailableTickets
{
private:
	static SearchAvailableTickets * inst;
	SearchAvailableTickets();
public:
	static SearchAvailableTickets * getInstance() { return inst; }
	vector<Ticket *> showAvailableTickets(HomeTeam *);
	~SearchAvailableTickets();
};

