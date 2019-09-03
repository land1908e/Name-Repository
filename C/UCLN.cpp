#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,i;
	printf("nhap a "); scanf("%d",&a);
	printf("nhap b "); scanf("%d",&b);
	if(a>=b)
	{
		for(i=b;i>=1;i--)
		{
			if(a%i==0&&b%i==0) 
			{
			 printf("UCLN =%d",i);
		     break;
	
			}
		}
	}
	else
	{
		for(i=a;i>=1;i--)
		{
			if(b%i==0&&a%i==0)
			{
				printf("UCLN =%d",i);
				break;
		
			}
		}
	}
	return 0;
}
