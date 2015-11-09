#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// �� ���� �л������� ������
// ������ ����ü
struct Student
{
	int sNo;			// �й�
	string name;		// �̸�
	int kor, eng, math;	// ������ ����
	float ave;			// ���
};

// �޴��� ������ ����ü�� �����.
enum MENU {MENU_ADD_STUDENT, MENU_SHOW_ALL, MENU_QUIT};

// �Լ��� ������
MENU ShowMenu();
void AddStudent(Student students[], int& NumberOfStudent, float& TotalAve);
void ShowAll(Student students[], int NumberOfStudent, float TotalAve);

int main()
{
	// 100 ���� ������ ������ �� �ִ� �迭�� ����
	const int MAX_STUDENTS = 100;
	Student students[ MAX_STUDENTS];
	
	float TotalAve = 0.0f;		// ��ü ���
	int NumberOfStudent = 0;	// ������� �Էµ� �л� ��

	// ���α׷��� ������ ������ �޴��� �����ְ�
	// �۾��� ó���Ѵ�.
	while(1)
	{

		// �޴��� �����ش�.
		MENU select;
		select = ShowMenu();


		// ���õ� ���� ���� ó��
		switch(select)
		{
		case MENU_ADD_STUDENT:
			// �л� ���� �߰�
			{
				// 100�� ��� �Էµ����� ����
				if (MAX_STUDENTS == NumberOfStudent)
				{
					cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";
					break;
				}

				// �л� ���� �߰� �Լ��� ȣ���Ѵ�.
				AddStudent( students, NumberOfStudent, TotalAve);

				// �۾��� ������ �˸���.
				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";

				break;
			}
		case MENU_SHOW_ALL:
			// ��ü ���� ����
			{
				// ��ü ���� ���� �Լ��� ȣ���Ѵ�.
				ShowAll( students, NumberOfStudent, TotalAve);

				break;
			}
		case MENU_QUIT:
			// ����
			cout << "\n���α׷��� �����մϴ�.\n";
			return 0;
		}

	}

	return 0;
}

// �޴��� �����ְ�, ���ð��� ��ȯ�Ѵ�.
// ��ȯ�� : ���õ� �޴� �׸�
MENU ShowMenu()
{
	// �ùٸ� �޴��� �� ������ �ݺ��Ѵ�.
	while(1)
	{
		// �޴� �����ֱ�
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����\n";
		cout << "Q. ���α׷� ����\n";
		cout << "------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		// �۾� �Է¹ޱ�
		char select;
		cin >> select;

		switch( select)
		{
		case '1': 
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			// �� ���� ����
			cout << "\n�ùٸ� ���� �Է����ּ���.\n";
			break;
		}
	}

	// �� ������ ����� ������� �ʴ´�.
	return MENU_QUIT;
}

// �л��� �� �� �߰��Ѵ�.
// students : �л����� ������ ���� �迭
// NumberOfStudent : ������� �Է¹��� �л���(�Լ� �ȿ��� +1�� �Ѵ�)
// TotalAve : ��ü ���. �Լ� �ȿ��� ���Ӱ� ���ȴ�.
void AddStudent(Student students[], int& NumberOfStudent, float& TotalAve)
{
	// �ҽ� �ڵ带 �����ϰ� �ϱ� ���ؼ�
	// ����� ������ ���۷����� ����Ų��.
	Student& std = students[NumberOfStudent];

	// �ش� �л��� �л���ȣ�� �ڵ����� �Է��Ѵ�.
	std.sNo = NumberOfStudent + 1;

	// �ش� �л��� �̸�, ������ ������ �Է¹޴´�.
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> std.name >> std.kor >> std.eng >> std.math;

	// ���� ����� ����Ѵ�.
	std.ave = float(std.kor + std.eng + std.math) / 3.0f;

	// �������� ����ؼ� ���ο� ��ü ����� ����Ѵ�.
	const int current = NumberOfStudent + 1;// ������� �Է¹��� �л� ��
	const int prev = NumberOfStudent;		// ���� ������ �Է¹��� �л� ��

	TotalAve = (TotalAve * prev / current) + (std.ave / current);

	// �Է¹��� �л� ���� ������Ų��.
	NumberOfStudent++;
}

// ��ü ������ �����ش�.
// students : �л����� ������ ���� �迭
// NumberOfStudent : ������� �Է¹��� �л���
void ShowAll(Student students[], int NumberOfStudent, float TotalAve)
{
	// �Ǽ� ��½ÿ� �Ҽ��� ���� �� �ڸ��� ǥ�õǵ��� �Ѵ�.
	cout.precision(2);
	cout << fixed;

	// Ÿ��Ʋ �κ��� ����Ѵ�.
	cout << "\n           < ��ü ���� ���� >";
	cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	// �Էµ� �л� ����ŭ �ݺ��Ѵ�.
	for (int i = 0; i < NumberOfStudent; ++i)
	{
		// �ҽ� �ڵ带 �����ϰ� �ϱ� ���ؼ�
		// ����� ������ ���۷����� ����Ų��.
		const Student& std = students[i];

		// �ش� �л��� ������ ����Ѵ�.
		cout << setw(7) << std.sNo << setw(7) << std.name;
		cout << setw(5) << std.kor << setw(5) << std.eng;
		cout << setw(5) << std.math << setw(7) << std.ave << "\n";
	}

	// ��ü ����� ����Ѵ�.
	cout << "\n��ü ��� = " << TotalAve << "\n";
}


// ����
// main() �� ���� ��Ȯ
// �� �۾� ���� ��Ȯ
// �޴� ����, ó�� ����� main() �� �и�

// ����
// main() ������ �������� ���� �ٷ��� �ʴµ� main() �� ������ �� �ִ�.
// �׸��� ���ڷ� �׻� �Ѱ��ش�.
