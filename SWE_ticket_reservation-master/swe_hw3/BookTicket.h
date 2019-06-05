#pragma once
#include "stdafx.h"
class HomeTeam;
class Buyer;
class Ticket;

// Class : BookTicket
// Description: 티켓 예약의 한 부분을 담당하는 컨트롤 클래스
// Created: 2019/5/28 21:30 pm
// Author: 김도현, 
// mail: donsdevko@gmail.com
class BookTicket
{
private:
	static BookTicket * inst;
	BookTicket();
	~BookTicket();
public:
	Ticket * bookTicket(HomeTeam *, Buyer *, map<string, string>, string);
	static BookTicket * getInstance() { return inst; }
};

