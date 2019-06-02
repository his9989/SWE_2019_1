# SWE_ticket_reservation
소프트웨어 공학 과제 3, 티켓 예약 시스템

## 1. Main 에서 입력 동적으로 받는 법

> 인수님 코드와 거의 똑같은데, 한줄 입력을 char 대신 string 으로 받도록 변경했습니다.  
혹시 다른 의견 있으시면 다시 바꾸겠습니다.

### 1.1) main 함수 getline 쪽 소스코드
~~~cpp
string inputString;
getline(inFile, inputString);

// split은 하단에 정의되어 있음 
vector<string> lineData = split(inputString, ' ');

// lineData 는 입력받은 한줄 데이터로 index 0,1은 각각 메뉴, 서브메뉴
menu_level_1 = stoi(lineData[0]); // 메뉴 
menu_level_2 = stoi(lineData[1]); // 서브메뉴
~~~

- 위 부분에서 **inputString** 은 회원 가입으로 따지면,  
1 1 ytn testpwd yoo 112233 seller  
이것이 통째로 들어있는 string 입니다.

- 그리고 바로 아래 lineData 는 **inputString** 을 공백 기준으로 잘라서 (Split)  
벡터에 담은 것입니다. 
따라서 lineData 는 아래와 같이 활용이 가능합니다.

>cf) split 함수는 소스코드 하단에 정의되어 있습니다.  
<a href="https://github.com/Donsworkout/SWE_ticket_reservation/blob/master/swe_hw3/swe_hw3.cpp">main 함수 전체 소스코드 보기</a>

~~~cpp
    case 1: {
      cout << menu_level_1 << ", " << menu_level_2 << ".";
      printf("회원가입\n");
      // ytn testpwd yoo 112233 seller
      cout << lineData[2] + " " + lineData[3] + " " + lineData[4] + " " + lineData[5] + " " + lineData[6] << endl;
      break;
    }
    case 2: {
      cout << menu_level_1 << ", " << menu_level_2 << ".";
      printf("회원탈퇴\n");
      break;
    }
~~~