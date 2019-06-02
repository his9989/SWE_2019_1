#include <iostream>
#include <vector>
#include <set>
using namespace std;
#include "memberManagement.h"
#include "member.h"
#include "seller.h"
#include "buyer.h"

MemberManagement::MemberManagement() {
	member = new MemberCollection();
}
MemberManagement::~MemberManagement() {

}
void MemberManagement::createAccount(string type, string id, string password, string name, string identificationNumber) {
	if (type == "Seller") {
		member->insertSeller(new Seller(id, password, name, identificationNumber));
	}
	else if (type == "Buyer") {
		member->insertBuyer(new Buyer(id, password, name, identificationNumber));
	}
	else {
		cout << "Invaild Type" << endl;
	}

}
bool MemberManagement::login(string id, string password) {
	if (member->getType(id) == "Seller") {
		if (member->match("Seller", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
	else if (member->getType(id) == "Buyer") {
		if (member->match("Buyer", id, password)) {
			session.insert(id);
			return true;
		}
		else {
			return false;
		}
	}
}

void MemberManagement::logout(string id) {
	set<string>::iterator it;
	for (it = session.begin(); it != session.end(); ++it) {
		if (*it == id) {
			session.erase(it);
		}
	}
}

bool MemberManagement::deleteAccount(string id) {
	
	if ((member->getType(id) == "Seller")) {
		Seller *s = member->getSeller(id);
		if (s->existTicket())
			return false;
		else {
			member->deleteSeller(id);
			set<string>::iterator it;
			for (it = session.begin(); it != session.end(); ++it) {
				if (*it == id) {
					session.erase(it);
				}
			}
		}
	}
	else if((member->getType(id) == "Buyer")){

		member->deleteBuyer(id);
		set<string>::iterator it;
		for (it = session.begin(); it != session.end(); ++it) {
			if (*it == id) {
				session.erase(it);
			}
		}
		
	}
	return true;
}
/*
MemberCollection* MemberManagement::getMembers() {
	return member;
}
*/