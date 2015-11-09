#include "students.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 한 명의 학생에대한 정보를
// 보관할 구조체
struct Student
{
	int sNo;			// 학번
	string name;		// 이름
	int kor, eng, math, sci;	// 국영수과 점수
	float ave;			// 평균
};


// 배열 대신에 링크드 리스트를 사용해서 구조체를 보관한다.
List* students = NULL;

float TotalAve = 0.0f;		// 전체 평균
int NumberOfStudent = 0;	// 현재까지 입력된 학생 수

// 학생을 한 명 추가한다.
// 반환값 : 더 이상 입력할 수 없는 경우 false 반환
bool AddStudent()
{
	// 여기 인원 제한을 검사하던 코드가 없어졌다.

	// 링크드 리스트에 넣기 위해서 
	// Stduent 변수를 하나 동적으로 할당한다.
	Student* std = new Student;

	// 해당 학생의 학생번호를 자동으로 입력한다.
	std->sNo = NumberOfStudent + 1;

	// 해당 학생의 이름, 국영수 점수를 입력받는다.
	cout << "이름(공백없이) 국어, 영어, 수학, 과학 점수를 입력하세요 : \n";
	cin >> std->name >> std->kor >> std->eng >> std->math >> std->sci;

	// 개인 평균을 계산한다.
	std->ave = float(std->kor + std->eng + std->math + std->sci) / 4.0f;

	// 기존값을 사용해서 새로운 전체 평균을 계산한다.
	const int current = NumberOfStudent + 1;// 현재까지 입력받은 학생 수
	const int prev = NumberOfStudent;		// 조금 전까지 입력받은 학생 수

	TotalAve = (TotalAve * prev / current) + (std->ave / current);

	// 입력받은 학생 수를 증가시킨다.
	NumberOfStudent++;

	// students 리스트에 새 노드를 추가한다.
	InsertNodeAfter(GetTail(students), std);

	return true;
}

// 전체 성적을 보여준다.
void ShowAll()
{
	// 실수 출력시에 소수점 이하 두 자리만 표시되도록 한다.
	cout.precision(2);
	cout << fixed;

	// 타이틀 부분을 출력한다.
	cout << "\n                   < 전체 성적 보기 >";
	cout << "\n   학번   이름   국어  영어  수학  과학    평균\n";

	// 리스트에 있는 모든 학생의 정보를 출력한다.
	Node* current = students->head->next;
	while (current != students->head)
	{
		// 현재 노드의 데이타를 꺼내온다.
		const Student* std = (Student*)GetData(current);

		// 해당 학생의 정보를 출력한다.
		cout << setw(6) << std->sNo << setw(7) << std->name;
		cout << setw(6) << std->kor << setw(6) << std->eng;
		cout << setw(6) << std->math << setw(6) << std->sci;
		cout << setw(9) << std->ave << "\n";

		// 다음 노드를 가리킨다.
		current = GetNext(current);
	}

	// 전체 평균을 출력한다.
	cout << "\n전체 평균 = " << TotalAve << "\n";
}

// 링크드 리스트의 데이터 제거용 함수
// (링크드 리스트가 노드의 데이타를
// 제거할 때 이 함수를 호출한다.)
void DeleteData(void* data)
{
	// Student 구조체를 바꿔서 제거한다.
	delete (Student*)data;
}

// 초기화 한다.
void Setup()
{
	// 리스트를 생성한다.
	// 데이터 제거 함수를 인자로 넘겨준다.
	students = CreateList(&DeleteData);
}

// 사용한 리소스를 정리한다.
void Teardown()
{
	// 리스트를 정리한다.
	RemoveList(students, true);
}
