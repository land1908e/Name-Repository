#include<stdio.h>
#include<conio.h>
int main()
{
	int N,i,a[9],tongUoc=0,j,soHoanThien=0;
	printf("Cho biet N ");
	scanf("%d",&N);
	printf("Nhap cac phan tu cua mang /n");
	for(i=0;i<N;i++)
	{
		printf("a%d= ",i+1);
		scanf("%d",&a[i]);
	}
	return 0;
}
