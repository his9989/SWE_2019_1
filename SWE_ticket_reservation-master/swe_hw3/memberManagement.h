#pragma once
#include "stdafx.h"
#include "member.h"
#include "memberCollection.h"
using namespace std;


class MemberManagement {

private:
	set<string> session;
	MemberCollection *member;

public:
	MemberManagement();
	~MemberManagement();
	void createAccount(string, string, string, string, string);
	bool login(string, string);
	void logout(string);
	bool deleteAccount(string);
	MemberCollection* getMembers();
};

