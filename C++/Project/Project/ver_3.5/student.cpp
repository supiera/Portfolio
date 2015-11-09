#include "student.h"
#include "BaseOutput.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(int sNo){
	this->sNo = sNo;
	kor = eng = math = 0;
	ave = 0.0f;
}

Student::~Student(){}

void Student::Input(){
	cout << "이름(공백없이) 국어, 영어, 수학 점수를 입력하세요 : \n";
	cin >> name >> kor >> eng >> math;

	ave = float(kor + eng + math) / 3.0f;
}

void Student::Show(BaseOutput& out) const{
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " ";
	ss << eng << " " << math << "-" << ave;
	
	string record[7];
	for(int i=0; i<7; ++i)
		ss >> record[i];
	out.PutRecord(record);
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
	cout << "이름(공백없이) 국어, 영어, 수학, 고급영어 점수를 입력하세요 : \n";
	cin >> name >> kor >> eng >> math >> hi_eng;

	ave = float(kor + eng + math + hi_eng) / 4.0f;
}

void EngStudent::Show(BaseOutput& out) const{
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " " ;
	ss << eng << " " << math << " " << hi_eng << ave;

	string record[7];
	for (int i = 0; i<7; ++i)
		ss >> record[i];
	out.PutRecord(record);

}