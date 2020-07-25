// 연속합
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, max;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a.push_back(b);
    }
    int sum = max = a[0];
    for (int i = 1; i < n; i++) {
        if (sum + a[i] < 0 || sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }
        if (max < sum) max = sum;
    }
    cout << max;
}