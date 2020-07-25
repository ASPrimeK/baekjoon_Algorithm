// 유기농 배추
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int tile[50][50];
int check[50][50];
int count;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void dfs(int a, int b) {
    stack<pair<int, int>> s;
    s.push(make_pair(a, b));
    while (!s.empty()) {
        int x, y;
        pair<int, int> p = s.top();
        s.pop();
        x = p.first;
        y = p.second;
        check[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx > 49 || ny < 0 || ny > 49) continue;
            if (check[nx][ny] == 0 && tile[nx][ny] == 1)
                s.push(make_pair(nx, ny));
        }
    }
}

int main() {
    int testCase, x, y, n;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        count = 0;
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                tile[j][k] = 0;
                check[j][k] = 0;
            }
        }
        cin >> x >> y >> n;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            tile[a][b] = 1;
        }
        for (int j = 0; j < 50; j++) {
            for (int k = 0; k < 50; k++) {
                if (check[j][k] == 0 && tile[j][k] == 1) {
                    count++;
                    dfs(j, k);
                }
            }
        }
        cout << count << '\n';
    }
}