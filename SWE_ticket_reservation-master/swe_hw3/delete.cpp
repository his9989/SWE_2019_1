#include "stdafx.h"
#include "delete.h"
#include "memberManagement.h"

Delete::Delete() {}
Delete::Delete(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}
bool Delete::deleteAccount(string id) {
	return memberManagement->deleteAccount(id);
}