#pragma once
#include "stdafx.h"
#include "SearchRegisteredTicket.h"
#include "memberManagement.h"


class SearchRegisteredTicketUI
{
private:
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* searchRegisteredTicketUIinst;
public:
	static SearchRegisteredTicketUI* getInstance();
	vector<Ticket*> searchTicket(MemberManagement*mm, string ID);
};

