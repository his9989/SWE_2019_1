#include "stdafx.h"
#include "TicketCollection.h"
#include "Ticket.h"

TicketCollection::TicketCollection() {
	// TODO Auto-generated constructor stub

}

TicketCollection::~TicketCollection() {
	// TODO Auto-generated destructor stub
}

// Function : vector<Ticket *> TicketCollection::getTickets()
// Description:
// 현재 콜렉션의 모든 티켓 포인터 벡터를 반환합니다
// Return Value : 티켓의 포인터가 담긴 벡터
//
// Created: 2019/05/28 21:10 pm
// Author: 김도현
vector<Ticket *> TicketCollection::getTickets() {
	return tickets;
}

// Function : void TicketCollection::add(Ticket * ticket)
// Description:
// 티켓콜렉션 인스턴스에 티켓을 추가합니다.
// Parameter : Ticket * ticket - 추가할 티켓 포인터
// Return Value : 홈팀의 포인터가 담긴 벡터
//
// Created: 2019/05/28 21:13 pm
// Author: 김도현
void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}

// Function : void TicketCollection::deleteTicket(Ticket* ticket)
// Description : 티켓 포인터가 저장된 벡터 중에, 매개변수로 받은 ticket과 같은 원소를 삭제
// Parameters : Ticket * ticket - 제거할 티켓 포인터
// Return Value : None
// Created: 2019/06/2 21:00 pm
// Author: 한인수
void TicketCollection::deleteTicket(Ticket* ticket) {
	// TicketCollection에 저장되어 있는 tickets vector를 iterator로 반복
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		// vector 내에 매개변수로 받은 ticket과 같은 원소가 있는 경우를 체크
		if ((*it) == ticket) {
			// 해당 vector원소를 vector.erase()로 삭제
			//cout << (*it)->getMatchDate() << endl;
			tickets.erase(it);
			break;
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

