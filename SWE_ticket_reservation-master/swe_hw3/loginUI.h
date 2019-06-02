#pragma once
#include "stdafx.h"
#include "login.h"

using namespace std;

class LoginUI {
private:
	Login * logins;

public:
	LoginUI();
	LoginUI(MemberManagement*);
	bool login(string, string);
};