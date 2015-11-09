#include "menu.h"
#include <iostream>
using namespace std;

// 메뉴를 보여주고, 선택값을 반환한다.
// 반환값 : 선택된 메뉴 항목
MENU ShowMenu()
{
	// 올바른 메뉴를 고를 때까지 반복한다.
	while (1)
	{
		// 메뉴 보여주기
		cout << "\n------ 메뉴 ------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기\n";
		cout << "Q. 프로그램 종료\n";
		cout << "------------------\n\n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		// 작업 입력받기
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			// 그 외의 선택
			cout << "\n올바른 값을 입력해주세요.\n";
			break;
		}
	}

	// 이 문장은 절대로 실행되지 않는다.
	return MENU_QUIT;
}
