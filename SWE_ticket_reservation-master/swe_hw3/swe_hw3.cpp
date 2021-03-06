#include "stdafx.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"
#include "SearchAvailableTicketsUI.h"
#include "SearchBookedTicketsUI.h"
#include "Buyer.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include "signUpUI.h"
#include "deleteAccountUI.h"
#include "loginUI.h"
#include "logoutUI.h"
#include "memberManagement.h"
#include "RegisterTicketUI.h"
#include "SearchRegisteredTicketUI.h"
#include "TimerUI.h"
#include "SearchAuctionTickets.h"
#include "SearchAuctionTicketsUI.h"
#include "ParticipateAuction.h"
#include "RegisterAuctionTicket.h"
#include "CloseAuctionTicket.h"

using namespace std;

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();
string curSessionID;
string currentTime = "";
string prefix = "> ";
vector<string> split(string, char);

int main() {
	doTask();
	return 0;
}

void doTask() {
	Buyer * buyer;
	string teamName;
	MemberManagement *mm = new MemberManagement();

	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	curSessionID = "guest session";

	ofstream outFile(OUTPUT_FILE_NAME);
	ifstream inFile(INPUT_FILE_NAME);

	while (!is_program_exit) {
		//while문 돌때마다 현재시간 받아와서 갱신. 새로운 옥션티켓 추가
		RegisterAuctionTicket *registerAuctionTicket = RegisterAuctionTicket::getInstance();
		if (currentTime.compare("") != 0) {
			string result = registerAuctionTicket->registerAuctionTickets(currentTime);		//현재시간
			//cout << result;
		}
		//while문 돌 때마다 경매종료시점 검사 후 경매마감
		CloseAuctionTicket *closeAuctionTicket = CloseAuctionTicket::getInstance();
		if (currentTime.compare("") != 0) {
			string result = closeAuctionTicket->closeAuction(mm,currentTime);
			//cout << result;
		}


		string inputString;
		getline(inFile, inputString);

		// split은 하단에 정의되어 있음 
		vector<string> lineData = split(inputString, ' ');

		// lineData 는 입력받은 한줄 데이터로 index 0,1은 각각 메뉴, 서브메뉴
		menu_level_1 = stoi(lineData[0]); // 메뉴 
		menu_level_2 = stoi(lineData[1]); // 서브메뉴

		switch (menu_level_1) {
		case 1: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("회원가입\n");
				outFile << "회원 가입" << endl;
				// ytn testpwd yoo 112233 seller
				cout << prefix + lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5] + " " + lineData[6] << endl;
				outFile << prefix + lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5] + " " + lineData[6] << endl;

				SignUpUI *signUpUI = new SignUpUI(mm);
				signUpUI->createAccount(lineData[2], lineData[3], lineData[4], lineData[5], lineData[6]);
				//cout << lineData[2] <<" " << lineData[3]<< " " << lineData[4] << " " << lineData[5]<< endl;

				break;
			}
			case 2: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("회원탈퇴\n");
				outFile << "회원 탈퇴" << endl;

				DeleteAccountUI *deleteAccountUI = new DeleteAccountUI(mm);
				bool output = deleteAccountUI->deleteAccount(curSessionID);
				if (output == true) {
					cout << curSessionID << endl;
					outFile << curSessionID << endl;
				}
				else {
					cout << prefix + "판매 중인 티켓이 남아있습니다. 탈퇴가 불가능 합니다." << endl;
					outFile << prefix + "판매 중인 티켓이 남아있습니다. 탈퇴가 불가능 합니다." << endl;
				}

				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 2: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("로그인\n");
				outFile << "로그인" << endl;

				LoginUI *loginUI = new LoginUI(mm);
				bool output = loginUI->login(lineData[2], lineData[3]);
				if (output == true) {
					cout << prefix + lineData[2] << " " << lineData[3] << endl;
					outFile << prefix + lineData[2] << " " << lineData[3] << endl;
					curSessionID = lineData[2];
				}
				else {
					cout << prefix + "아이디 또는 비밀번호를 다시 확인하세요." << endl;
					outFile << prefix + "아이디 또는 비밀번호를 다시 확인하세요." << endl;
					cout << prefix + "등록되지 않은 아이디이거나, 아이디 또는 비밀번호를 잘못 입력하셨습니다." << endl;
					outFile << prefix + "등록되지 않은 아이디이거나, 아이디 또는 비밀번호를 잘못 입력하셨습니다." << endl;
				}
				break;
			}
			case 2: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("로그아웃\n");
				outFile << "로그아웃" << endl;

				LogoutUI *logoutUI = new LogoutUI(mm);
				logoutUI->logout(curSessionID);
				cout << prefix + curSessionID << endl;
				outFile << prefix + curSessionID << endl;
				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("판매티켓 등록\n");
				outFile << "판매티켓 등록" << endl;

				bool _limitedTimeAuction;

				if (lineData[7] == "1")
					_limitedTimeAuction = true;
				else
					_limitedTimeAuction = false;

				RegisterTicketUI::getInstance()->putTicketInfo(lineData[2], lineData[3], lineData[4], lineData[5], lineData[6], _limitedTimeAuction, curSessionID, mm, currentTime);
				// price, matchDate, homeTeam, awayTeam, seat, limitedTimeAuction
				cout << prefix + lineData[2] << " " << lineData[3] << " " << lineData[4] << " " << lineData[5] << " " << lineData[6] << " " << _limitedTimeAuction << endl;
				outFile << prefix + lineData[2] << " " << lineData[3] << " " << lineData[4] << " " << lineData[5] << " " << lineData[6] << " " << _limitedTimeAuction << endl;
				//cout << HomeTeamCollection::getInstance()->getHomeTeams()[0]->getTicketCollection()->getTickets().size() << endl;
				//cout << ht->getName() << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("등록티켓 조회\n");
				outFile << "등록티켓 조회" << endl;
				vector<Ticket*> tickets = SearchRegisteredTicketUI::getInstance()->searchTicket(mm, curSessionID);
				//sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket* ticket = tickets[i]->getTicket();
					bool ticketSolded = !(ticket->getAvailability());
					cout << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() + " " + to_string(ticket->getLimitedTimeAuction()) + " " + to_string(ticketSolded) << endl;
					outFile << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() + " " + to_string(ticket->getLimitedTimeAuction()) + " " + to_string(ticketSolded) << endl;
				}
			}
			}
			break;
		}
		case 4: {
			switch (menu_level_2) {
			case 1: {
				buyer = (mm->getMembers())->getBuyer(curSessionID);
				teamName = lineData[2];
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("티켓 검색\n");
				outFile << "티켓 검색" << endl;

				vector<Ticket *> tickets = SearchAvailableTicketsUI::getInstance()->startInterface(buyer, teamName);
				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					if (ticket->getAvailability()) {
						// [희망가격] [날짜-시간] [홈팀] [어웨이팀] [좌석위치]
						cout << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
						outFile << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					}
				}
				break;
			}
			case 2: {
				buyer = (mm->getMembers())->getBuyer(curSessionID);
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("티켓 예약\n");
				outFile << "티켓 예약" << endl;
				HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
				Ticket * bookedTicket = SearchAvailableTicketsUI::getInstance()->buyTicketInterface(buyer, homeTeam, lineData[2], lineData[3], lineData[4], currentTime);
				cout << prefix + to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				outFile << prefix + to_string(bookedTicket->getPrice()) + " " + bookedTicket->getMatchDate() + " " + bookedTicket->getHomeTeam() + " " + bookedTicket->getAwayTeam() + " " + bookedTicket->getSeat() << endl;
				break;
			}
			case 3: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("경매 중인 티켓 검색\n");
				outFile << "경매 중인 티켓 검색" << endl;

				SearchAuctionTicketsUI *searchAuctionTicketsUI = SearchAuctionTicketsUI::getInstance();
				string result = searchAuctionTicketsUI->selectHomeTeam(lineData[2], currentTime);			//홈팀, 현재시간
				outFile << prefix + result << endl;

				break;
			}
			case 4: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("경매 참여\n");
				outFile << "경매 참여" << endl;

				SearchAuctionTicketsUI *searchAuctionTicketsUI = SearchAuctionTicketsUI::getInstance();
				string bidAmount = searchAuctionTicketsUI->selectParticipateAuction(curSessionID, lineData[2], lineData[3], lineData[4], lineData[5]); // buyerID도 넘겨주기! [날짜-시간] [어웨이팀] [좌석위치] [입찰금액]
				cout << prefix + bidAmount << endl;
				outFile << prefix + bidAmount << endl;

				break;
			}
			case 5: {
			    buyer = (mm->getMembers())->getBuyer(curSessionID);
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("예약 정보 조회\n");
				outFile << "예약 정보 조회" << endl;
				vector<Ticket *> tickets = SearchBookedTicketsUI::getInstance()->showBookedList(buyer);

				sort(tickets.begin(), tickets.end(), Ticket::compare);
				for (int i = 0; i < tickets.size(); i++) {
					Ticket * ticket = tickets[i]->getTicket();
					cout << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
					outFile << prefix + to_string(ticket->getPrice()) + " " + ticket->getMatchDate() + " " + ticket->getHomeTeam() + " " + ticket->getAwayTeam() + " " + ticket->getSeat() << endl;
				}
			}
			}
			break;
		}
		case 5: {
			cout << menu_level_1 << "." << menu_level_2 << ".";
			outFile << menu_level_1 << "." << menu_level_2 << ".";
			printf("현재시간 설정\n");
			outFile << "현재시간 설정" << endl;
			cout << prefix + lineData[2] << endl;
			currentTime = lineData[2];
			outFile << prefix + currentTime << endl;
			TimerUI timerUI;
			// timerUI(바운더리 클래스)의 checkTicket 함수 호출.
			// 매개변수로 현재시간과, memberManagement의 포인터 객체를 전달
			timerUI.checkTicket(currentTime, mm);
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("session 변경\n");
				outFile << "session 변경" << endl;
				curSessionID = lineData[2];
				cout << prefix + lineData[2] << endl;
				outFile << prefix + lineData[2] << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << "." << menu_level_2 << ".";
				outFile << menu_level_1 << "." << menu_level_2 << ".";
				printf("guest session으로 변경\n");
				outFile << "guest session으로 변경" << endl;
				curSessionID = "guest session";
				break;
			}
			}
			break;
		}
		case 7: {
			cout << menu_level_1 << "." << menu_level_2 << ".";
			outFile << menu_level_1 << "." << menu_level_2 << ".";
			printf("종료\n");
			outFile << "종료" << endl;
			is_program_exit = 1;
			break;
		}
		}
	}
}

// Function : vector<string> split(string str, char delimiter)
// Description:
// 스트링으로 받은 입력을 delimeter 기준으로 split 하는 함수입니다. 
// 인풋을 각 변수로 분리할 때 사용합니다.
// Parameters : string str ? 스플릿 할 스트링 입력입니다
// char delimiter ? 무엇으로 스플릿 할지 판단하는 변수입니다.
// Return Value : 스플릿된 요소들이 담긴 벡터
// Created: 2019/06/01 18:31 pm
// Author: 김도현
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}