#include<stdio.h>
#include<conio.h>
int main(){
	int num,i,j,k=1;
	printf("enter the number :");
	scanf("%d",&num);
	for(i=1;i<=num;i++){
		for(j=1;j<=i;j++){
			printf("%3d",k++);
		}
		printf("\n");
	}
	return 0;
}
