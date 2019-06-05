#include "stdafx.h"
#include "deleteAccount.h"
#include "memberManagement.h"

//Function: DeleteAccount()
//Description: DeleteAccount class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteAccount::DeleteAccount() {}

//Function: DeleteAccount((MemberManagement *mm)
//Description: Delete class의 생성자.새로운 memberManagement 객체를 할당한다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteAccount::DeleteAccount(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool deleteAccount(string id)
//Description: memberManagement의 deleteAccount 함수를 부른다.
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool DeleteAccount::deleteAccount(string id) {
	return memberManagement->deleteAccount(id);
}