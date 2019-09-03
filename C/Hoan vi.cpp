#include<stdio.h>
int x[100], mark[100];
int n;
void PrintSolution(){
	for(int i=1;i<=n;i++) printf("%d, ",x[i]);
	printf("\n");
}
int TRY(int k){
	for(int i=1;i<=n;i++)
		if(!mark[i]){
			x[k]=i;
			mark[i]=true;
			if(k==n) { PrintSolution();
			} else TRY(k+1);
			mark[i]=0;
		}
}
int main(){
	printf("Nhap gia tri n= ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++) mark[i]=0;
	TRY(1);
}
