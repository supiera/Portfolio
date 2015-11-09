// Update From ver 2.0
// Update  version 2.0.01 
// 	: additional Science Subject

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student{
	int sNo;
	string name;
	int kor, eng, math, sci;
	float ave;
};

int main(){
	const int MAX_STUDENTS = 100;
	Student students[MAX_STUDENTS];
	float TotalAve = 0.0f;
	int NumberOfStudent = 0;

	while(1){
		cout << "\n------ 메뉴 ------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기\n";
		cout << "Q. 프로그램 종료\n";
		cout << "------------------\n\n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		char select;
		cin >> select;

		switch(select) {
			case '1': {
				if (MAX_STUDENTS == NumberOfStudent) {
					cout << "\n더 이상 입력할 수 없습니다.\n";
					break;
				}
				Student& std = students[NumberOfStudent];
				std.sNo = NumberOfStudent + 1;

	 			cout << "이름(공백없이) 국어, 영어, 수학, 과학 점수를 입력하세요 : \n";
				cin >> std.name >> std.kor >> std.eng >> std.math >> std.sci;

				std.ave = float(std.kor + std.eng + std.math + std.sci) / 4.0f;

				const int current = NumberOfStudent + 1;
				const int prev = NumberOfStudent;

				TotalAve = (TotalAve * prev / current ) + (std.ave / current);
				NumberOfStudent++;

				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";

				break;
			}
			case '2': {
	 
				cout.precision(2);
				cout << fixed;

				cout << "\n             < 전체 성적 보기 >";
				cout << "\n     학번  이름  국어 영어 수학 과학 평균\n";
 
	
				for (int i = 0; i < NumberOfStudent; ++i){
					const Student& std = students[i];
					cout << setw(7) << std.sNo << setw(8) << std.name;
					cout << setw(5) << std.kor << setw(5) << std.eng;
					cout << setw(5) << std.sci;
					cout << setw(5) << std.math << setw(7) << std.ave << "\n";
				}
	 
				cout << "\n전체 평균 = " << TotalAve << "\n";
 
				break;
			}
			case 'Q':
			case 'q':
				cout << "\n프로그램을 종료합니다.\n";
				return 0;
			default:
				cout << "\n올바른 값을 입력해주세요.\n";
				break;
		}		//switch
	 }		//while
	 return 0;
}		//main
