#pragma once
#include "stdafx.h"
#include "logout.h"
using namespace std;

//Class : LogoutUI
//Description: This is Boundary Class of use case "Log out"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class LogoutUI {
private:
	Logout * logOut;
public:
	LogoutUI();
	LogoutUI(MemberManagement*);
	void logout(string);
};
