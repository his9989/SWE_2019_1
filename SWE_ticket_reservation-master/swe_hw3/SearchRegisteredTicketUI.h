#include <vector>
#include "SearchRegisteredTicket.h"
#include "memberManagement.h"


#pragma once

class SearchRegisteredTicketUI
{
private:
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* searchRegisteredTicketUIinst;
public:
	static SearchRegisteredTicketUI* getInstance();
	vector<Ticket*> searchTicket(MemberManagement*mm, string ID);
};

