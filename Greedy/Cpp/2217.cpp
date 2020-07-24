// 로프
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int *lope = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> lope[i];
    }
    sort(lope, lope + N);
    int max = -1;
    int weight;
    int count = 1;
    for (int i = N - 1; i >= 0; i--) {
        weight = lope[i] * count;
        if (max < weight) max = weight;
        count++;
    }
    cout << max;
    delete[] lope;
}