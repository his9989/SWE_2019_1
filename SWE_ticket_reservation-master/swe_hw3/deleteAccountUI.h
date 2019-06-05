#pragma once
#include "stdafx.h"
#include "deleteAccount.h"
#include "memberManagement.h"

//Class : DeleteAccountUI
//Description: This is Boundary Class of use case "Delete Account"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class DeleteAccountUI {
private:
	DeleteAccount * deletes;
public:
	DeleteAccountUI();
	DeleteAccountUI(MemberManagement*);
	bool deleteAccount(string);
};
