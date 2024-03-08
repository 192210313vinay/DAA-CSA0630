#include<stdio.h>
int main(){
	int n,count=0,i;
	printf("enter the value of n:");
	scanf("%d",&n);
    for(i=1;i<=n;i++){
    	if(n%i==0){
    		count++;
		}
	}
		if(count==2){
			printf("it is a prime number");
		}else{
			printf("it is not a prime number");
		}
		return 0;
	
}
