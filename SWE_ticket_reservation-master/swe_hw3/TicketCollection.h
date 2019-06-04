#pragma once
#include "stdafx.h"
class Ticket;

class TicketCollection {

private:
	vector<Ticket *> tickets;

public:
	TicketCollection();
	virtual ~TicketCollection();
	void add(Ticket *);
	void deleteTicket(Ticket *);
	bool existTicket();
	void setAvailability(Ticket* ticket, bool availability);
	vector<Ticket *> getTickets();
};
