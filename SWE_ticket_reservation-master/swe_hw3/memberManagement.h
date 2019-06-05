#pragma once
#include "stdafx.h"
#include "member.h"
#include "memberCollection.h"
using namespace std;

//Class : MemberManagement
//Description:    This is Management Class. 멤버 그룹을 관리하는 클래스이다.
//				세션 리스트와 멤버 그룹을 가지고 있으며, use case의 동작을 직접적으로 실행하는 함수들의 집합이다.
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
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

