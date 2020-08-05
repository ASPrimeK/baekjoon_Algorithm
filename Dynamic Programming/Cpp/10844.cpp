// 쉬운 계단 수
#include <iostream>
#include <vector>
#define den 1000000000
using namespace std;

int main() {
    int input;
    cin >> input;
    int dp[101][10];

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;
    dp[2][0] = dp[2][9] = dp[2][1] = 1;
    for (int i = 2; i < 9; i++)
        dp[2][i] = 2;

    int i = 3;
    while (i <= input) {
        dp[i][0] = dp[i - 1][1] % den;
        dp[i][9] = dp[i - 1][8] % den;
        for (int j = 1; j < 9; j++)
            dp[i][j] = dp[i - 1][j - 1] % den + dp[i - 1][j + 1] % den;
        i++;
    }
    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[input][i];

    cout << ans % den << '\n';
}