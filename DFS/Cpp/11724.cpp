#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
bool check[1001];
void dfs(int s) {
    for (int i = 0; i < v[s].size(); i++) {
        int a = v[s][i];
        if (!check[a]) {
            check[a] = true;
            dfs(a);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            count++;
            check[i] = true;
            dfs(i);
        }
    }
    cout << count << '\n';
}