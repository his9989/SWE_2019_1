#pragma once
#include "stdafx.h"
class Buyer;
class Ticket;

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

