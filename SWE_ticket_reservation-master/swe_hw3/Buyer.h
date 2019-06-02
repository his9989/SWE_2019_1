#pragma once
#include "stdafx.h"
#include "Member.h"
#include "TicketCollection.h"

class Buyer : public Member
{
	TicketCollection *bookedTickets;
public:
	Buyer();
	Buyer(string, string, string, string);
	~Buyer();
	TicketCollection* getBookedTickets();
	string getType();
};