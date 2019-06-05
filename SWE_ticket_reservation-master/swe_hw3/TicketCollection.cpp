#include "stdafx.h"
#include "TicketCollection.h"
#include "Ticket.h"

TicketCollection::TicketCollection() {
	// TODO Auto-generated constructor stub

}

TicketCollection::~TicketCollection() {
	// TODO Auto-generated destructor stub
}

vector<Ticket *> TicketCollection::getTickets() {
	return tickets;
}

// Function : void TicketCollection::add(Ticket * ticket)
// Description: Ticket vector인 tickets에 새로운 ticket 인스턴스를 추가한다.
// Parameters : Ticket * ticket
// Return Value : 없음
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}


void TicketCollection::deleteTicket(Ticket* ticket) {
	// TicketCollection에 저장되어 있는 tickets vector를 iterator로 반복
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();) {
		// vector 내에 매개변수로 받은 ticket과 같은 원소가 있는 경우를 체크
		if ((*it) == ticket) {
			// 해당 vector원소를 vector.erase()로 삭제
			it = tickets.erase(it);
		}
		else {
			it++;
		}
	}
}

void TicketCollection::setAvailability(Ticket* ticket, bool availability) {
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();it++) {
		if ((*it) == ticket) {
			(*it)->setAvailability(availability);
		}
	}
}

bool TicketCollection::existTicket() {
	if (tickets.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

