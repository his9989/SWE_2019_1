#include "stdafx.h"
#include "SearchAvailableTickets.h"
#include "SearchAvailableTicketsUI.h"
#include "HomeTeam.h"

SearchAvailableTickets::SearchAvailableTickets()
{
}


SearchAvailableTickets::~SearchAvailableTickets()
{
}

// Function : vector<Ticket *> SearchAvailableTickets::showAvailableTickets(HomeTeam * homeTeam)
// Description:
// 넘겨진 홈팀에 대한 모든 티켓 포인터 벡터를 반환합니다
// Parameters : HomeTeam * homeTeam - 홈팀 포인터
// Return Value : 검색된 티켓의 포인터가 담긴 벡터
//
// Created: 2019/05/28 23:15 pm
// Author: 김도현
vector<Ticket *> SearchAvailableTickets::showAvailableTickets(HomeTeam * homeTeam) {
	return homeTeam->listAvailableTickets();
}

SearchAvailableTickets * SearchAvailableTickets::inst;