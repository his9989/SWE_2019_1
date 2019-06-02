#ifndef LOG_OUT_UI_H
#define LOG_OUT_UI_H
#include <string>
#include "logout.h"
using namespace std;

class LogoutUI {
private:
	Logout * logOut;
public:
	LogoutUI();
	LogoutUI(MemberManagement*);
	void logout(string);
};

#endif