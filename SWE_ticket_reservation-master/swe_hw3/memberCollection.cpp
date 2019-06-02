#include "member.h"
#include <vector>
#include <iostream>
#include "memberCollection.h"
using namespace std;
MemberCollection::MemberCollection() {
}
void MemberCollection::insertSeller(Seller *m) {
	sellers.push_back(m);

}
void MemberCollection::insertBuyer(Buyer *m) {
	buyers.push_back(m);

}
string MemberCollection::getType(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			return "seller";
		}
	}
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return "buyer";
		}
	}

}
Seller* MemberCollection::getSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}

Buyer* MemberCollection::getBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}
bool MemberCollection::match(string type, string id, string password) {
	if (type == "seller") {
		for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
			if ((*it)->getID() == id) {
				if ((*it)->getPassword() == password) {
					return true;
				}
			}
		}
		return false;
	}
	else if (type == "buyer") {
		for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
			if ((*it)->getID() == id) {
				if ((*it)->getPassword() == password) {
					return true;
				}
			}
		}
		return false;
	}

}
void MemberCollection::deleteSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			sellers.erase(it);
		}
	}

}

void MemberCollection::deleteBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			buyers.erase(it);
		}
	}

}

int MemberCollection::num() {
	return sellers.size();
}

