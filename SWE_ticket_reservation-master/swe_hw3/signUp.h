#pragma once
#include "stdafx.h"
#include "memberManagement.h"

class SignUp {
private:
	MemberManagement * memberManagement;
public:
	SignUp();
	SignUp(MemberManagement*);
	void createAccount(string, string, string, string, string);
};
