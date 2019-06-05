#pragma once
#include "stdafx.h"
#include "SearchRegisteredTicket.h"
#include "memberManagement.h"

// Class : SearchRegisteredTicketUI
// Description: boundary class·Î ¼¿·¯ÀÇ membermanagement¿Í ID·Î seller ÀÎ½ºÅÏ½º¸¦ ¹Þ¾Æ¿Â´Ù.
// Created: 2019/5/29 12:00 pm
// Author: ±è¹Î¼·
// mail: minseob17@naver.com
class SearchRegisteredTicketUI
{
private:
	SearchRegisteredTicketUI();
	static SearchRegisteredTicketUI* searchRegisteredTicketUIinst;
public:
	static SearchRegisteredTicketUI* getInstance();
	vector<Ticket*> searchTicket(MemberManagement*mm, string ID);
};

