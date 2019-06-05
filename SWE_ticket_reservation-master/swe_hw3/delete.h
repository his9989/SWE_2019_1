#pragma once
#include "stdafx.h"
#include "memberManagement.h"

//Class : Delete
//Description: This is Control Class of use case "Delete Account"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class Delete {
private:
	MemberManagement * memberManagement;
public:
	Delete();
	Delete(MemberManagement*);
	bool deleteAccount(string);
};
