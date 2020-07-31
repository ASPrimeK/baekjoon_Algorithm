// 대회 or 인턴
#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    while (n >= 2 && m >= 1 && (n - 2 + m - 1) >= k) {
        n -= 2;
        m--;
        ans++;
    }
    cout << ans << '\n';
}