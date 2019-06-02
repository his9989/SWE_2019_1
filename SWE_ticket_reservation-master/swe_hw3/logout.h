#pragma once
#include "stdafx.h"
#include "memberManagement.h"
using namespace std;

class Logout {
private:
	MemberManagement * memberManagement;
public:
	Logout();
	Logout(MemberManagement*);
	void logout(string);
};
