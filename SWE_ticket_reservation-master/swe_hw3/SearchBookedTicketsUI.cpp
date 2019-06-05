#include "stdafx.h"
#include "SearchBookedTicketsUI.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"

SearchBookedTicketsUI::SearchBookedTicketsUI()
{
}


SearchBookedTicketsUI::~SearchBookedTicketsUI()
{
}

// Function : vector<Ticket *> SearchBookedTicketsUI::showBookedList(Buyer * buyer)
// Description:
// 예약된 리스트를 반환받기 위한 바운더리 클래스의 함수
// Parameter : Buyer * buyer - 티켓 바이어
// Return Value : 바이어가 예약한 Ticket 포인터 벡터를 리턴합니다.
//
// Created: 2019/06/02 21:10 pm
// Author: 김도현
vector<Ticket *> SearchBookedTicketsUI::showBookedList(Buyer * buyer) {
	return SearchBookedTickets::getInstance()->listBookedTickets(buyer);
}

SearchBookedTicketsUI * SearchBookedTicketsUI::inst;