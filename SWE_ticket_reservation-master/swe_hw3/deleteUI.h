#pragma once
#include "stdafx.h"
#include "delete.h"
#include "memberManagement.h"

//Class : DeleteUI
//Description: This is Boundary Class of use case "Delete Account"
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
class DeleteUI {
private:
	Delete * deletes;
public:
	DeleteUI();
	DeleteUI(MemberManagement*);
	bool deleteAccount(string);
};
