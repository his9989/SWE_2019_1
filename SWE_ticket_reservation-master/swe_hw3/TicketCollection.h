#pragma once
#include "stdafx.h"
class Ticket;

// Class : TicketCollection
// Description: collection class로 Ticket 인스턴스들을 저장하고 관리한다.
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
// mail: minseob17@naver.com
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
