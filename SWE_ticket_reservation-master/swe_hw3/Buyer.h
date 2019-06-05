#pragma once
#include "stdafx.h"
#include "Member.h"
#include "TicketCollection.h"

//Class : Buyer
//Description:    This is Entity Class. And This is subclass of Member. 
//				Buyer is the person who buys the ticket using this system.
//				So this class do the job about basic action for getting buyer's information.
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class Buyer : public Member
{
	TicketCollection *bookedTickets;
public:
	Buyer();
	Buyer(string, string, string, string);
	~Buyer();
	TicketCollection* getBookedTickets();
	string getType();
};