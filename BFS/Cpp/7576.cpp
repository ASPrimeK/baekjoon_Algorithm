// 토마토
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool box[1000][1000];
int M, N;
int max_day = 0;
queue<pair<int, pair<int, int>>> q;

void bfs() {
    max_day = 0;
    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int day = q.front().first;
        q.pop();
        if (max_day < day) max_day = day;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!box[nx][ny]) {
                q.push(make_pair(day + 1, make_pair(nx, ny)));
                box[nx][ny] = true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N;
    int a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a;
            if (a == -1) {
                box[i][j] = true;
            } else if (a == 0) {
                box[i][j] = false;
            } else {
                box[i][j] = true;
                q.push(make_pair(0, make_pair(i, j)));
            }
        }
    }
    bfs();
    bool isUnchecked = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!box[i][j]) {
                isUnchecked = true;
                break;
            }
        }
        if (isUnchecked) break;
    }
    cout << ((isUnchecked) ? -1 : max_day) << '\n';
}
