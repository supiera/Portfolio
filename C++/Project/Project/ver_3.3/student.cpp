#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(int sNo){
	this->sNo = sNo;
	kor = eng = math = 0;
	ave = 0.0f;
}

void Student::Input(){
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> name >> kor >> eng >> math;

	ave = float(kor + eng + math) / 3.0f;
}

void Student::Show() const{
	cout << setw(7) << sNo << setw(7) << name;
	cout << setw(5) << kor << setw(5) << eng;
	cout << setw(5) << math << setw(7) << ave << "\n";
}

int Student::GetStdNumber() const { return sNo; }
string Student::GetName() const { return name; }
int Student::GetKor() const { return kor; }
int Student::GetEng() const { return eng; }
int Student::GetMath() const { return math; }
float Student::GetAverage() const { return ave; }

EngStudent::EngStudent(int sNo) 
	: Student(sNo){
	hi_eng = 0;
}

void EngStudent::Input(){
	cout << "�̸�(�������) ����, ����, ����, ��޿��� ������ �Է��ϼ��� : \n";
	cin >> name >> kor >> eng >> math >> hi_eng;

	ave = float(kor + eng + math + hi_eng) / 4.0f;
}

void EngStudent::Show() const{
	cout << setw(7) << sNo << setw(7) << name;
	cout << setw(5) << kor << setw(5) << eng;
	cout << setw(5) << math << setw(9) << hi_eng;
	cout << setw(7) << ave << "\n";
}