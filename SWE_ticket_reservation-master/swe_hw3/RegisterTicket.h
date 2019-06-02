#pragma once

#include <string>
#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"
#include "MemberCollection.h"
#include "MemberManagement.h"
using namespace std;

class RegisterTicket
{
private:
	RegisterTicket();
	static RegisterTicket* registerTicketinst;
public:
	static RegisterTicket* getInstance();
	void registerNewTicket(int _price,
		string _matchDate,
		string _homeTeam,
		string _awayTeam,
		string _seat,
		bool _limitedTimeAuction,
		Seller* s);
	~RegisterTicket();
};

