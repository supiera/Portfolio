/*	프로젝트 명 : 가위바위보 게임
	작성자 : 정연주 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h> // 컴퓨터의 현재의 시간과 1970년 1월 1일 이후의 시간적 차를 초단위로 계산해서 반환해준다 

void main(){ 
	int win=0, draw=0, lose=0;
	int user, com,  i;
	char choice;
	srand((int)time(NULL));		// 현재 시간을 이용해서 시드설정, 껐다가 켜도 중복되게 나오는 수 방지하기 위해서 선언
								// 시드seed는 난수 생성을 위해 씨앗을 심는 용도로 사용되는 함수
	while(1) {
		com = (rand() % 3) + 1;				// 1이상 3이하의 난수생성
		printf("computers num : %d\n", com);	// 난수 확인출력문
		printf("******* Game START *******\n");
		printf("1. 바위 2. 가위 3. 보\n4. 결과확인하기\n0. 종료\n\n");
		printf(">> : ");
		scanf("%d", &user);
		fflush(stdin);

		if (user >= 5 && user < 0){		// 이외의 값이 들어왔을때
			printf("4이하 0이상의 값을 입력해주세요\n");
			system("PAUSE");
			system("cls");
			continue;
		}

		else if (user == 4){ // 결과확인창
			do {
				system("cls");
				printf("< 결과 확인 > \n\n");
				printf("%d승\t%d무\t%d패\n\n", win, draw, lose);
				printf("게임을 계속하시겠습니까?(y/n) : ");
				scanf("%c", &choice);
				fflush(stdin);
				if (choice == 'y' || choice == 'Y'){
					break;}
				else if (choice == 'n' || choice == 'N'){
					system("cls");
					printf("종료합니다\n");
					exit(1);
				}	
			}while(choice != 'n' || choice != 'N');	
		}

		else if (user == 0){ // 게임내에서의 종료창
			system("cls");
			printf("종료합니다\n");
			exit(1);
		}

		else {
			switch (user){
				case 1: //유저가 묵일때
					if (com == 2){	//컴퓨터가 찌일때
						printf("Win!\n");
						win++;}
					else if(com == 3){ //컴퓨터가 빠일때
						printf("Lose!\n");
						lose++;}
					else if (com == user){ // 유저와 컴퓨터가 같을 때
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				case 2: //유저가 찌일때
					if (com == 1){	//컴퓨터가 묵일때
						printf("Lose!\n");
						lose++;}
					else if(com == 3){ //컴퓨터가 빠일때
						printf("Win!\n");
						win++;}
					else if (com == user){ // 유저와 컴퓨터가 같을 때
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				case 3: //유저가 빠일때
					if (com == 1){	//컴퓨터가 묵일때
						printf("Win!\n");
						win++;}
					else if(com == 2){ //컴퓨터가 빠일때
						printf("Lose!\n");
						lose++;}
					else if (com == user){ // 유저와 컴퓨터가 같을 때
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				default:
					printf("올바른 값을 입력해주세요\n");
					system("PAUSE");
					system("cls");
					continue;
				}								//switch문의 끝
		}										//else문의 끝
		system("cls");
	}											//while문의 끝
}												//함수의 끝