/* 프로그램명 : 다항식의 덧셈 프로그램 Polynomial
   작성자 : 정 연주			작성일 : 2013.10.01 */
#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a>b)?a:b) // a>b가 참이면 a반환, 거짓이면 b반환
#define MAX_DEGREE 50	//최고차항을 50으로 제한

/*구조체 polynomial 선언*/
typedef struct{
	int degree;				//항의 차수를 저장 변수
	float coef[MAX_DEGREE];	//항의 계수를 저장 1차원 배열
} polynomial;

polynomial addPoly(polynomial A, polynomial B)	// add polynomial 
{
	polynomial C;
	int A_index=0, B_index=0, C_index=0;
	int A_degree=A.degree, B_degree=B.degree;
	C.degree=MAX(A.degree,B.degree);

	while(A_index<=A.degree && B_index<=B.degree){
		if(A_degree > B_degree){
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if(A_degree == B_degree){
			C.coef[C_index++]=A.coef[A_index++]+B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else{
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}

void printPoly(polynomial P)
{
	int i, degree;
	degree=P.degree;

	for(i=0; i<=P.degree; i++)
		printf("%3.0fx^%d",P.coef[i], degree--);
	printf("\n");
}

int Home(){			// Start Menu
	int val;
	printf(" *** 다항식 덧셈 프로그램 *** \n");
	printf("1. 덧셈하기 \n");
	printf("2. 종료 \n");
	printf(">> ");
	scanf("%d", &val);

	return val;
}

/* polynomial inputA(polynomial A){	// input A of coefficient and exponent
	int i;
	int A_index=0;
	system("cls");

	printf("첫번째 식(A)의 최고차항 입력 : ");
	scanf("%d", &A.degree);
	fflush(stdin);
	printf("\t첫번째 식(A)의 계수 입력 : ");
	for (i=A.degree; i<0; i--, A_index++){
		scanf("%d", A.coef[A_index]);
		printf("\n");
		fflush(stdin);
	}
	printf("\n\n");

	return A;
}
*/
polynomial inputB(polynomial B){	// input B of coefficient and exponent
	int i;
	int B_index=0;
	system("cls");

	printf("두번째 식(B)의 최고차항 입력 : ");
	scanf("%d", &B.degree);
	fflush(stdin);
	printf("\t두번째 식(B)의 계수 입력 : ");
	for (i=B.degree; i<0; i--, B_index++){
		scanf("%d", B.coef[B_index]);
		printf("\n");
		fflush(stdin);
	}
	
	//polynomial B = {B.degree, {B.coef[B_index]}};
	return B;
}
void main()
{	
	int val;
	polynomial A;
	polynomial B;
	polynomial C;
	val = Home();

	switch (val) {
		case 1:
			int i;
			int A_index=0;
			system("cls");

			printf("첫번째 식(A)의 최고차항 입력 : ");
			scanf("%d", &A.degree);
			fflush(stdin);
			printf("\t첫번째 식(A)의 계수 입력 : ");
			for (i=A.degree; i<0; i--, A_index++){
				scanf("%d", A.coef[A_index]);
				printf("\n");
				fflush(stdin);
			}
			printf("\n\n");

			/*inputB(B);
			C=addPoly(A, B);
			printf("\n A(x)="); printPoly(A);
			printf("\n B(x)="); printPoly(B);
			printf("\n C(x)="); printPoly(C); */
			break;
		case 2:
			exit(1);
			break;
		default:
			getchar();
			break;
	}
	
	//polynomial A={3, {4,3,5,0}};	//{최고차항, {계수부}}
	//polynomial B={4, {3,1,0,2,1}};

	/*polynomial C;
	

	
	
	getchar(); */
}

/*void printP() {
	polynomial A;
	polynomial B;
	polynomial C;
	C= addPoly(A, B);
	
}*/