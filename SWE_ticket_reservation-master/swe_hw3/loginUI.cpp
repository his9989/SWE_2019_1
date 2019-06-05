#include "stdafx.h"
#include "loginUI.h"

//Function: LoginUI()
//Description: LoginUI class의 기본 생성자. Login 객체를 생성한다.
//Parameters: None
//Return Value: None
//Created: 2019/06/02
LoginUI::LoginUI() {
	logins = new Login();
}

//Function: LoginUI(MemberManagement*mm)
//Description: LoginUI class의 생성자, Login에 memberManagement를 넘겨주어 새로운 객체를 만든다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
LoginUI::LoginUI(MemberManagement *mm) {
	logins = new Login(mm);
}

//Function: bool login(string id, string password)
//Description: logins 멤버 객체 변수의 login함수를 부른다.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool LoginUI::login(string id, string password) {

	return logins->login(id, password);
}