#ifndef SIGN_UP_H
#define SIGN_UP_H
#include <string>
#include "memberManagement.h"
using namespace std;

class SignUp {
private:
	MemberManagement * memberManagement;
public:
	SignUp();
	SignUp(MemberManagement*);
	void createAccount(string, string, string, string, string);
};

#endif