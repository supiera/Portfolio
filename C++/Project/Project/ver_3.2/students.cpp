#include "students.h"
#include "student.h"
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

List* students = NULL;

float TotalAve = 0.0f;		
int NumberOfStudent = 0;	


bool AddStudent(){
	Student* std = new Student;

	std->sNo = NumberOfStudent + 1;
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> std->name >> std->kor >> std->eng >> std->math;
	std->ave = float(std->kor + std->eng + std->math) / 3.0f;

	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;		

	TotalAve = (TotalAve * prev / current) + (std->ave / current);

	NumberOfStudent++;
	InsertNodeAfter(GetTail(students), std);

	return true;
}

void ShowAll(){
	cout.precision(2);
	cout << fixed;
	cout << "\n           < ��ü ���� ���� >";
	cout << "\n   �й�  �̸�  ���� ���� ����   ���\n";

	Node* current = students->head->next;
	while (current != students->head){
		const Student* std = (Student*)GetData(current);

		cout << setw(7) << std->sNo << setw(7) << std->name;
		cout << setw(5) << std->kor << setw(5) << std->eng;
		cout << setw(5) << std->math << setw(7) << std->ave << "\n";

		current = GetNext(current);
	}
	cout << "\n��ü ��� = " << TotalAve << "\n";
}

void DeleteData(void* data){

	delete (Student*)data;
}

void Setup(){
	students = CreateList(&DeleteData);
}

void Teardown(){
	RemoveList(students, true);
}
