#include "stdafx.h"
#include "signUp.h"

//Function: SignUp()
//Description: SignUp class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
SignUp::SignUp() {}

//Function: SignUp(MemberManagement *mm)
//Description: SignUp class의 생성자. 새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
SignUp::SignUp(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: void createAccount(string id, string password, string name, string identificationNumber, string type)
//Description: 멤버 그룹에 멤버를 추가하는 함수이다. memberManagement 클래스의 createAccount 함수를 부른다.
//Parameters: string id, string password, string name, string identificationNumber, string type
//Return Value: void
//Created: 2019/06/02
void SignUp::createAccount(string id, string password, string name, string identificationNumber, string type) {
	memberManagement->createAccount(type, id, password, name, identificationNumber);
}