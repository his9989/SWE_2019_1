#ifndef LOG_IN_UI_H
#define LOG_IN_UI_H
#include "login.h"
#include <string>
using namespace std;

class LoginUI {
private:
	Login * logins;

public:
	LoginUI();
	LoginUI(MemberManagement*);
	bool login(string, string);
};
#endif