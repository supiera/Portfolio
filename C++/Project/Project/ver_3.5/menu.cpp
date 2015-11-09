#include "menu.h"
#include <iostream>
using namespace std;

MENU ShowMenu(){
	while (1){
		cout << "\n------ 메뉴 ------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 학생 성적 추가(고급 영어)\n";
		cout << "3. 전체 성적 보기\n";
		cout << "4. 전체 성적 저장하기(텍스트)\n";
		cout << "5. 전체 성적 저장하기(HTML)\n";
		cout << "Q. 프로그램 종료\n";
		cout << "------------------\n\n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		char select;
		cin >> select;

		switch (select){
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_ADD_STUDENT_ENG;
		case '3':
			return MENU_SHOW_ALL;
		case '4':
			return MENU_SAVE_TEXT;
		case '5':
			return MENU_SAVE_HTML;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			cout << "\n올바른 값을 입력해주세요.\n";
			break;
		}
	}
	return MENU_QUIT;
}
