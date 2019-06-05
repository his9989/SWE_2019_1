#pragma once
#include "stdafx.h"
#include "memberManagement.h"

//Class : SignUp
//Description: This is Control Class of use case "Sign Up"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.
class SignUp {
private:
	MemberManagement * memberManagement;
public:
	SignUp();
	SignUp(MemberManagement*);
	void createAccount(string, string, string, string, string);
};
