#pragma once
#include "stdafx.h"

//Class : Member
//Description:    This is Entity Class. 
//				And This is superclass of Buyer and Seller. So, This inlcude methods belong to both.
//				This is only used for inheritance. Basic methods are included.
//
//Created: 2019/06/02
//Author: Nahyun Lim
//mail: nahyun970128@gmail.com
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
	//virtual string getType();
	//virtual bool existTicket();
};

