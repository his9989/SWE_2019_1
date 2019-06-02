#ifndef LOG_OUT_H
#define LOG_OUT_H
#include <string>
#include "memberManagement.h"
using namespace std;

class Logout {
private:
	MemberManagement * memberManagement;
public:
	Logout();
	Logout(MemberManagement*);
	void logout(string);
};


#endif