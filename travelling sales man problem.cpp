#include <stdio.h>
#include <limits.h>

#define N 4
#define INF INT_MAX
#define VISITED_ALL (1<<N) - 1

int tsp(int distance[N][N], int mask, int pos, int dp[N][VISITED_ALL]) {
    if(mask == VISITED_ALL) {
        return distance[pos][0];
    }
    if(dp[pos][mask] != -1) {
       return dp[pos][mask];
    }

    int ans = INF;

    // Try to go to an unvisited city
    for(int city=0; city<N; city++) {
        if((mask&(1<<city)) == 0) {
            int newAns = distance[pos][city] + tsp(distance, mask|(1<<city), city, dp);
            ans = ans < newAns ? ans : newAns;
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    int distance[N][N] = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    int dp[N][VISITED_ALL];
    for(int i=0; i<N; i++)
        for(int j=0; j<VISITED_ALL; j++)
            dp[i][j] = -1;

    printf("The minimum travelling cost is %d\n", tsp(distance, 1, 0, dp));
    return 0;
}

