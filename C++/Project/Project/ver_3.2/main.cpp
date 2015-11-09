#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main(){
	Setup();

	while (1){
		MENU select;
		select = ShowMenu();

		switch (select){
			case MENU_ADD_STUDENT:{
				bool succeeded;
				succeeded = AddStudent();
				if (succeeded)
					cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
				else
					cout << "\n더 이상 입력할 수 없습니다.\n";

				break;
			}
			case MENU_SHOW_ALL:{
				ShowAll();
				break;
			}
			case MENU_QUIT:{
				Teardown();
				cout << "\n프로그램을 종료합니다.\n";
			}
				return 0;
		}
	}
	return 0;
}
