#include "stdafx.h"
#include "Buyer.h"
#include "memberManagement.h"

//Function: Buyer()
//Description : Buyer class의 기본 생성자
//Parameters : None
//Return Value : None
//Created : 2019 / 06 / 02
Buyer::Buyer()
{
}

//Function: Buyer(string id, string password, string name, string identificationNumber)
//Description: Buyer class의 생성자. 멤버 변수를 초기화한다.
//Parameters: string id, string password, string name, string identificationNumber
//Return Value: None
//Created: 2019/06/02
Buyer::Buyer(string id, string password, string name, string identificationNumber)
{
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	bookedTickets = new TicketCollection();
}

//Function: ~Buyer()
//Description: Buyer class의 소멸자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Buyer::~Buyer()
{
}

//Function: TicketCollection * getBookedTickets()
//Description: bookedTickets 객체를 반환한다.
//Parameters: None
//Return Value: TicketCollection*
//Created: 2019/06/02
TicketCollection* Buyer::getBookedTickets() {
	return bookedTickets;
}

//Function: string getType()
//Description: "buyer" 문자열을 반환한다.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Buyer::getType() {
	return "buyer";
}

/* virtual existTicket() 구현 필요 */