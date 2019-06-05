#include "RegisterTicketUI.h"
#include "memberManagement.h"

RegisterTicketUI* RegisterTicketUI::registerTicketUIinst;

RegisterTicketUI::RegisterTicketUI()
{
}

RegisterTicketUI::~RegisterTicketUI()
{
}

// Function : static RegisterTicketUI* getInstance()
// Description: 싱글톤을 위해 하나의 instance를 넘겨주는 함수
// Parameters : 없음
// Return Value : registerTicketUIinst (RegisterTicketUI의 instance)
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
RegisterTicketUI* RegisterTicketUI::getInstance()
{
	if (registerTicketUIinst == nullptr)
		registerTicketUIinst = new RegisterTicketUI();
	return registerTicketUIinst;
}

// Function : void RegisterTicketUI::putTicketInfo(string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,string ID,MemberManagement* mm, string currentTime)
// Description: 파일로부터 입력된 티켓의 정보를 main에서 받아온다.
// Description: 메인에서 받아온 membermanagement와 ID로 seller의 인스턴스를 받아온 후 티켓의 정보와 함께 RegisterTicket(control class)로 넘겨준다.
// Parameters : string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,string ID,MemberManagement* mm, string currentTime
// Return Value : 없음
// Created: 2019/5/29 12:00 pm
// Author: 김민섭
void RegisterTicketUI::putTicketInfo(string price,
	string matchDate,
	string homeTeam,
	string awayTeam,
	string seat,
	bool limitedTimeAuction,
	string ID,
	MemberManagement *mm,
	string currentTime){
	Seller *s = (mm->getMembers())->getSeller(ID);
	int intprice = atoi(price.c_str());
	RegisterTicket::getInstance()->registerNewTicket(intprice, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction, s, currentTime);
}
