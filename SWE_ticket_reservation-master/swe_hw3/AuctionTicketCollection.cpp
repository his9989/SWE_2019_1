//AuctionTicketCollection.cpp
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include <vector>
#include <iostream>
using namespace std;

AuctionTicketCollection::AuctionTicketCollection() {
}

AuctionTicketCollection::~AuctionTicketCollection() {
}

// Function : void AuctionTicketCollection::add(AuctionTicket *ticket)
// Description: AuctionTicketCollection의 옥션티켓벡터에 옥션티켓을 추가하는 함수.
// Parameters : AuctionTicket *ticket - 옥션티켓의 포인터
// Return Value :  None
// Created: 2019/06/29  
// Author: 안재령
void AuctionTicketCollection::add(AuctionTicket *ticket) {
	this->tickets.push_back(ticket);
}

// Function : void AuctionTicketCollection::deleteTicket(AuctionTicket* ticket) 
// Description: AuctionTicketCollection의 옥션티켓벡터에서 옥션티켓을 삭제하는 함수
// Parameters : AuctionTicket *ticket - 옥션티켓의 포인터
// Return Value :  None
// Created: 2019/06/29  
// Author: 안재령
void AuctionTicketCollection::deleteTicket(AuctionTicket* ticket) {
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end();) {
		if ((*it) == ticket) {
			it = tickets.erase(it);
		}
		else {
			it++;
		}
	}
}

// Function : void AuctionTicketCollection::updateBidAmount(AuctionTicket* ticket, int bidAmount) 
// Description: AuctionTicketCollection의 옥션티켓벡터에서 옥션티켓의 입찰액을 업데이트하는 함수
// Parameters : AuctionTicket *ticket - 옥션티켓의 포인터
//					int BidAmount - 입찰 금액
// Return Value :  None
// Created: 2019/06/29  
// Author: 안재령
void AuctionTicketCollection::updateBidAmount(AuctionTicket* ticket, int bidAmount) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBidAmount(bidAmount);
		}
	}
}

// Function : void AuctionTicketCollection::updateBuyerID(AuctionTicket* ticket, string buyerID)
// Description: AuctionTicketCollection의 옥션티켓벡터에서 옥션티켓의 구매자아이디를 업데이트하는 함수
// Parameters : AuctionTicket *ticket - 옥션티켓의 포인터
//					string buyerID - 구매자 아이디 (옥션의 낙찰자)
// Return Value :  None
// Created: 2019/06/29  
// Author: 안재령
void AuctionTicketCollection::updateBuyerID(AuctionTicket* ticket, string buyerID) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBuyerID(buyerID);
		}
	}
}

vector<AuctionTicket*> AuctionTicketCollection::getTickets() { return tickets; }

int AuctionTicketCollection::getSize() {
	return this->tickets.size();

}