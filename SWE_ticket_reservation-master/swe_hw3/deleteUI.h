#ifndef DELETE_UI_H
#define DELETE_UI_H
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

#endif