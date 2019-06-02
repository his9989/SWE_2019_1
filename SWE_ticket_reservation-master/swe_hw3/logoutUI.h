#pragma once
#include "stdafx.h"
#include "logout.h"
using namespace std;

class LogoutUI {
private:
	Logout * logOut;
public:
	LogoutUI();
	LogoutUI(MemberManagement*);
	void logout(string);
};
