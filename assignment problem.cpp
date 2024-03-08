#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define MAX_SIZE 5 
int N; 
int minCost; 
int calculateCost(int costMatrix[MAX_SIZE][MAX_SIZE], int assignment[MAX_SIZE]){
    int totalCost=0;
    for(int i=0;i<N;i++){
        totalCost+=costMatrix[i][assignment[i]];
    }
    return totalCost;
}
bool isAssigned(int job,int assignment[MAX_SIZE]){
    for(int i=0;i<N;i++){
        if(assignment[i]==job)
            return true;
    }
    return false;
}
void branchAndBound(int costMatrix[MAX_SIZE][MAX_SIZE],int row,int assignment[MAX_SIZE],int currentCost){
    if(row==N){
        if(currentCost<minCost){
            minCost=currentCost;
        }
        return;
    }
    for(int job=0;job<N;job++){
        if(!isAssigned(job,assignment)){
            assignment[row]=job;
            int newCost=currentCost+costMatrix[row][job];
            if(newCost<minCost){
                branchAndBound(costMatrix,row+1,assignment,newCost);
            }
            assignment[row]=-1;
        }
    }
}
int main(){
    printf("Enter the number of workers and jobs(maximum %d):",MAX_SIZE);
    scanf("%d",&N);
    int costMatrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the cost matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&costMatrix[i][j]);
        }
    }
    int assignment[MAX_SIZE];
    for(int i=0;i<N;i++){
        assignment[i]=-1; 
    }
    minCost=INT_MAX;
    branchAndBound(costMatrix,0,assignment,0);
    printf("Minimum Cost of Assignment: %d\n",minCost);
    return 0;
}

