#include "stdafx.h"
#include "member.h"
#include "memberCollection.h"

//Function: MemberCollection()
//Description: MemberCollection class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
MemberCollection::MemberCollection() {
}

//Function: void insertSeller(Seller*)
//Description: seller에 들어온 객체를 추가한다.
//Parameters: Seller *m
//Return Value: void
//Created: 2019/06/02
void MemberCollection::insertSeller(Seller *m) {
	sellers.push_back(m);

}

//Function: void insertBuyer(Buyer*)
//Description: Buyer에 들어온 객체를 추가한다.
//Parameters: Buyer *m
//Return Value: void
//Created: 2019/06/02
void MemberCollection::insertBuyer(Buyer *m) {
	buyers.push_back(m);

}

//Function: string getType(string id)
//Description: 들어온 id를 셀러 그룹과 바이어 그룹을 확인하여 셀러인지 바이어인지 판별한다.
//Parameters: string id
//Return Value: string
//Created: 2019/06/02
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

//Function: Seller* getSeller(string id)
//Description: 셀러 그룹을 확인하여 들어온 id에 대한 셀러 객체를 반환한다.
//Parameters: string id
//Return Value: Seller*
//Created: 2019/06/02
Seller* MemberCollection::getSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}

//Function: Buyer* getBuyer(string id)
//Description: 바이어 그룹을 확인하여 들어온 id에 대한 바이어 객체를 반환한다.
//Parameters: string id
//Return Value: Buyer*
//Created: 2019/06/02
Buyer* MemberCollection::getBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
}

//Function: vector<Seller*> getAllSeller()
//Description: 셀러 그룹 객체를 반환한다.
//Parameters: None
//Return Value: vector<Seller*>
//Created: 2019/06/02
vector<Seller*> MemberCollection::getAllSeller() {
	return sellers;
}



//Function: vector<Buyer*> getAllBuyer()
//Description: 바이어 그룹 객체를 반환한다.
//Parameters: None
//Return Value: vector<Buyer*>
//Created: 2019/06/02
vector<Buyer*>MemberCollection::getAllBuyer() {
	return buyers;
}

//Function: bool match(string type, string id, string password)
//Description: 멤버 타입을 확인하고, 해당 id를 가진 객체의 password와 인자값으로 받은 password가 일치하면 true를 반환하고 아니면 false를 반환한다.
//Parameters: string type, string id, string password
//Return Value: bool
//Created: 2019/06/02
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

//Function: void deleteSeller(string id)
//Description: 셀러 그룹에서 해당 id를 가진 셀러를 삭제한다.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberCollection::deleteSeller(string id) {
	for (vector<Seller*>::iterator it = sellers.begin(); it != sellers.end(); it++) {
		if ((*it)->getID() == id) {
			sellers.erase(it);
			break;
		}
	}

}

//Function: void deleteBuyer(string id)
//Description: 바이어 그룹에서 해당 id를 가진 바이어를 삭제한다.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void MemberCollection::deleteBuyer(string id) {
	for (vector<Buyer*>::iterator it = buyers.begin(); it != buyers.end(); it++) {
		if ((*it)->getID() == id) {
			buyers.erase(it);
			break;
		}
	}

}


