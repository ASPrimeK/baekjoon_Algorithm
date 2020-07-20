// RGB거리
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    int **dp = (int **)calloc(n + 1, sizeof(int *));
    int **cost = (int **)calloc(n + 1, sizeof(int *));
    for (i = 1; i < n + 1; i++)
    {
        dp[i] = (int *)calloc(3, sizeof(int));
        cost[i] = (int *)calloc(3, sizeof(int));
        scanf("%d %d %d", cost[i] + 0, cost[i] + 1, cost[i] + 2);
    }
    for (i = 0; i < 3; i++)
        dp[1][i] = cost[1][i];
    for (i = 2; i < n + 1; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    printf("%d", min(min(dp[n][0], dp[n][1]), dp[n][2]));

    for (i = 0; i < n + 1; i++)
    {
        free(cost[i]);
        free(dp[i]);
    }
    free(cost);
    free(dp);
    return 0;
}