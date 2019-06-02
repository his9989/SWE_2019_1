#include "seller.h"
Seller::Seller() {

}

Seller::Seller(string id, string password, string name, string identificationNumber) {
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	registeredTickets = TicketCollection::TicketCollection();
}
bool Seller::existTicket() {
	return registeredTickets.existTicket();
}

string Seller::getType() {
	return "seller";
}

TicketCollection Seller::getRegisteredTickets()
{
	return registeredTickets;
}