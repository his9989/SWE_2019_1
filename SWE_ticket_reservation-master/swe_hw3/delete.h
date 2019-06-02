#pragma once
#include "memberManagement.h"

class Delete {
private:
	MemberManagement * memberManagement;
public:
	Delete();
	Delete(MemberManagement*);
	bool deleteAccount(string);
};
