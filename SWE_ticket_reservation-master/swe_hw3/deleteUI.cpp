#include "stdafx.h"
#include "deleteUI.h"

DeleteUI::DeleteUI() {
	deletes = new Delete();
}


DeleteUI::DeleteUI(MemberManagement *mm) {
	deletes = new Delete(mm);
}

bool DeleteUI::deleteAccount(string line) {
	return deletes->deleteAccount(line);

}