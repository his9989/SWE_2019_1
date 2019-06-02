#include "login.h"
Login::Login() {
	memberManagement = new MemberManagement();

}
Login::Login(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

bool Login::login(string id, string password) {
	return memberManagement->login(id, password);
}