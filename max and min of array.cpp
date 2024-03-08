#include<stdio.h>
int main(){
	int arr[100];
	int max,min,i,n;
	printf("enter the value of n:");
	scanf("%d",&n);
	printf("Input %d elements in the array :\n", n);
	for(i=0;i<n;i++){
		printf("elements_%d",i);
		scanf("%d",&arr[i]);
	}
	max=arr[0];
	min=arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
		
	}
	printf("maximum number is%d",max);
	printf("manimum number is%d",min);
	return 0;
}
