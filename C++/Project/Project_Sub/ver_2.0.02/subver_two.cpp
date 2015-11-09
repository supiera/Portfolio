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
				Student& stu = students[NumberOfStudent];
				stu.sNo = NumberOfStudent + 1;

	 			cout << "이름(공백없이) 국어, 영어, 수학, 과학 점수를 입력하세요 : \n";
				cin >> stu.name >> stu.kor >> stu.eng >> stu.math >> stu.sci;

				stu.total = (stu.kor + stu.eng + stu.math + stu.sci);
				stu.ave = (float)stu.total / 4.0f;

				const int current = NumberOfStudent + 1;
				const int prev = NumberOfStudent;

				TotalAve = (TotalAve * prev / current ) + (stu.ave / current);
				NumberOfStudent++;

				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";

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

				cout << "\n             < 전체 성적 보기 >";
				cout << "\n     학번  이름  국어 영어 수학 과학 평균\n";
 
	
				for (int i = 0; i < NumberOfStudent; ++i){
					const Student& stu = students[i];
					cout << setw(7) << stu.sNo << setw(8) << stu.name;
					cout << setw(5) << stu.kor << setw(5) << stu.eng;
					cout << setw(5) << stu.sci;
					cout << setw(5) << stu.math << setw(7) << stu.ave << "\n";
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
