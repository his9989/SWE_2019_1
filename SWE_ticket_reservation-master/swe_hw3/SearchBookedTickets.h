#pragma once
#include "stdafx.h"
class Buyer; 
class Ticket;

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

