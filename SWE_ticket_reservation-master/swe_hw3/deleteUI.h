#pragma once
#include "stdafx.h"
#include "delete.h"
#include "memberManagement.h"

class DeleteUI {
private:
	Delete * deletes;
public:
	DeleteUI();
	DeleteUI(MemberManagement*);
	bool deleteAccount(string);
};
