//CloseAuctionTicket.cpp
#include "CloseAuctionTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"
#include "AuctionTicket.h"
#include "Ticket.h"
#include "Buyer.h"
#include "seller.h"
#include "SearchAvailableTicketsUI.h"
#include <time.h>

CloseAuctionTicket* CloseAuctionTicket::instance;

CloseAuctionTicket::CloseAuctionTicket() {
	this->homeTeamCollection = HomeTeamCollection::getInstance();
}

CloseAuctionTicket::~CloseAuctionTicket() {
}

CloseAuctionTicket* CloseAuctionTicket::getInstance() {
	CloseAuctionTicket *newInstance;
	if (instance == nullptr) {
		instance = new CloseAuctionTicket();
	}
	newInstance = instance;
	return newInstance;
}

vector<string> split(string str, char delimiter);
string CloseAuctionTicket::closeAuction(MemberManagement *mm, string currentTime) {
	string out;
	//낙찰 및 유찰: 경매대상으로 등록된 티켓의 경매종료시점에 입찰액이 높은 순서로 낙찰된다. 입찰에 참여한 회원이 없는 경우에는 유찰이 된다.

	vector<string> current = split(currentTime, ':');		//현재시간
	int year = stoi(current[0]);
	int month = stoi(current[1]);
	int day = stoi(current[2]);
	int hour = stoi(current[3]);
	int min = stoi(current[4]);

	struct tm currentDate = {};
	currentDate.tm_year = year - 1900;
	currentDate.tm_mon = month - 1;
	currentDate.tm_mday = day;
	currentDate.tm_hour = hour;
	currentDate.tm_min = min;
	time_t currentDateT = mktime(&currentDate);

	vector<HomeTeam*> homeTeams = homeTeamCollection->getHomeTeams();
	vector<AuctionTicket*> tickets;

	int i = 0;
	vector<AuctionTicket*>::iterator it;
	bool flag;
	for (i = 0; i < homeTeams.size(); i++) {
		tickets = homeTeams.at(i)->getAuctionTicketCollection()->getTickets();

		for (it = tickets.begin(); it != tickets.end();it++) {

			flag = false;
			string closingTime = (*it)->getClosingTime();		//티켓의 경매종료 시점
			vector<string> vClosingTime = split(closingTime, ':');
			year = stoi(vClosingTime[0]);
			month = stoi(vClosingTime[1]);
			day = stoi(vClosingTime[2]);
			hour = stoi(vClosingTime[3]);
			min = stoi(vClosingTime[4]);

			struct tm closingTimeS = {};
			closingTimeS.tm_year = year - 1900;
			closingTimeS.tm_mon = month - 1;
			closingTimeS.tm_mday = day;
			closingTimeS.tm_hour = hour;
			closingTimeS.tm_min = min;
			time_t closingTimeT = mktime(&closingTimeS);

			//현재시간-경매종료시점 시간차 구하기
			double     d_diff;
			d_diff = difftime(closingTimeT, currentDateT);		//double difftime( time_t timeEnd, time_t timeStart );

			if (d_diff <= 0) {		//마감시간이 지났거나 현재시간과 같은경우
				flag = true;
			}

			if (flag == true) {	//경매 종료시점에 도달한 경우
				//셀러에있는 티켓 찾기
				Seller *seller = (mm->getMembers())->getSeller((*it)->getSellerID());
				vector<Ticket*> registeredTickets = seller->getRegisteredTickets()->getTickets();
				bool same; 
				vector<Ticket*>::iterator itt;
				for (itt = registeredTickets.begin(); itt != registeredTickets.end(); itt++) {
					same = (*itt)->isSame((*itt), (*it));
					if (same) {
						break;
					}
				}

				//Ticket *ticket = new Ticket((*it)->getPrice(), (*it)->getMatchDate(), (*it)->getHomeTeam(), (*it)->getAwayTeam(), (*it)->getSeat(), (*it)->getLimitedTimeAuction(), (*it)->getSellerID(), (*it)->getBuyerID());
				homeTeams[i]->getTicketCollection()->add(*itt);				//티켓 추가 - availability false
				
				if ((*it)->getBuyerID() != "") {	//경매 참여자가 있는 경우 - 낙찰
					Buyer *buyer = (mm->getMembers())->getBuyer((*it)->getBuyerID());		//buyer 구매티켓에 추가
					(*itt)->bookTicket(buyer,currentTime);
					}
				
				homeTeams[i]->getAuctionTicketCollection()->deleteTicket(*it);		//옥션티켓 삭제

				out.append(to_string((*itt)->getPrice())); out.append(" ");
				out.append((*itt)->getMatchDate()); out.append(" ");
				out.append((*itt)->getHomeTeam()); out.append(" ");
				out.append((*itt)->getAwayTeam()); out.append(" ");
				out.append((*itt)->getSeat());
				out.append("\n");
			}
		}
	}
	return out;
}