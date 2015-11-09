#include "Students.h"
#include "Student.h"
#include <iostream>
using namespace std;

Students::Students() 
	: students(&Students::DeleteData) {
	TotalAve = 0;
	NumberOfStudent = 0;
}

Students::~Students(){}

bool Students::AddStudent(bool general){
	Student* std;
	if (general)
		std = new Student(NumberOfStudent + 1);
	else
		std = new EngStudent(NumberOfStudent + 1);

	std->Input();

	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;

	TotalAve = (TotalAve * prev / current) + (std->GetAverage() / current);

	NumberOfStudent++;
	students.InsertNodeAfter(students.GetTail(), std);
	return true;
}

void Students::ShowAll(){
	cout.precision(2);
	cout << fixed;

	cout << "\n            < 전체 성적 보기 >";
	cout << "\n   학번  이름   국어 영어 수학 고급영어  평균\n";

	Node*current = students.GetHead()->GetNext();
	while (current != students.GetHead()){
		const Student* std = (Student*)current->GetData();

		std->Show();
		current = current->GetNext;
	}
	cout << "\n전체 평균 = " << TotalAve << "\n";
}

void Students::DeleteData(void* data){
	delete (Student*)data;
}