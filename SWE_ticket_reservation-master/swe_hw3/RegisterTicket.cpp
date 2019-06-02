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

RegisterTicket* RegisterTicket::getInstance()
{
	if (registerTicketinst == nullptr)
		registerTicketinst = new RegisterTicket();
	return registerTicketinst;
}

void RegisterTicket::registerNewTicket(int _price,
	string _matchDate,
	string _homeTeam,
	string _awayTeam,
	string _seat,
	bool _limitedTimeAuction,
	Seller *s)
{
	Ticket *newTicket = new Ticket(_price, _matchDate, _homeTeam, _awayTeam, _seat, _limitedTimeAuction);
	s->getRegisteredTickets().add(newTicket);
	// Seller에 있는 ticketcollection에 추가

	HomeTeam * hometeam = HomeTeamCollection::getInstance()->getHomeTeamByName(_homeTeam);
	hometeam->getTicketCollection().add(newTicket);
	// HomeTeam에 있는 ticketcollection에 추가
}


