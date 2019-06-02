//#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "TimerUI.h"
#include <ctime>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

void doTask();

string currentTime = "";

int main() {
	doTask();
	return 0;
}

void doTask() {
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	ofstream outFile(OUTPUT_FILE_NAME);
	ifstream inFile(INPUT_FILE_NAME);

	while (!is_program_exit) {
		char inputString[100] = { NULL, };
		inFile.getline(inputString, 100); // 100으로 일단 잡았어요.. 동적으로 변환 요망
		menu_level_1 = inputString[0]-48; // 아스키 변환
		menu_level_2 = inputString[2]-48; // 아스키 변환
		// 말단으로 전달하는 string 변수가 inputData입니당
		string inputData(inputString + 4 , 50); // 50으로 일단 잡았어요.. 동적으로 바꿔야해요...
		switch (menu_level_1) {
		case 1: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("회원가입\n");
				cout << inputData << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("회원탈퇴\n");
				break;
			}
			}
			break;
		}
		case 2: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("로그인\n");
				cout << inputData << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("로그아웃\n");
				break;
			}
			}
			break;
		}
		case 3: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("판매티켓 등록\n");
				cout << inputData << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("등록티켓 조회\n");
				break;
			}
			}
			break;
		}
		case 4: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("티켓 검색\n");
				cout << inputData << endl;
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("티켓 예약\n");
				cout << inputData << endl;
				break;
			}
			case 3: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("경매 중인 티켓 검색\n");
				cout << inputData << endl;
				break;
			}
			case 4: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("경매 참여\n");
				cout << inputData << endl;
				break;
			}
			case 5: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("예약 정보 조회\n");
				break;
			}
			}	
			break;
		}
		case 5: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("현재시간 설정\n");
			cout << inputData << endl;
			TimerUI timerUI;
			currentTime = inputData;
			timerUI.checkTicket(currentTime);
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("session 변경\n");
				break;
			}
			case 2: {
				cout << menu_level_1 << ", " << menu_level_2 << ".";
				printf("guest session으로 변경\n");
				break;
			}
			}
			break;
		}
		case 7: {
			cout << menu_level_1 << ", " << menu_level_2 << ".";
			printf("종료\n");
			is_program_exit = 1;
			break;
		}
		}
	}
}