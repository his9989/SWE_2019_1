#ifndef _TICKETCOLLECTION_H
#define _TICKETCOLLECTION_H
#include <vector>
using namespace std;

class Ticket;
class TicketCollection {
private:
	vector<Ticket*> tickets;
	
public:
	TicketCollection();
	virtual ~TicketCollection();
	void add(Ticket *ticket);

	vector<Ticket*> getTickets();
};

#endif // !_TICKETCOLLECTION_H
