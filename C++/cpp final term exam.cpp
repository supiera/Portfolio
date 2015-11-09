/*		CPP PROJECT		제출일자 : 2014-06-11
*		제출자:정연주	 학번 : 2013301165 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
using namespace::std;

#define MAX 10			// 개설 가능한 최대 계좌 수
const int NAME_LEN = 20;

typedef struct _Account{
	int id_165;
	char name_165[NAME_LEN];
	int balance_165;				// 통장 총합 잔액
	double avr_165;					// 은행 잔고 평균
	int rank;						// 랭킹 순위 
	int s1_money, s2_money, s3_money;		//3개의 통장
	int job_165, nation_165;

	string phone_165, address_165;
	string jobs_165, nations_165;
	string credit_165;			//신용등급
}Account;

Account pArray[MAX];				// ACCOUNT

int index = 0;			//생성 된 계좌 수 카운트

void calc();		//계좌 합계, 평균, 랭크 계산
void PrintMenu();	//메인화면
void MakeAccount();	//계좌 개설
void Deposit();		//예금
void Withdraw();	//출금
void Inquire();		//잔액확인
void Information();	//고객정보확인
void CustList();	//고객랭크, 총합산 잔액 확인

enum MENU{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, INFO, LIST, EXIT };		//메뉴선택
enum JOB{							// 직업선택
	STUDENT = 1, DOCTOR, PROGRAMMER, PROFESSOR, OTHER
};
enum NATIONALITY { KOREA = 1, JAPAN, USA, CHINA, ETC };		//국가선택

/* ENUM TO STRING*/
void enum_to_String(){
	for (int i = 0; i < index; i++){
		if (pArray[i].job_165 == 1)
			pArray[i].jobs_165 = "STUDENT";
		else if (pArray[i].job_165 == 2)
			pArray[i].jobs_165 = "DOCTOR";
		else if (pArray[i].job_165 == 3)
			pArray[i].jobs_165 = "PROGRAMMER";
		else if (pArray[i].job_165 == 4)
			pArray[i].jobs_165 = "PROFESSOR";
		else if (pArray[i].job_165 == 5)
			pArray[i].jobs_165 = "OTHER";
		else
			pArray[i].jobs_165 = "NO JOB";
	}
	for (int i = 0; i < index; i++){
		if (pArray[i].nation_165 == 1)
			pArray[i].nations_165 = "KOREA";
		else if (pArray[i].nation_165 == 2)
			pArray[i].nations_165 = "JAPAN";
		else if (pArray[i].nation_165 == 3)
			pArray[i].nations_165 = "USA";
		else if (pArray[i].nation_165 == 4)
			pArray[i].nations_165 = "CHINA";
		else if (pArray[i].nation_165 == 5)
			pArray[i].nations_165 = "ETC";
		else
			pArray[i].nations_165 = "NO NATIONS";
	}
}

/*MAIN FUNCTION*/
int main(){
	int choice;

	while (1){
		system("cls");
		PrintMenu();
		cout << "SELECT : ";
		cin >> choice;

		switch (choice){
		case MAKE:
			MakeAccount();
			break;

		case DEPOSIT:
			system("cls");
			if (index == 0){			// 계좌를 하나도 만들지 않았을 때
				cout << "\n" << " HAVE NOTHING ACCOUNT! " << endl;
				system("PAUSE");
				continue;
			}
			Deposit();
			break;

		case WITHDRAW:
			if (index == 0){			// 계좌를 하나도 만들지 않았을 때
				cout << "\n" << " HAVE NOTHING ACCOUNT! " << endl;
				system("PAUSE");
				continue;
			}
			Withdraw();
			break;

		case INQUIRE:
			if (index == 0){			// 계좌를 하나도 만들지 않았을 때
				cout << "\n" << " HAVE NOTHING ACCOUNT! " << endl;
				system("PAUSE");
				continue;
			}
			Inquire();
			break;

		case INFO:
			if (index == 0){			// 계좌를 하나도 만들지 않았을 때
				cout << "\n" << " HAVE NOTHING ACCOUNT! " << endl;
				system("PAUSE");
				continue;
			}
			Information();
			break;

		case LIST:
			if (index == 0){			// 계좌를 하나도 만들지 않았을 때
				cout << "\n" << " HAVE NOTHING ACCOUNT! " << endl;
				system("PAUSE");
				continue;
			}
			CustList();
			break;

		case EXIT:
			system("cls");
			cout << " EXIT PROGRAM ..." << endl;
			return 0;

		default:
			cout << "Illegal selection.. " << endl;
			break;
		}
		calc();
		fflush(stdin);
	}
}

