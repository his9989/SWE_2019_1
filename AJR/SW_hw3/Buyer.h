#pragma once
#include "stdafx.h"
#include "Member.h"
#include "TicketCollection.h"


class Buyer : public Member

{

public:

	TicketCollection bookedTickets;

	Buyer();

	Buyer(string, string, string, string, string, string);

	~Buyer();

};