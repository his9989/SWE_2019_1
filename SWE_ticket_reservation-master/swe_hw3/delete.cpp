#include "stdafx.h"
#include "delete.h"
#include "memberManagement.h"

//Function: Delete()
//Description: Delete class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Delete::Delete() {}

//Function: Delete((MemberManagement *mm)
//Description: Delete class의 생성자.새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Delete::Delete(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool deleteAccount(string id)
//Description: memberManagement의 deleteAccount 함수를 부른다.
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool Delete::deleteAccount(string id) {
	return memberManagement->deleteAccount(id);
}