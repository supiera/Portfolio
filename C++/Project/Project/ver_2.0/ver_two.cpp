//page 484

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

int main(){
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];
	float TotalAve = 0.0f;
	int NumberOfStudent = 0;

	while(1){
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����\n";
		cout << "Q. ���α׷� ����\n";
		cout << "------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		char select;
		cin >> select;

		switch(select) {
			case '1': {
				if (MAX_STUDENTS == NumberOfStudent) {
					cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";
					break;
				}
				Student& std = students[NumberOfStudent];
				std.sNo = NumberOfStudent + 1;

	 			cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
				cin >> std.name >> std.kor >> std.eng >> std.math;

				std.ave = float(std.kor + std.eng + std.math) / 3.0f;

				const int current = NumberOfStudent + 1;
				const int prev = NumberOfStudent;

				TotalAve = (TotalAve * prev / current ) + (std.ave / current);
				NumberOfStudent++;

				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";

				break;
			}
			case '2': {
	 
				cout.precision(2);
				cout << fixed;

				cout << "\n < ��ü ���� ���� >";
				cout << "\n �й� ���� ���� ���� ���\n";
 
	
				for (int i = 0; i < NumberOfStudent; ++i){
					const Student& std = students[i];
					cout << setw(7) << std.sNo << setw(7) << std.name;
					cout << setw(5) << std.kor << setw(5) << std.eng;
					cout << setw(5) << std.math << setw(7) << std.ave << "\n";
				}
	 
				cout << "\n��ü ��� = " << TotalAve << "\n";
 
				break;
			}
			case 'Q':
			case 'q':
				cout << "\n���α׷��� �����մϴ�.\n";
				return 0;
			default:
				cout << "\n�ùٸ� ���� �Է����ּ���.\n";
				break;
		}		//switch
	 }		//while
	 return 0;
}		//main
