#include "stdafx.h"
#include "loginUI.h"

LoginUI::LoginUI() {
	logins = new Login();
}
LoginUI::LoginUI(MemberManagement *mm) {
	logins = new Login(mm);
}
bool LoginUI::login(string id, string password) {

	return logins->login(id, password);
}