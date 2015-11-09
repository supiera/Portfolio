#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;

int main(){
	while(1){
		MENU select;
		select = ShowMenu();

		switch(select){
			case MENU_ADD_STUDENT:{
					bool succeeded;			  
					succeeded = AddStudent();
					if(succeeded)
						cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
					else
						cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";
					break;
			}
			case MENU_SHOW_ALL:{
							   ShowAll();
							   break;
			}
			case MENU_QUIT:
				cout << "\n���α׷��� �����մϴ�.\n";
				return 0;
		}
	}
	return 0;
}