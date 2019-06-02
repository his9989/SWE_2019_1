#include "logoutUI.h"
LogoutUI::LogoutUI() {
	logOut = new Logout();

}
LogoutUI::LogoutUI(MemberManagement *mm) {
	logOut = new Logout(mm);
}
void LogoutUI::logout(string id) {
	logOut->logout(id);
}