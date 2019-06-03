//RegisterAuctionTicket.h
#ifndef _REGISTERAUCTIONTICKET_H
#define _REGISTERAUCTIONTICKET_H
#include <string>
using namespace std;

class HomeTeamCollection;
class RegisterAuctionTicket {
private:
	static RegisterAuctionTicket *instance;
	RegisterAuctionTicket();

	HomeTeamCollection *homeTeamCollection;
public:
	~RegisterAuctionTicket();
	static RegisterAuctionTicket *getInstance();

	string registerAuctionTickets(string currentTime);
};

#endif // !_REGISTERAUCTIONTICKET_H
