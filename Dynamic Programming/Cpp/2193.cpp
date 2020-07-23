// 이친수
#include <iostream>
#define ULL unsigned long long
using namespace std;

int main() {
    int N;
    cin >> N;
    ULL* d = new ULL[N + 1];
    d[1] = 1;
    d[2] = 1;
    for (int i = 3; i <= N; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    cout << d[N];
    delete[] d;
}