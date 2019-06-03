#include "stdafx.h"

#include "Buyer.h"



Buyer::Buyer()

{

}



Buyer::Buyer(string id, string password, string name, string identificationNumber, string address, string email)

{

	this->id = id;

	this->password = password;

	this->name = name;

	this->identificationNumber = identificationNumber;

	this->address = address;

	this->email = email;

}



Buyer::~Buyer()

{

}