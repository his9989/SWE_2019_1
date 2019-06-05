#pragma once
#include "stdafx.h"
#include "member.h"
#include "ticketCollection.h"

//Class : Seller
//Description:    This is Entity Class. And This is subclass of Member. 
//				Seller is the person who sells the ticket using this system.
//				So this class do the job about basic action for getting seller's information.
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
// 
//Revisions
class Seller : public Member {

private:
	TicketCollection * registeredTickets;

public:
	Seller();
	Seller(string, string, string, string);
	bool existTicket();
	string getType();
	TicketCollection * getRegisteredTickets();

};