/*CALCULATE*/
void calc(){
	Account temp;
	for (int i = 0; i < index; i++){
		// TOTAL BALANCE
		pArray[i].balance_165 = pArray[i].s1_money + pArray[i].s2_money + pArray[i].s3_money;
		// AVAERAGE IN BANK
		pArray[i].avr_165 = (double)pArray[i].balance_165 / 3;

		// CREDIT
		if ((pArray[i].avr_165 > 0) && (pArray[i].avr_165 <= 100))
			pArray[i].credit_165 = "C";
		else if ((pArray[i].avr_165 > 100) && (pArray[i].avr_165 <= 1000))
			pArray[i].credit_165 = "B";
		else if ((pArray[i].avr_165 > 1000) && (pArray[i].avr_165 <= 10000))
			pArray[i].credit_165 = "A";
		else if (pArray[i].avr_165 > 10000)
			pArray[i].credit_165 = "VIP";
		else
			pArray[i].credit_165 = "NULL";
	}

	// RANK
	for (int i = 0; i < index; ++i){
		pArray[i].rank = 1;
		for (int j = 0; j < index; ++j){
			if (pArray[i].avr_165 < pArray[j].avr_165)
				++pArray[i].rank;
		}
	}

	// SORT
	for (int i = 0; i < index - 1; ++i){
		for (int j = 0; j < index - 1 - i; j++){
			if (pArray[j].avr_165 < pArray[j + 1].avr_165){
				temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
		}
	}
}

/*CUSTOMER INFORMATION*/
void Information(){
	system("cls");
	int val;

	cout << "CUSTOMER INFORMATION ----------------" << endl;
	cout << " ACCOUNT ID : "; cin >> val;
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == val){
			cout << endl;
			cout << "  ID : " << pArray[i].id_165 << endl;
			cout << "  NAME : " << pArray[i].name_165 << endl;
			cout << "  ADDRESS : " << pArray[i].address_165 << endl;
			cout << "  PHONE : " << pArray[i].phone_165 << endl;
			cout << "  JOB : " << pArray[i].jobs_165 << endl;
			cout << "  NATIONALITY : " << pArray[i].nations_165 << endl;
			cout << "  BALANCE : " << pArray[i].balance_165 << endl;
			cout << "  CREDIT : " << pArray[i].credit_165 << endl << endl;
			system("PAUSE");
			return;
		}
	}
	cout << "\n" << "ACCOUNT ID IS NOT EXIST!" << endl;
	system("PAUSE");
	return;
}

/*CUSTOMER LIST*/
void CustList(){
	system("cls");

	cout << "CUSTOMER LIST ------------------" << endl;
	cout << "   ID     NAME      TOTAL MONEY    AVERAGE BALANCE     CREDIT  RANK " << endl;

	for (int i = 0; i < index; i++){
		cout << setw(5) << pArray[i].id_165 << setw(8);
		cout << pArray[i].name_165 << setw(14) << pArray[i].balance_165;
		cout << setw(16) << pArray[i].avr_165 << setw(13);
		cout << pArray[i].credit_165 << setw(8) << pArray[i].rank << endl;
	}
	system("PAUSE");
}
/*PRINT MENU*/
void PrintMenu(){
	cout << "--------------- BANK ACCOUNT SYSTEM ------------------" << endl;
	cout << "1. MAKE A ACCOUNT " << endl;
	cout << "2. DEPOSIT " << endl;
	cout << "3. WITHDRAW " << endl;
	cout << "4. CHECKING BALANCE " << endl;
	cout << "5. CUSTOMER INFORMATION" << endl;
	cout << "6. CHECK CUSTOMER LIST" << endl;
	cout << "7. EXIT " << endl;
}

