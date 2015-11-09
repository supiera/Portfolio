#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;


int main()
{

	// �ʱ�ȭ�Ѵ�.
	Setup();

	// ���α׷��� ������ ������ �޴��� �����ְ�
	// �۾��� ó���Ѵ�.
	while (1)
	{

		// �޴��� �����ش�.
		MENU select;
		select = ShowMenu();


		// ���õ� ���� ���� ó��
		switch (select)
		{
		case MENU_ADD_STUDENT:
			// �л� ���� �߰�
		{
			// �л� ���� �߰� �Լ��� ȣ���Ѵ�.
			bool succeeded;
			succeeded = AddStudent();

			// ����� �˸���.
			if (succeeded)
				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
			else
				cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";

			break;
		}
		case MENU_SHOW_ALL:
			// ��ü ���� ����
		{
			// ��ü ���� ���� �Լ��� ȣ���Ѵ�.
			ShowAll();

			break;
		}
		case MENU_QUIT:
			// ����
		{
			// ����� ���ҽ��� �����Ѵ�.
			Teardown();

			cout << "\n���α׷��� �����մϴ�.\n";
		}
			return 0;
		}

	}

	return 0;
}
