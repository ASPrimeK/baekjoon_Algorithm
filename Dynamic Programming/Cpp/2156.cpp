// 포도주 시식
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    cin >> n;
    vector<int> wine(n + 1, 0);
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> wine[i];
    d[1] = wine[1];
    d[2] = wine[1] + wine[2];
    for (int i = 3; i <= n; i++) {
        d[i] = max(
            max(d[i - 2] + wine[i], d[i - 3] + wine[i - 1] + wine[i]),
            d[i - 1]);
    }
    cout << d[n];
}