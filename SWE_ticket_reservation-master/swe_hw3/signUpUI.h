#ifndef SIGN_UP_UI_H
#define SIGN_UP_UI_H
#include <string>
#include "signUp.h"
using namespace std;

class SignUpUI {
private:
	SignUp * signUp;
public:
	SignUpUI();
	SignUpUI(MemberManagement *);
	void createAccount(string ,string, string, string, string);
};

#endif
