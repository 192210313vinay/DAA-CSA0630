#include <stdio.h>
int main() {
  int arr[100],n;
  printf("enter the value of n:");
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
  	scanf("%d",&arr[i]);
  }
  for(i=0;i<n;i++){
  	if(arr[0]<arr[i]){
  		arr[0]=arr[i];
	  }
}
	  printf("the largest number is %d",arr[i]);

return 0;

}

  
