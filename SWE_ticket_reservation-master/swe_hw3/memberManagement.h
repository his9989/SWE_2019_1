#include <iostream>
#include <map>
#include <set>
#include <string>
#include "member.h"
#include "memberCollection.h"
using namespace std;
#ifndef MEMBER_MANAGEMENT_H
#define MEMBER_MANAGEMENT_H


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

#endif


