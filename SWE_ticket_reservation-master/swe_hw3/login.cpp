#include "stdafx.h"
#include "login.h"

//Function: Login()
//Description: Login class의 기본 생성자. MemberManagement 객체를 생성한다.
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Login::Login() {
	memberManagement = new MemberManagement();

}

//Function: Login(MemberManagement*mm)
//Description: Login class의 생성자, 새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Login::Login(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool login(string id, string password)
//Description: memberManagement 멤버 객체 변수의 login함수를 부른다.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool Login::login(string id, string password) {
	return memberManagement->login(id, password);
}