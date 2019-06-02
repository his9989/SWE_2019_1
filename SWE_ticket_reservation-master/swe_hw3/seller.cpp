#include "seller.h"
Seller::Seller() {

}

Seller::Seller(string id, string password, string name, string identificationNumber) {
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	registeredTickets = TicketCollection();
}
bool Seller::existTicket() {
	/*if (registeredTickets == NULL){
	return true;
	}
	else{
	return false;
	}
	*/
	return true;
}

string Seller::getType() {
	return "Seller";
}

TicketCollection Seller::getRegisteredTickets()
{
	return registeredTickets;
}