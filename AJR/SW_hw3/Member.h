#pragma once
#include "stdafx.h"

class Member
{
protected:
	string id;
	string password;
	string name;
	string identificationNumber;
	string address;
	string email;
public:
	Member();
	~Member();
	string getName();
};
