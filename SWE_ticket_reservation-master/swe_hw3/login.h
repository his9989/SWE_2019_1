#pragma once
#include "stdafx.h"
#include "memberManagement.h"

using namespace std;

//Class : Login
//Description: This is Control Class of use case "Logout"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class Login {
private:
	MemberManagement * memberManagement;
public:
	Login();
	Login(MemberManagement*);
	bool login(string, string);
};
