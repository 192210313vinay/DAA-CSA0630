#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];
    int i,L,r;
    for ( i = 0; i < n; i++)
        cost[i][i] = freq[i];
    
    for ( L = 2; L <= n; L++) {
        for (i = 0; i <= n-L+1; i++) {
            int j = i+L-1;
            cost[i][j] = INT_MAX;
            
            for ( r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r-1] : 0) + 
                        ((r < j) ? cost[r+1][j] : 0) + 
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}

int sum(int freq[], int i, int j) {
    int s = 0,k;
    for ( k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main() {
    int keys[] = {10, 20, 30, 40, 50};
    int freq[] = {34, 8, 50, 21, 16};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d", optimalSearchTree(keys, freq, n));
    return 0;
}

