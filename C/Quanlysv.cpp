#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 50
char sv[MAX][30],tg[30];
int n=0;
void Bosungds() {
	while (n<MAX){
		printf("Nhap vao ho ten sv thu %d: ",n+1);
		fflush(stdin);gets(sv[n]);
		if (sv[n][0]=='\0') break;
		n++;
	}
}
void Sapxep() {
	int i,j,k;
	for(i=0;i<=n-1;i++) {
		k=i;
		for (j=i;j<n;j++)	
			if (strcmp(sv[k],sv[j])>0) k=j;
		if (k>i)	{
			strcpy(tg,sv[k]);
			strcpy(sv[k],sv[i]);
			strcpy(sv[i],tg);
		}
	}
	printf("Da sap xep xong.");
	getch();
}
int vitriten(char a[30]){
	int i= strlen(a)-1;
	while(a[i]==' '&& i>-1) i--;
	while(a[i]!=' '&& i>-1) i--;
	return i+1;
	
}
void SapxepVN() {
	int i,j,k;
	for(i=0;i<=n-1;i++) {
		k=i;
		for (j=i;j<n;j++)	
			if (strcmp(sv[k]+vitriten(sv[k]),sv[j]+vitriten(sv[j]))>0) k=j;
			else if (strcmp(sv[k]+vitriten(sv[k]),sv[j]+vitriten(sv[j]))>0) 
					if(strcmp(sv[k],sv[j])>0) k=j;
		if (k>i)	{
			strcpy(tg,sv[k]);
			strcpy(sv[k],sv[i]);
			strcpy(sv[i],tg);
		}
	}
	printf("Da sap xep xong.");
	getch();
}
void Inds(){
int i;
printf("Danh sach sinh vien: \n");
for(i=0;i<n;i++) printf("%s \n",sv[i]);
getch();
}
	
int main(){
char ch,cha;
	while (1){
 		system("cls");
 	 printf("\n\n\n\n");
	 printf("\n       		Quan li sinh vien");
	 printf("\n      	1,bo sung danh sach");
	 printf("\n      	2,sap xep danh sach");
	 printf("\n      	3,sap xep danh sach theo VN");
 	 printf("\n      	4,in danh sach");
 	 printf("\n      Bam 1-4 de chon,phim khac de ket thuc\n");
 	 ch= getch();
 	 if (ch=='1') Bosungds();
 	 else if (ch=='2') Sapxep();
	 else if (ch=='3') SapxepVN();
 	 else if (ch=='4') Inds();
 	 else{
 	 	printf("\n chan roi a? Yes or No");
 	 	fflush(stdin);
 	 	ch=getch();
 	 	if (ch=='y'||ch=='Y') break;
 	
 	 	 }
   }
}
