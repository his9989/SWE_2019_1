#include "stdafx.h"
#include "Member.h"
#include "memberManagement.h"

Member::Member()
{
}


Member::~Member()
{
}

string Member::getID() {
	return id;
}

string Member::getPassword() {
	return password;
}