#pragma once
#include "stdafx.h"
#include "memberManagement.h"

class Delete {
private:
	MemberManagement * memberManagement;
public:
	Delete();
	Delete(MemberManagement*);
	bool deleteAccount(string);
};
