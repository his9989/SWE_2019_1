#include "stdafx.h"
#include "deleteUI.h"

//Function: DeleteUI()
//Description: DeleteUI class의 기본 생성자
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteUI::DeleteUI() {
	deletes = new Delete();
}

//Function: DeleteUI(MemberManagement *mm)
//Description: DeleteUI class의 생성자. deletes 멤버 객체 변수에 새로운 값으로 할당해준다.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteUI::DeleteUI(MemberManagement *mm) {
	deletes = new Delete(mm);
}

//Function: bool deleteAccount(string line)
//Description: deletes의 deleteAccount 함수를 부른다.
//Parameters: string line
//Return Value: bool
//Created: 2019/06/02
bool DeleteUI::deleteAccount(string line) {
	return deletes->deleteAccount(line);

}