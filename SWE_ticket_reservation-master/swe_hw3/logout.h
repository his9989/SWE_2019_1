#pragma once
#include "stdafx.h"
#include "memberManagement.h"
using namespace std;

//Class : Logout
//Description: This is Control Class of use case "Log out"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class Logout {
private:
	MemberManagement * memberManagement;
public:
	Logout();
	Logout(MemberManagement*);
	void logout(string);
};
