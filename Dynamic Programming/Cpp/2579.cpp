// 계단 오르기
#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int a, b;
    int i, n, seq = 0;
    int *stair, *dp;
    scanf("%d", &n);
    stair = (int *)calloc(n, sizeof(int));
    dp = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", stair + i);
    }
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(
        stair[0] + stair[2],
        stair[1] + stair[2]);
    for (i = 3; i < n; i++)
    {
        dp[i] = max(
            dp[i - 2] + stair[i],
            dp[i - 3] + stair[i - 1] + stair[i]);
        // printf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("%d", dp[n - 1]);
    free(stair);
    free(dp);
    return 0;
}