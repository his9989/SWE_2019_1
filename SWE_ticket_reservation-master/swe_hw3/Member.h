#pragma once
#include "stdafx.h"

class Member
{
protected:
	string id;
	string password;
	string name;
	string identificationNumber;
public:
	Member();
	~Member();
	string getID();
	string getPassword();
	virtual string getType();
	virtual bool existTicket();
};

