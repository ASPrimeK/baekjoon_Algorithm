// 가장 긴 증가하는 부분 수열
#include <iostream>
using namespace std;

int main() {
    int n;
    int total = 1;
    cin >> n;
    int* a = new int[n + 1];
    int* dp = new int[n + 1];
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int d = 0;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j])
                if (d < dp[j])
                    d = dp[j];
        }
        dp[i] = d + 1;
        if (total < dp[i]) total = dp[i];
    }
    cout << total << '\n';
}