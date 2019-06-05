#include "stdafx.h"
#include "RegisterTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

RegisterTicket* RegisterTicket::registerTicketinst;

RegisterTicket::RegisterTicket()
{
}

RegisterTicket::~RegisterTicket()
{
}

// Function : static RegisterTicket* getInstance()
// Description: 싱글톤을 위해 하나의 instance를 넘겨주는 함수
// Parameters : 없음
// Return Value : registerTicketinst (RegisterTicket의 instance)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭

RegisterTicket* RegisterTicket::getInstance()
{
	if (registerTicketinst == nullptr)
		registerTicketinst = new RegisterTicket();
	return registerTicketinst;
}

// Function : void RegisterTicketUI::putTicketInfo(string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,Seller *s, string currentTime)
// Description: UI로부터 받은 티켓의 정보로 티켓을 생성하고 티켓을 seller의 ticketcollection과 hometeam의 ticketcollection에 추가한다.
// Parameters : string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,Seller *s, string currentTime
// Return Value : 없음
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
void RegisterTicket::registerNewTicket(int price,
	string matchDate,
	string homeTeam,
	string awayTeam,
	string seat,
	bool limitedTimeAuction,
	Seller *s,
	string currentTime)
{
	string sellerID = s->getID();
	Ticket *newTicket = new Ticket(price, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction, sellerID, "", currentTime);
	s->getRegisteredTickets()->add(newTicket);
	// Seller에 있는 ticketcollection에 추가
	HomeTeam * hometeam = HomeTeamCollection::getInstance()->getHomeTeamByName(homeTeam);
	hometeam->getTicketCollection()->add(newTicket);
	// HomeTeam에 있는 ticketcollection에 추가
}


