#include "stdafx.h"
#include "Member.h"
#include "memberManagement.h"

//Function: Member()
//Description: Member class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Member::Member()
{
}

//Function: ~Member()
//Description: Member class의 소멸자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Member::~Member()
{
}

//Function: string getID()
//Description: id 값을 리턴한다.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Member::getID() {
	return id;
}

//Function: string getPassword()
//Description: password 값을 리턴한다.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Member::getPassword() {
	return password;
}