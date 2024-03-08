#include<stdio.h>
int main()
{
	int c=500,i,n;
	int a[]={100,75,50,25};
	printf("enter the number of boxes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		c=c-a[i];
		printf("%d\n is the left capacity",c);
	}
}
