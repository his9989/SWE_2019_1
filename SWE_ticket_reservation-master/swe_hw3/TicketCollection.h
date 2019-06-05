#pragma once
#include "stdafx.h"
class Ticket;

// Class : TicketCollection
// Description: 티켓들의 포인터를 담아놓은 콜렉션 클래스입니다
// Created: 2019/5/28 20:30 pm
// Author: 김도현
// mail: donsdevko@gmail.com
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
