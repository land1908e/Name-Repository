#include<stdio.h>
typedef struct Matrix {
	int Hang;
	int Cot;
	float *Giatri;
} Matrix;
Matrix SetMatrix(Matrix A){
	printf("Nhap so hang cua ma tran: ");
	scanf("%d",&A.Hang);
	printf("Nhap so cot cua ma tran: ");
	scanf("%d",&A.Cot);
	A.Giatri = new float[A.Hang*A.Cot];
	if(A.Giatri==NULL) printf("Ko du bo nho cap phat");
	else
		for (int i=1;i<=A.Hang;i++) 
		  for(int j=1;j<=A.Cot;j++){
			printf("\n Nhap vao phan tu hang %d cot %d: ",i,j);
			scanf("%f",&A.Giatri[(i-1)*A.Cot+j-1]);
	}
	return A;
}
void FreeMatrix(Matrix A){
	if(A.Giatri!=NULL) delete []A.Giatri;
	
}
Matrix operator * (Matrix A, Matrix B) {
	Matrix C;
	if (A.Cot == B.Hang) {
	C.Hang= A.Hang; C.Cot=B.Cot;
	C.Giatri = new float [C.Hang*C.Cot];
	for(int m=1;m<=A.Hang;m++)
		for(int n=1;n<=B.Cot;n++){
			C.Giatri[(m-1)*C.Cot+n-1]=0;
			for(int p=1;p<=A.Cot;p++)
			 	C.Giatri[(m-1)*C.Cot+n-1]+=A.Giatri[(m-1)*A.Cot+p-1] * B.Giatri[(p-1)*B.Cot+n-1];
			}
	return C;
	} else 	printf("Khong nhan duoc !");
}
Matrix operator + (Matrix A, Matrix B) {
	Matrix C;
	if (A.Hang == B.Hang && A.Cot==B.Cot) {
		C.Hang= A.Hang; C.Cot=B.Cot;
		C.Giatri = new float [C.Hang*C.Cot];
		for(int m=1;m<=C.Hang;m++)
			for(int n=1;n<=C.Cot;n++)
				C.Giatri[(m-1)*C.Cot+n-1]=A.Giatri[(m-1)*A.Cot+n-1]+B.Giatri[(m-1)*B.Cot+n-1];
    } else printf("Khong cong duoc");
    return C;
}
Matrix operator + (Matrix C, float a) {
	for(int m=1;m<=C.Hang;m++)
			for(int n=1;n<=C.Cot;n++)
				C.Giatri[(m-1)*C.Cot+n-1]+=a;
	return C;
}
Matrix operator * (Matrix C, float a) {
	for(int m=1;m<=C.Hang;m++)
			for(int n=1;n<=C.Cot;n++)
				C.Giatri[(m-1)*C.Cot+n-1]*=a;
	return C;
}
void PutsMatrix(Matrix A){
	for(int i=1;i<=A.Hang;i++){
		for(int j=1;j<=A.Cot;j++)
			printf("%7.2f ", A.Giatri[(i-1)*A.Cot+j-1]); 
		printf("\n");
	}			
}
int main (){
	Matrix A,B,C,D,E,F;
	A=SetMatrix(A);
	B=SetMatrix(B);
	C=A*B;
	D=A+B;
	E=A+2;
	F=B*2;
	printf("Ma tran tich la: \n");
	if (A.Cot == B.Hang)  PutsMatrix(C);
	printf("Ma tran tong la: \n");
	if (A.Hang == B.Hang && A.Cot==B.Cot) PutsMatrix(D);
	printf("\n");
 	PutsMatrix(E);
 	printf("\n");
 	PutsMatrix(F);
	FreeMatrix(A);
	FreeMatrix(B);
	FreeMatrix(C);
	FreeMatrix(D);
	FreeMatrix(E);
	FreeMatrix(F);
}
	
	
	
	
	
	
	
	
