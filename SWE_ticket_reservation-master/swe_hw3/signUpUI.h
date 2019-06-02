#pragma once
#include "stdafx.h"
#include "signUp.h"

class SignUpUI {
private:
	SignUp * signUp;
public:
	SignUpUI();
	SignUpUI(MemberManagement *);
	void createAccount(string ,string, string, string, string);
};

