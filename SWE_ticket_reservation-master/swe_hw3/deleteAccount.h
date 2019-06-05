#pragma once
#include "stdafx.h"
#include "memberManagement.h"

//Class : DeleteAccount
//Description: This is Control Class of use case "Delete Account"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class DeleteAccount {
private:
	MemberManagement * memberManagement;
public:
	DeleteAccount();
	DeleteAccount(MemberManagement*);
	bool deleteAccount(string);
};
