#include "SearchRegisteredTicketUI.h"

SearchRegisteredTicketUI* SearchRegisteredTicketUI::searchRegisteredTicketUIinst;

SearchRegisteredTicketUI::SearchRegisteredTicketUI() {}

SearchRegisteredTicketUI* SearchRegisteredTicketUI::getInstance()
{
	if (searchRegisteredTicketUIinst == nullptr)
		searchRegisteredTicketUIinst = new SearchRegisteredTicketUI;
	return searchRegisteredTicketUIinst;
}

vector<Ticket*> SearchRegisteredTicketUI::searchTicket(MemberManagement* mm, string ID)
{
	Seller *s = (mm->getMembers())->getSeller(ID);
	return  SearchRegisteredTicket::getInstance()->listTIcket(s);
}
