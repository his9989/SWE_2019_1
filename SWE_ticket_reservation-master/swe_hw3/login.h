#ifndef LOG_IN_H
#define LOG_IN_H
#include "memberManagement.h"
#include <string>
using namespace std;

class Login {
private:
	MemberManagement * memberManagement;
public:
	Login();
	Login(MemberManagement*);
	bool login(string, string);
};

#endif