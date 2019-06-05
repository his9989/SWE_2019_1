#include "stdafx.h"
#include "SearchRegisteredTicket.h"

SearchRegisteredTicket* SearchRegisteredTicket::searchRegisteredTicketinst;

SearchRegisteredTicket::SearchRegisteredTicket() {}

// Function : SearchRegisteredTicket* SearchRegisteredTicket::getInstance()
// Description: 싱글톤을 위해 하나의 instance를 넘겨주는 함수
// Parameters : 없음
// Return Value : searchRegisteredTicketinst (SearchRegisteredTicket의 instance)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
SearchRegisteredTicket* SearchRegisteredTicket::getInstance()
{
	if (searchRegisteredTicketinst == nullptr)
		searchRegisteredTicketinst = new SearchRegisteredTicket;
	return searchRegisteredTicketinst;
}

// Function : vector<Ticket*> SearchRegisteredTicket::listTIcket(Seller* s)
// Description: seller에 있는 ticketcollection에서 vector<Ticket*>를 가져와서 리턴한다.
// Parameters : Seller* s
// Return Value : vector<Ticket*> (s->getRegisteredTickets()->getTickets()와 같다)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
vector<Ticket*> SearchRegisteredTicket::listTIcket(Seller* s)
{
	return s->getRegisteredTickets()->getTickets();
}

