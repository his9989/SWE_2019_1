#include "RegisterTicketUI.h"
#include "memberManagement.h"

RegisterTicketUI* RegisterTicketUI::registerTicketUIinst;

RegisterTicketUI::RegisterTicketUI()
{
}

RegisterTicketUI::~RegisterTicketUI()
{
}

RegisterTicketUI* RegisterTicketUI::getInstance()
{
	if (registerTicketUIinst == nullptr)
		registerTicketUIinst = new RegisterTicketUI();
	return registerTicketUIinst;
}

void RegisterTicketUI::putTicketInfo(string _price,
	string _matchDate,
	string _homeTeam,
	string _awayTeam,
	string _seat,
	bool _limitedTimeAuction,
	string ID,
	MemberManagement *mm){
	Seller *s = (mm->getMembers())->getSeller(ID);
	int price = atoi(_price.c_str());
	RegisterTicket::getInstance()->registerNewTicket(price, _matchDate, _homeTeam, _awayTeam, _seat, _limitedTimeAuction, s);
}
