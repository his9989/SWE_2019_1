//HomeTeam.h
#ifndef _HOMETEAM_H
#define _HOMETEAM_H
#include <string>
#include"TicketCollection.h"
#include "AuctionTicketCollection.h"

class Ticket;
class AuctionTicketCollection;
using namespace std;
class HomeTeam {
private:
	string name;
	string city;
	TicketCollection *ticketCollection;
	AuctionTicketCollection *auctionTicketCollection;
public:
	HomeTeam();
	HomeTeam(string, string);
	virtual ~HomeTeam();

	string getName();
	string getCity();
	TicketCollection* getTicketCollection(); // 도현 재령
	AuctionTicketCollection* getAuctionTicketCollection(); // 재령
	vector<Ticket *> listAvailableTickets(); // 도현 - 티켓들 돌려주도록 (벡터) 구현 예정 
											 // ADDED : 컬렉션 셋팅하는 함수도 필요합니다.
	void setTicketCollection(TicketCollection *);
	void setAuctionTicketCollection(AuctionTicketCollection *);

};
#endif // !_HOMETEAM_H
