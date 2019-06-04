//SearchAuctionTicketsUI.cpp
#include "SearchAuctionTicketsUI.h"
#include "SearchAuctionTickets.h"
#include "ParticipateAuction.h"
#include "HomeTeam.h"
#include "AuctionTicket.h"
#include <iostream>


SearchAuctionTicketsUI* SearchAuctionTicketsUI::instance;

SearchAuctionTicketsUI::SearchAuctionTicketsUI() {

}

SearchAuctionTicketsUI::~SearchAuctionTicketsUI() {

}

SearchAuctionTicketsUI* SearchAuctionTicketsUI::getInstance() {
	SearchAuctionTicketsUI *newInstance;
	if (instance == nullptr) {
		instance = new SearchAuctionTicketsUI();
	}
	newInstance = instance;
	return newInstance;
}

void SearchAuctionTicketsUI::startInterface(vector<HomeTeam*> homeTeams) {

}

vector<string> split(string str, char delimiter);
string SearchAuctionTicketsUI::selectHomeTeam(string teamName, string currentTime) {
	this->teamName = teamName;

	vector<AuctionTicket*> auctionTickets = SearchAuctionTickets::getInstance()->showHomeTeamAuctionTickets(teamName);
	string out;

	int i = 0;
	while (i < (int)auctionTickets.size()) {

		AuctionTicket *ticket = auctionTickets[i];

		vector<string> closingTime = split(ticket->getClosingTime(), ':');		//마감시간
		int year = stoi(closingTime[0]);
		int month = stoi(closingTime[1]);
		int day = stoi(closingTime[2]);
		int hour = stoi(closingTime[3]);
		int min = stoi(closingTime[4]);

		struct tm closingTimeS = {};
		closingTimeS.tm_year = year - 1900;
		closingTimeS.tm_mon = month - 1;
		closingTimeS.tm_mday = day;
		closingTimeS.tm_hour = hour;
		closingTimeS.tm_min = min;
		time_t closingTimeT = mktime(&closingTimeS);

		vector<string> currentTimeV = split(currentTime, ':');		//현재시간
		year = stoi(currentTimeV[0]);
		month = stoi(currentTimeV[1]);
		day = stoi(currentTimeV[2]);
		hour = stoi(currentTimeV[3]);
		min = stoi(currentTimeV[4]);

		struct tm currentTimeS = {};
		currentTimeS.tm_year = year - 1900;
		currentTimeS.tm_mon = month - 1;
		currentTimeS.tm_mday = day;
		currentTimeS.tm_hour = hour;
		currentTimeS.tm_min = min;
		time_t currentTimeT = mktime(&currentTimeS);

		//마감까지 남은 시간 계산
		double d_diff = difftime(closingTimeT, currentTimeT);		//double difftime( time_t timeEnd, time_t timeStart );
		int printHour = d_diff / 3600;
		int printMin = (d_diff - printHour * 3600) / 60;

		//struct tm remainS = {};
		//remainS.tm_min = (int)difftime;
		//time_t remainT = mktime(&remainS);



		string remainTimeString;
		remainTimeString.append(to_string(printHour)); remainTimeString.append(":");
		remainTimeString.append(to_string(printMin));

		cout << to_string(ticket->getPrice()) +" " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() + " " + remainTimeString << endl;

		out.append(to_string(ticket->getPrice())); out.append(" ");
		out.append(ticket->getMatchDate()); out.append(" ");
		out.append(ticket->getHomeTeam()); out.append(" ");
		out.append(ticket->getAwayTeam()); out.append(" ");
		out.append(ticket->getSeat()); out.append(" ");
		out.append(remainTimeString);
		if (i != auctionTickets.size() - 1) {
			out.append("\n");
		}
		i++;
	}
	return out;
}

string SearchAuctionTicketsUI::selectParticipateAuction(string buyerID, string matchDate, string awayTeam, string seat, string bidAmount) {
	int intBidAmount = stoi(bidAmount);
	vector<AuctionTicket*> tickets = SearchAuctionTickets::getInstance()->showHomeTeamAuctionTickets(this->teamName);
	AuctionTicket *ticket;
	bool flag;
	vector<AuctionTicket*>::iterator it;
	for (it = tickets.begin(); it != tickets.end(); it++) {
		ticket = (*it);
		flag = false;
		if (matchDate.compare(ticket->getMatchDate()) == 0 && awayTeam.compare(ticket->getAwayTeam()) == 0 && seat.compare(ticket->getSeat()) == 0) {
			flag = true;
			break;
		}
	}
	ParticipateAuction::getInstance()->participateAuction(this->teamName, (*it), buyerID, intBidAmount);

	return to_string((*it)->getBidAmount());
}

string SearchAuctionTicketsUI::getTeamName() { return this->teamName; }