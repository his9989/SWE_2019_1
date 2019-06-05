#include "stdafx.h"
#include "logout.h"

//Function: Logout()
//Description: Logout class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Logout::Logout() {
	memberManagement = new MemberManagement();
}

//Function: Logout(MemberManagement*mm)
//Description: Logout class의 생성자, 새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Logout::Logout(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: void logout(string id)
//Description: memberManagement 맴버 객체 변수에 logout 함수를 부른다.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void Logout::logout(string id) {
	memberManagement->logout(id);
}