#include "stdafx.h"
#include "signUpUI.h"

//Function: SignUpUI()
//Description: SignUpUI class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
SignUpUI::SignUpUI() {}

//Function: SignUpUI(MemberManagement *mm)
//Description: SignUpUI class의 생성자. 새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
SignUpUI::SignUpUI(MemberManagement *mm) {
	signUp = new SignUp(mm);
}

//Function: void createAccount(string id, string password, string name, string identificationNumber, string type)
//Description: 멤버 그룹에 멤버를 추가하는 함수이다. SignUp 클래스의 createAccount 함수를 부른다.
//Parameters: string id, string password, string name, string identificationNumber, string type
//Return Value: void
//Created: 2019/06/02
void SignUpUI::createAccount(string id, string password, string name, string identificationNumber, string type) {
	signUp->createAccount(id, password, name, identificationNumber, type);
}