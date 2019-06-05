#pragma once
#include "stdafx.h"
#include "login.h"

using namespace std;


//Class : LoginUI
//Description: This is Boundary Class of use case "Login"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class LoginUI {
private:
	Login * logins;

public:
	LoginUI();
	LoginUI(MemberManagement*);
	bool login(string, string);
};