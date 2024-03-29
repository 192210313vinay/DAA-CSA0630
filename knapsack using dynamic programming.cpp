#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapSack(int W, int weights[], int values[], int n) {
    int i, w;
    int dp[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],  dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}
int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);
    printf("Maximum value we can obtain = %d\n", knapSack(W, weights, values, n));
    return 0;
}

