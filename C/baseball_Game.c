/***		야구 게임
*		작성일 : 2013/12/30
**/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int i, j;
	int strike = 0, ball = 0, cnt = 0;
	int comAry[2] = { 0 }, userAry[2] = { 0 };

	srand((int)time(NULL));
	
	for (i = 0; i < 3; i++){
		comAry[i] = (rand() % 9) + 1;
		printf("%d	", comAry[i]);
	}

	puts("\nStart Game!");

	while (1){
		printf("\n3개의 숫자 선택: ");
		strike = 0, ball = 0, cnt++;
		
		for (i = 0; i < 3; i++)
			scanf("%d", &userAry[i]);

		printf("%d번째 도전결과 : ", cnt);
		//fflush(stdin);

		for (i = 0; i < 3; i++){
			if (comAry[i] == userAry[i])
				strike++;
			else {
				for (j = 0; j < 3; j++){
					if (comAry[i] == userAry[j])
						ball++;
				}
			}			
		}
		printf("%dstrike, %dball!!\n", strike, ball);
		
		if (strike == 3){
			puts("Game End!");
			exit(0);
		}
	}
}