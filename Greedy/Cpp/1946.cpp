// 신입사원
#include <algorithm>
#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;

bool cmp(P& a, P& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

void f() {
    int n;
    cin >> n;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), cmp);

    int cri = v[0].second;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (cri >= v[i].second) {
            cnt++;
            cri = v[i].second;
        }
    }
    cout << cnt + 1 << '\n';
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        f();
}