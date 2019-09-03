#include<stdio.h>
int n;
int x[50];
int check(int j,int k) { //check x[k] co the gan bang j dc k
	int i;
	for (i=1;i<=k;i++){
		if (x[i]==j) return 0;
		if ((x[i]+i) ==j+k) return 0;
		if ((x[i]-i) ==j-k) return 0;
	}
	return 1;
}
void InKQ(){
	int i;
	for (i=1;i<=n;i++) printf("%d  ",x[i]);
	printf("\n");
}
void VeKQ(){
	int a,b;
	for (a=1;a<=n;a++){
		for (b=1;b<=n;b++)
			if (b!=x[a]) printf("O ");
			else printf("X ");
		printf("\n");
	}
	printf("\n");
}
int TRY(int k){
	int i;
	for(i=1;i<=n;i++)
	if (check(i,k)) {
		x[k]= i;
		if (k==n) {InKQ() ; VeKQ();}
		else TRY(k+1);
	}
}
int main(){
	printf("Nhap gia tri n= ");
	scanf("%d",&n);
	TRY(1);
}
