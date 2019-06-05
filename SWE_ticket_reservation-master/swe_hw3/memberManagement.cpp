#include "stdafx.h"
#include "memberManagement.h"
#include "member.h"
#include "seller.h"
#include "buyer.h"
using namespace std;

//Function: MemberManagement()
//Description: MemberManagement class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberManagement::MemberManagement() {
	member = new MemberCollection();
}

//Function: ~MemberManagement()
//Description: MemberManagement class의 소멸자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberManagement::~MemberManagement() {

}

//Function: void createAccount(string type, string id, string password, string name, string identificationNumber)
//Description: 새로운 멤버의 type을 확인하고 해당 type의 멤버 그룹에 멤버를 추가한다.
//Parameters: string type, string id, string password, string name, string identificationNumber
//Return Value: void
//Created: 2019/06/02
void MemberManagement::createAccount(string type, string id, string password, string name, string identificationNumber) {
	if (type == "seller") {
		member->insertSeller(new Seller(id, password, name, identificationNumber));
	}
	else if (type == "buyer") {
		member->insertBuyer(new Buyer(id, password, name, identificationNumber));
	}
	else {
		cout << "Invaild Type" << endl;
	}

}

//Function: bool login(string id, string password)
//Description: 로그인하는 회원의 type을 확인하고 저장되어 있는 id와 password가 일치할 시에 session 그룹에 회원을 추가한다.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool MemberManagement::login(string id, string password) {
	if (!(member->match("seller", id, password))&&!(member->match("buyer", id, password))) {
		return false;
	}

	if (member->getType(id) == "seller") {
		if (member->match("seller", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
	else if (member->getType(id) == "buyer") {
		if (member->match("buyer", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
}


//Function: void logout(string id)
//Description: session 그룹에 로그아웃하는 회원을 삭제한다.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberManagement::logout(string id) {
	set<string>::iterator it;
	for (it = session.begin(); it != session.end(); ++it) {
		if (*it == id) {
			session.erase(it);
			break;
		}
	}
}

//Function: bool deleteAccount(string id)
//Description: 현재 세션 멤버의 type을 확인하고 해당 type의 멤버 그룹과 세션에서 멤버를 삭제한다.
//			단, seller일 때에 판매중인 티켓이 남아있으면 멤버 그룹과 세션에서 해당 seller를 삭제하지 않는다. 
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool MemberManagement::deleteAccount(string id) {
	
	if ((member->getType(id) == "seller")) {
		Seller *s = member->getSeller(id);
		if (s->existTicket()) {
			return false;
		}
		else {
			member->deleteSeller(id);
			set<string>::iterator it;
			for (it = session.begin(); it != session.end(); ++it) {
				if (*it == id) {
					session.erase(it);
					break;
				}
			}
		}
	}
	else if((member->getType(id) == "buyer")){

		member->deleteBuyer(id);
		set<string>::iterator it;
		for (it = session.begin(); it != session.end(); ++it) {
			if (*it == id) {
				session.erase(it);
				break;
			}
		}
		
	}
	return true;
}

//Function: MemberCollection* getMembers()
//Description: 멤버그룹 포인터를 반환한다.
//Parameters: None
//Return Value: MemberCollection*
//Created: 2019/06/02
MemberCollection* MemberManagement::getMembers() {
	return member;
}