/*MAKE ACCOUNT*/
void MakeAccount(){
	system("cls");
	int job, nation;

	pArray[index].s1_money = 0;
	pArray[index].s2_money = 0;
	pArray[index].s3_money = 0;

	cout << " MAKE ACCOUNT ----------" << endl;
	cout << " ACCOUNT ID : "; cin >> pArray[index].id_165;
	// 중복된 id검사
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == pArray[index].id_165){
			cout << " Duplicated ID !" << endl;
			system("PAUSE");
			return;
		}
	}
	cout << " NAME : "; cin >> pArray[index].name_165;
	cout << " PHONE : "; cin >> pArray[index].phone_165;
	cout << " Deposit Money into 1st BANK BOOK : "; cin >> pArray[index].s1_money;
	cout << " Deposit Money into 2nd BANK BOOK : "; cin >> pArray[index].s2_money;
	cout << " Deposit Money into 3rd BANK BOOK : "; cin >> pArray[index].s3_money;

	cout << " <JOB>" << endl; cout << " 1.STUDENT 2.DOCTOR 3.PROGRAMMER 4.PROFESSOR 5.OTHER" << endl;
	cout << " JOB : "; cin >> job;
	pArray[index].job_165 = (JOB)job;
	cout << " <NATIONALITY>" << endl; cout << " 1.KOREA 2.JAPAN 3.USA 4.CHINA 5.ETC" << endl;
	cout << " NATIONALITY : "; cin >> nation;
	pArray[index].nation_165 = (NATIONALITY)nation;
	cout << " ADDRESS : "; cin >> pArray[index].address_165;

	index++;		//계좌 생성수 카운트
	enum_to_String();
	cout << "\n" << "Account is Created" << endl;
	system("PAUSE");
}

/*DEPOSIT MONEY*/
void Deposit(){

	int val, book, dep;
	cout << "DEPOSIT MONEY ------------" << endl;
	cout << " ACCOUNT ID : "; cin >> val;
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == val){				// ID와 계좌 ID가 같은게 있는지 찾기
			cout << " CHOOSE BANK BOOK : "; cin >> book;

			// 통장번호 없을 때
			if (book > 3){
				cout << "\n" << " BANK BOOK IS NOT EXIST!" << endl;
				system("PAUSE");
				return;
			}

			cout << " HOW MUCH DO YOU WANT DEPOSIT ? : "; cin >> dep;
			if (book == 1)
				pArray[i].s1_money += dep;
			else if (book == 2)
				pArray[i].s2_money += dep;
			else if (book == 3)
				pArray[i].s3_money += dep;

			cout << "\n" << " successed!" << endl;
			system("PAUSE");
			return;
		}
	}
	cout << "\n" << "ACCOUNT ID IS NOT EXIST!" << endl;
	system("PAUSE");
	return;
}
/*LOAN*/
void Loan(int bknum){		//bankbook Number받음
	system("cls");

	int val, want;
	int limit;		//한도
	cout << "LOAN MONEY ----------------" << endl;
	cout << " ACCOUNT ID : "; cin >> val;
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == val){
			cout << " YOUR CREDIT IS " << pArray[i].credit_165 << endl;
			cout << " CREDIT LIMIT : ";			// 크레딧 한도
			if (pArray[i].credit_165 == "C")
				limit = 100;
			else if (pArray[i].credit_165 == "B")
				limit = 1000;
			else if (pArray[i].credit_165 == "A")
				limit = 1000;
			else if (pArray[i].credit_165 == "VIP")
				limit = 10000;
			else
				limit = 0;

			cout << limit << endl << endl;
			cout << " HOW MUCH YOU WANT LOAN THE MONEY ?" << endl; cin >> want;
			if (want > limit){
				cout << " OVER CREDIT LIMIT ! " << endl;
				system("PAUSE");
				return;
			}
			else {
				if (bknum == 1)
					pArray[i].s1_money += want;
				else if (bknum == 2)
					pArray[i].s2_money += want;
				else if (bknum == 3)
					pArray[i].s3_money += want;
				cout << " BANKBOOK " << bknum << " IN DEPOSITED ! " << endl;
				system("PAUSE");
				return;
			}
		}
	}
	cout << "\n" << "ACCOUNT ID IS NOT EXIST!" << endl;
	system("PAUSE");
	return;
}

