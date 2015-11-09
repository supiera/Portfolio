#include "Students.h"
#include "Menu.h"
#include <iostream>
using namespace std;


int main(){
	//Setup();

	while (1){
		MENU select;
		select = ShowMenu();

		switch (select){
		case MENU_ADD_STUDENT:
		case MENU_ADD_STUDENT_ENG:{
			bool succeeded;
			succeeded = s.AddStudent((MENU_ADD_STUDENT == select ? true : false) );
			if (succeeded)
				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
			else
				cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";

			break;
		}
		case MENU_SHOW_ALL:{
			ShowAll();
			break;
		}
		case MENU_QUIT:{
			Teardown();
			cout << "\n���α׷��� �����մϴ�.\n";
		}
			return 0;
		}
	}
	return 0;
}
