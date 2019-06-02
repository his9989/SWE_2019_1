#pragma once
#include "stdafx.h"
#include "seller.h"
#include "buyer.h"

class MemberCollection {
private:
	vector<Seller*> sellers;
	vector<Buyer*> buyers;

public:
	MemberCollection();
	void insertSeller(Seller*);
	void insertBuyer(Buyer*);
	void deleteSeller(string);
	void deleteBuyer(string);
	string getType(string id);
	Buyer* getBuyer(string);
	Seller* getSeller(string);
	bool match(string, string, string);
};