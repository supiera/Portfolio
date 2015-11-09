#include "students.h"
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

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
float TotalAve = 0.0f;
int NumberOfStudent = 0;

bool AddStudent(){
	if (MAX_STUDENTS == NumberOfStudent) 
		return false;

	Student& std = students[NumberOfStudent];
	std.sNo = NumberOfStudent + 1;

	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> std.name >> std.kor >> std.eng >> std.math;

	std.ave = float(std.kor + std.eng + std.math) / 3.0f;

	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;

	TotalAve = (TotalAve * prev / current ) + (std.ave / current);
	NumberOfStudent++;

	return true;
}

void ShowAll(){
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
}