#pragma once
#include "stdafx.h"
class HomeTeam;
class Buyer;
class Ticket;

class BookTicket
{
private:
	static BookTicket * inst;
	BookTicket();
	~BookTicket();
public:
	Ticket * bookTicket(HomeTeam *, Buyer *, map<string, string>);
	static BookTicket * getInstance() { return inst; }
};

