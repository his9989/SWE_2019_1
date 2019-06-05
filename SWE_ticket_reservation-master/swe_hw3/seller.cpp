#include "stdafx.h"
#include "seller.h"

//Function: Seller()
//Description: Seller class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Seller::Seller() {

}

//Function: Seller(string id, string password, string name, string identificationNumber)
//Description: Seller class의 생성자. 멤버 변수를 초기화한다.
//Parameters: string id, string password, string name, string identificationNumber
//Return Value: None
//Created: 2019/06/02
Seller::Seller(string id, string password, string name, string identificationNumber) {
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	registeredTickets = new TicketCollection();
}

//Function: bool existTicket()
//Description: registeredTickets의 existTicket 함수를 부른다.
//Parameters: None
//Return Value: bool
//Created: 2019/06/02
bool Seller::existTicket() {
	return registeredTickets->existTicket();
}

//Function: string getType()
//Description: "seller" 문자열을 반환한다.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Seller::getType() {
	return "seller";
}

//Function: TicketCollection * getRegisteredTickets()
//Description: registeredTickets 객체를 반환한다.
//Parameters: None
//Return Value: TicketCollection*
//Created: 2019/06/02
TicketCollection* Seller::getRegisteredTickets()
{
	return registeredTickets;
}