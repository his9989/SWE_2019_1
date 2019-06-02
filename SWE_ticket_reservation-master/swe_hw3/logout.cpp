#include "logout.h"
Logout::Logout() {
	memberManagement = new MemberManagement();
}
Logout::Logout(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}
void Logout::logout(string id) {
	memberManagement->logout(id);
}