#include "stdafx.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"
#include "TicketCollection.h"

SearchBookedTickets::SearchBookedTickets()
{
}


SearchBookedTickets::~SearchBookedTickets()
{
}

// Function : vector<Ticket *> SearchBookedTickets::listBookedTickets(Buyer * buyer)
// Description:
// 예약된 모든 티켓 포인터 벡터를 반환합니다
// Parameter : Buyer * buyer - 조회를 요청한 바이어
// Return Value : 예약된 티켓의 포인터가 담긴 벡터
//
// Created: 2019/06/02 19:15 pm
// Author: 김도현
vector<Ticket *> SearchBookedTickets::listBookedTickets(Buyer * buyer) {
	return buyer->getBookedTickets()->getTickets();
}

SearchBookedTickets * SearchBookedTickets::inst;