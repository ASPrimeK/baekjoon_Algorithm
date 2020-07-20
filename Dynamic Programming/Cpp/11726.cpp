// 2xN 타일링

// d[n] = d[n-1] + d[n-2]
// d[1] = 1
// d[2] = 2
#include <stdio.h>

int main()
{
    int i, n;
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    scanf("%d", &n);
    for (i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    printf("%d", dp[n]);
}