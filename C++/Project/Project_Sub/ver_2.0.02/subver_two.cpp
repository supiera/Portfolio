// Update From ver 2.0
// Update  version 2.0.02
// 	: additional Science Subject and Sort(bubble sort)


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student{
	int sNo;
	string name;
	int kor, eng, math, sci;
	int total;
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
				Student& stu = students[NumberOfStudent];
				stu.sNo = NumberOfStudent + 1;

	 			cout << "�̸�(�������) ����, ����, ����, ���� ������ �Է��ϼ��� : \n";
				cin >> stu.name >> stu.kor >> stu.eng >> stu.math >> stu.sci;

				stu.total = (stu.kor + stu.eng + stu.math + stu.sci);
				stu.ave = (float)stu.total / 4.0f;

				const int current = NumberOfStudent + 1;
				const int prev = NumberOfStudent;

				TotalAve = (TotalAve * prev / current ) + (stu.ave / current);
				NumberOfStudent++;

				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";

				break;
			}
			case '2': {
				Student temp;
				for(int i = 0 ; i < NumberOfStudent - 1; i++){
					for(int j = 0; j<NumberOfStudent - 1 - i; j++){
						if( students[j].total < students[j+1].total){
							temp = students[j];
							students[j] = students[j+1];
							students[j+1] = temp;
						}
					}
				}
				cout.precision(2);
				cout << fixed;

				cout << "\n             < ��ü ���� ���� >";
				cout << "\n     �й�  �̸�  ���� ���� ���� ���� ���\n";
 
	
				for (int i = 0; i < NumberOfStudent; ++i){
					const Student& stu = students[i];
					cout << setw(7) << stu.sNo << setw(8) << stu.name;
					cout << setw(5) << stu.kor << setw(5) << stu.eng;
					cout << setw(5) << stu.sci;
					cout << setw(5) << stu.math << setw(7) << stu.ave << "\n";
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
