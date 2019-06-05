#pragma once
#include "stdafx.h"
class HomeTeam;
class HomeTeamCollection;
class Buyer;
class Ticket;

// Class : SearchAvailableTicketsUI
// Description: 현재 예약가능한 티켓을 보고 extend로 티켓 예약을 위한 UI 클래스
// Created: 2019/5/29 23:10 pm
// Author: 김도현
// mail: donsdevko@gmail.com
class SearchAvailableTicketsUI
{
private:
	static SearchAvailableTicketsUI * inst;
	SearchAvailableTicketsUI();
public:
	~SearchAvailableTicketsUI();
	static SearchAvailableTicketsUI * getInstance() { return inst; }
	vector<Ticket *> startInterface(Buyer *, string);
	Ticket * buyTicketInterface(Buyer *, HomeTeam *, string, string, string, string);
};

