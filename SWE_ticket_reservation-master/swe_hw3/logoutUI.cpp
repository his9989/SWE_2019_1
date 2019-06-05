#include "stdafx.h"
#include "logoutUI.h"

//Function: LogoutUI()
//Description: LogoutUI class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
LogoutUI::LogoutUI() {
	logOut = new Logout();

}

//Function: LogoutUI(MemberManagement*mm)
//Description: LogoutUI class의 생성자, Logout에 memberManagement를 넘겨주어 새로운 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
LogoutUI::LogoutUI(MemberManagement *mm) {
	logOut = new Logout(mm);
}

//Function: void logout(string id)
//Description: logOut 맴버 객체 변수에 logout 함수를 부른다.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void LogoutUI::logout(string id) {
	logOut->logout(id);
}