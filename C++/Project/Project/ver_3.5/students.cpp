#include "students.h"
#include "student.h"
#include "ConsoleOutput.h"
#include "TextOutput.h"
#include "HTMLOutput.h"

#include <iostream>
#include <sstream>
using namespace std;

Students::Students() 
	: students(&Students::DeleteData) {
	TotalAve = 0.0f;
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

void Students::ShowAll(FORMAT fmt){
	BaseOutput* out;
	if(TEXTFILE == fmt)
		out = new TextOutput("report.txt");
	else if(HTMLFILE == fmt)
		out = new HTMLOutput("report.html");
	else
		out = new ConsoleOutput;

	out->BeginTable("<전체 성적 보기>");
	string header[7] = {"학번", "이름", "국어", "영어", "수학", "고급영어", "평균"};
	out->PutHeader(header, 7);

	Node* current = students.GetHead()->GetNext();

	while(current != students.GetHead()){
		const Student* std = (Student*)current->GetData();
		std->Show(*out);
		current = current->GetNext();
	}
	out->EndTable();

	stringstream ss;
	ss.precision(2);

	ss << fixed;
	ss << "전체 평균 = " << TotalAve;
	out->Write(ss.str());

	delete out;
	out = NULL;
}

void Students::DeleteData(void* data){
	delete (Student*)data;
}