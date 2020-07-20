// 정수 삼각형
#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[i + 1];
        dp[i] = new int[i + 1];
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == i)
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            else if (j == 0)
                dp[i][j] = a[i][j] + dp[i - 1][0];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
            }
        }
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < dp[n - 1][i])
            max = dp[n - 1][i];
    }
    cout << max;
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
        delete[] dp[i];
    }
    delete[] a;
    delete[] dp;
    return 0;
}