/*WITHDRAW MONEY*/
void Withdraw(){
	system("cls");

	int val, book, wit;
	char check;
	cout << "WITHDRAW MONEY ------------" << endl;
	cout << "ACCOUNT ID : "; cin >> val;
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == val){
			cout << "CHOOSE BANK BOOK : "; cin >> book;

			// 통장번호 없을 때
			if (book > 3){
				cout << "\n" << "BANK BOOK IS NOT EXIST!" << endl;
				system("PAUSE");
				return;
			}

			cout << "HOW MUCH DO YOU WANT WITHDRAW ? "; cin >> wit;
			if (book == 1){
				if (pArray[i].s1_money < wit){				// 잔액보다 인출금액이 더 클 때 
					cout << " NOT ENOUGH MONEY ! " << endl;
					cout << " IF YOU WANT LOAN MONEY PRESS \"Y\"" << endl;
					cout << " ELSE PRESS ANY KEY TO MAIN MANU" << endl;
					cin >> check;
					if (check == 'Y' || check == 'y')
						Loan(1);
					else
						system("PAUSE");
					return;
				}
				else {
					pArray[i].s1_money -= wit;
					cout << "\n" << " Successed!" << endl;
					system("PAUSE");
					return;
				}
			}
			else if (book == 2){
				if (pArray[i].s2_money < wit){
					cout << " NOT ENOUGH MONEY ! " << endl;
					cout << " IF YOU WANT LOAN MONEY PRESS \"Y\"" << endl;
					cout << " ELSE PRESS ANY KEY TO MAIN MANU" << endl;
					cin >> check;
					if (check == 'Y' || check == 'y')
						Loan(2);
					else
						system("PAUSE");
					return;
				}
				else{
					pArray[i].s2_money -= wit;
					cout << "\n" << " Successed!" << endl;
					system("PAUSE");
					return;
				}
			}
			else if (book == 3){
				if (pArray[i].s3_money < wit){
					cout << " NOT ENOUGH MONEY ! " << endl;
					cout << " IF YOU WANT LOAN MONEY PRESS \"Y\"" << endl;
					cout << " ELSE PRESS ANY KEY TO MAIN MANU" << endl;
					cin >> check;
					if (check == 'Y' || check == 'y')
						Loan(3);
					else
						system("PAUSE");
					return;
				}
				else {
					pArray[i].s3_money -= wit;
					cout << "\n" << " Successed!" << endl;
					system("PAUSE");
					return;
				}
			}
		}
	}
	cout << "\n" << "ACCOUNT ID IS NOT EXIST!" << endl;
	system("PAUSE");
	return;
}

/*CHECKING BALANCE*/
void Inquire(){
	system("cls");
	int val;
	cout << "CHECKING BALANCE ------------" << endl;
	cout << " ACCOUNT ID : "; cin >> val;
	for (int i = 0; i < index; ++i){
		if (pArray[i].id_165 == val){
			cout << " 1st BANK BOOK Balance : " << pArray[i].s1_money << endl;
			cout << " 2nd BANK BOOK Balance : " << pArray[i].s2_money << endl;
			cout << " 3rd BANK BOOK Balance : " << pArray[i].s3_money << endl;
			cout << "   Total Money in Bank : " << pArray[i].balance_165 << endl;
			cout << " Average Money in Bank : " << pArray[i].avr_165 << endl;
			cout << "                Credit : " << pArray[i].credit_165 << endl;
			system("PAUSE");
			return;
		}
	}
	cout << "\n" << "ACCOUNT ID IS NOT EXIST!" << endl;
	system("PAUSE");
	return;
}