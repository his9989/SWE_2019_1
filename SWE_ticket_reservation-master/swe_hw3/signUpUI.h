#pragma once
#include "stdafx.h"
#include "signUp.h"

//Class : SignUpUI
//Description: This is Boundary Class of use case "Sign Up"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class SignUpUI {
private:
	SignUp * signUp;
public:
	SignUpUI();
	SignUpUI(MemberManagement *);
	void createAccount(string ,string, string, string, string);
};

