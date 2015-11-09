#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main()
{

	// 초기화한다.
	Setup();

	// 프로그램이 종료할 때까지 메뉴로 보여주고
	// 작업을 처리한다.
	while (1)
	{

		// 메뉴를 보여준다.
		MENU select;
		select = ShowMenu();


		// 선택된 값에 따라서 처리
		switch (select)
		{
		case MENU_ADD_STUDENT:
			// 학생 성적 추가
		{
			// 학생 성적 추가 함수를 호출한다.
			bool succeeded;
			succeeded = AddStudent();

			// 결과를 알린다.
			if (succeeded)
				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
			else
				cout << "\n더 이상 입력할 수 없습니다.\n";

			break;
		}
		case MENU_SHOW_ALL:
			// 전체 성적 보기
		{
			// 전체 성적 보기 함수를 호출한다.
			ShowAll();

			break;
		}
		case MENU_QUIT:
			// 종료
		{
			// 사용한 리소스를 정리한다.
			Teardown();

			cout << "\n프로그램을 종료합니다.\n";
		}
			return 0;
		}

	}

	return 0;
}
