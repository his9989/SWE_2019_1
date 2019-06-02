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
			return "Seller";
		}
	}
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return "Buyer";
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
	if (type == "Seller") {
		for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
			if ((*it)->getID() == id) {
				if ((*it)->getPassword() == password) {
					return true;
				}
			}
		}
		return false;
	}
	else if (type == "Buyer") {
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

