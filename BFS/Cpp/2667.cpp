// 단지번호 붙이기
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
vector<int> v;
queue<pair<int, int>> q;
int number;
bool check[25][25];
bool tile[25][25];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

void bfs(int x, int y, int N) {
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        x = p.first;
        y = p.second;
        if (check[x][y] == true)
            continue;

        check[x][y] = true;

        number++;
        for (int i = 0; i < 4; i++) {
            int a = dx[i];
            int b = dy[i];
            if (x + a < 0 || y + b < 0) continue;
            if (x + a >= N || y + b >= N) continue;
            if (check[x + a][y + b] == false && tile[x + a][y + b] == 1)
                q.push(make_pair(x + a, y + b));
        }
    }
}

int main() {
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            tile[i][j] = str[j] - '0';
        }
    }

    int c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tile[i][j] == 1 && check[i][j] == false) {
                c++;
                number = 0;
                bfs(i, j, N);
                v.push_back(number);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << c << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}