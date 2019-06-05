#pragma once
#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"

// Class : SearchRegisteredTicket
// Description: controll class로 셀러의 티켓콜렉션으로부터 vector<Ticket*>를 받아온다.
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
// mail: minseob17@naver.com
class SearchRegisteredTicket
{
private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* searchRegisteredTicketinst;
public:
	static SearchRegisteredTicket* getInstance();
	vector<Ticket*> listTIcket(Seller *s);
};

