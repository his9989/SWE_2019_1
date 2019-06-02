#pragma once
#include "stdafx.h"
#include "memberManagement.h"

using namespace std;

class Login {
private:
	MemberManagement * memberManagement;
public:
	Login();
	Login(MemberManagement*);
	bool login(string, string);
};
