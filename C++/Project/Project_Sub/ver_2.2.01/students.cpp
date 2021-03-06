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

	cout << "이름(공백없이) 국어, 영어, 수학, 과학 점수를 입력하세요 : \n";
	cin >> std.name >> std.kor >> std.eng >> std.math >> std.sci;

	std.total = (std.kor + std.eng + std.math + std.sci);
	std.ave = (float)std.total / 4.0f;

	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;

	TotalAve = (TotalAve * prev / current) + (std.ave / current);
	NumberOfStudent++;

	return true;
}

void ShowAll(){
	cout.precision(2);
	cout << fixed;

	Student temp;
	for (int i = 0; i < NumberOfStudent - 1; i++){
		for (int j = 0; j<NumberOfStudent - 1 - i; j++){
			if (students[j].total < students[j + 1].total){
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	cout << "\n               < 전체 성적 보기 >";
	cout << "\n     학번  이름  국어 영어 수학 과학 평균\n";


	for (int i = 0; i < NumberOfStudent; ++i){
		const Student& std = students[i];
		cout << setw(7) << std.sNo << setw(7) << std.name;
		cout << setw(5) << std.sci;
		cout << setw(5) << std.kor << setw(5) << std.eng;
		cout << setw(5) << std.math << setw(7) << std.ave << "\n";
	}

	cout << "\n전체 평균 = " << TotalAve << "\n";
}