#include "menu.h"
#include <iostream>
using namespace std;

MENU ShowMenu(){
	while (1){
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. �л� ���� �߰�(��� ����)\n";
		cout << "3. ��ü ���� ����\n";
		cout << "4. ��ü ���� �����ϱ�(�ؽ�Ʈ)\n";
		cout << "5. ��ü ���� �����ϱ�(HTML)\n";
		cout << "Q. ���α׷� ����\n";
		cout << "------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

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
			cout << "\n�ùٸ� ���� �Է����ּ���.\n";
			break;
		}
	}
	return MENU_QUIT;
}
