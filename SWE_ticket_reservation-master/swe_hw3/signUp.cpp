#include "stdafx.h"
#include "signUp.h"

SignUp::SignUp() {}
SignUp::SignUp(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}
void SignUp::createAccount(string id, string password, string name, string identificationNumber, string type) {
	memberManagement->createAccount(type, id, password, name, identificationNumber);
}