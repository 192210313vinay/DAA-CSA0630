#include<stdio.h>
int main(){
    int arr1[100],i,n,p,inval;
    printf("Input the size of the array:");
    scanf("%d",&n);
    printf("Input %d elements in the array:\n",n);
    for(i=0;i<n;i++){
        printf("element-%d:",i);
        scanf("%d",&arr1[i]);
    }
    printf("Input the value to be inserted:");
    scanf("%d",&inval);
    printf("Input the position to insert the value (0 to %d):",n);
    scanf("%d",&p);
    if(p<0||p>n){
        printf("Invalid position.\n");
    } else{
        for(i=n;i>=p;i--){
            arr1[i]=arr1[i-1];
        }
        arr1[p]=inval;
        printf("\nAfter Insert the list is:\n");
        for(i=0;i<=n;i++){
            printf("% 5d",arr1[i]);
        }
        printf("\nIndex of the inserted value: %d\n",p);
    }
    printf("\n");
}
