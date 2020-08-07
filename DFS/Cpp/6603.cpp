// 로또
#include <iostream>
#include <stack>

using namespace std;

int lo[13];
int comb[6];
void dfs(int start, int depth, int n) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++)
            cout << comb[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        comb[depth] = lo[i];
        dfs(i + 1, depth + 1, n);
    }
}

void foo(int n) {
    for (int i = 0; i < n; i++) {
        cin >> lo[i];
    }
    dfs(0, 0, n);
}

int main() {
    int input;
    cin >> input;
    while (input != 0) {
        foo(input);
        cin >> input;
        cout << '\n';
    }
}