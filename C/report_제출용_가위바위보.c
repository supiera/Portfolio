/*	������Ʈ �� : ���������� ����
	�ۼ��� : ������ */
#include<stdio.h>
#include<stdlib.h>
#include<time.h> // ��ǻ���� ������ �ð��� 1970�� 1�� 1�� ������ �ð��� ���� �ʴ����� ����ؼ� ��ȯ���ش� 

void main(){ 
	int win=0, draw=0, lose=0;
	int user, com,  i;
	char choice;
	srand((int)time(NULL));		// ���� �ð��� �̿��ؼ� �õ弳��, ���ٰ� �ѵ� �ߺ��ǰ� ������ �� �����ϱ� ���ؼ� ����
								// �õ�seed�� ���� ������ ���� ������ �ɴ� �뵵�� ���Ǵ� �Լ�
	while(1) {
		com = (rand() % 3) + 1;				// 1�̻� 3������ ��������
		printf("computers num : %d\n", com);	// ���� Ȯ����¹�
		printf("******* Game START *******\n");
		printf("1. ���� 2. ���� 3. ��\n4. ���Ȯ���ϱ�\n0. ����\n\n");
		printf(">> : ");
		scanf("%d", &user);
		fflush(stdin);

		if (user >= 5 && user < 0){		// �̿��� ���� ��������
			printf("4���� 0�̻��� ���� �Է����ּ���\n");
			system("PAUSE");
			system("cls");
			continue;
		}

		else if (user == 4){ // ���Ȯ��â
			do {
				system("cls");
				printf("< ��� Ȯ�� > \n\n");
				printf("%d��\t%d��\t%d��\n\n", win, draw, lose);
				printf("������ ����Ͻðڽ��ϱ�?(y/n) : ");
				scanf("%c", &choice);
				fflush(stdin);
				if (choice == 'y' || choice == 'Y'){
					break;}
				else if (choice == 'n' || choice == 'N'){
					system("cls");
					printf("�����մϴ�\n");
					exit(1);
				}	
			}while(choice != 'n' || choice != 'N');	
		}

		else if (user == 0){ // ���ӳ������� ����â
			system("cls");
			printf("�����մϴ�\n");
			exit(1);
		}

		else {
			switch (user){
				case 1: //������ ���϶�
					if (com == 2){	//��ǻ�Ͱ� ���϶�
						printf("Win!\n");
						win++;}
					else if(com == 3){ //��ǻ�Ͱ� ���϶�
						printf("Lose!\n");
						lose++;}
					else if (com == user){ // ������ ��ǻ�Ͱ� ���� ��
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				case 2: //������ ���϶�
					if (com == 1){	//��ǻ�Ͱ� ���϶�
						printf("Lose!\n");
						lose++;}
					else if(com == 3){ //��ǻ�Ͱ� ���϶�
						printf("Win!\n");
						win++;}
					else if (com == user){ // ������ ��ǻ�Ͱ� ���� ��
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				case 3: //������ ���϶�
					if (com == 1){	//��ǻ�Ͱ� ���϶�
						printf("Win!\n");
						win++;}
					else if(com == 2){ //��ǻ�Ͱ� ���϶�
						printf("Lose!\n");
						lose++;}
					else if (com == user){ // ������ ��ǻ�Ͱ� ���� ��
						printf("Draw!\n");
						draw++;}
					system("PAUSE");
					break;
				default:
					printf("�ùٸ� ���� �Է����ּ���\n");
					system("PAUSE");
					system("cls");
					continue;
				}								//switch���� ��
		}										//else���� ��
		system("cls");
	}											//while���� ��
}												//�Լ��� ��