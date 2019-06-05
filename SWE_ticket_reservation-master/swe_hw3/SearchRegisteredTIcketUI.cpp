#include "stdafx.h"
#include "SearchRegisteredTicketUI.h"
#include "memberManagement.h"

SearchRegisteredTicketUI* SearchRegisteredTicketUI::searchRegisteredTicketUIinst;

SearchRegisteredTicketUI::SearchRegisteredTicketUI() {}

// Function : static SearchRegisteredTicketUI* getInstance()
// Description: 싱글톤을 위해 하나의 instance를 넘겨주는 함수
// Parameters : 없음
// Return Value : SearchRegisteredTicketUIinst (SearchRegisteredTicketUI의 instance)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
SearchRegisteredTicketUI* SearchRegisteredTicketUI::getInstance()
{
	if (searchRegisteredTicketUIinst == nullptr)
		searchRegisteredTicketUIinst = new SearchRegisteredTicketUI;
	return searchRegisteredTicketUIinst;
}

// Function : vector<Ticket*> SearchRegisteredTicketUI::searchTicket(MemberManagement* mm, string ID)
// Description: membermanagement와 ID로 seller 인스턴스를 받아온 후 SearchRegisteredTicket으로 넘겨준다.
// Parameters : MemberManagement* mm, string ID
// Return Value : vector<Ticket*> (control class에서 ricketcollection에 있는 vector 받아올 예정)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
vector<Ticket*> SearchRegisteredTicketUI::searchTicket(MemberManagement* mm, string ID)
{
	Seller *s = (mm->getMembers())->getSeller(ID);
	return  SearchRegisteredTicket::getInstance()->listTIcket(s);
}
