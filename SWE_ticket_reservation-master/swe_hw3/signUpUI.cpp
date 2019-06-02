#include "stdafx.h"
#include "signUpUI.h"

SignUpUI::SignUpUI() {}
SignUpUI::SignUpUI(MemberManagement *mm) {
	signUp = new SignUp(mm);
}
void SignUpUI::createAccount(string id, string password, string name, string identificationNumber, string type) {
	signUp->createAccount(id, password, name, identificationNumber, type);
}