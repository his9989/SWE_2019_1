#include "stdafx.h"
#include "deleteAccountUI.h"

//Function: DeleteAccountUI()
//Description: DeleteAccountUI class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteAccountUI::DeleteAccountUI() {
	deletes = new DeleteAccount();
}

//Function: DeleteAccountUI(MemberManagement *mm)
//Description: DeleteAccountUI class의 생성자. deletes 멤버 객체 변수에 새로운 값으로 할당해준다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteAccountUI::DeleteAccountUI(MemberManagement *mm) {
	deletes = new DeleteAccount(mm);
}

//Function: bool deleteAccount(string line)
//Description: deletes의 deleteAccount 함수를 부른다.
//Parameters: string line
//Return Value: bool
//Created: 2019/06/02
bool DeleteAccountUI::deleteAccount(string line) {
	return deletes->deleteAccount(line);

}