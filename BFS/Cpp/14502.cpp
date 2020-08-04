// 연구소
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int M;
int map[8][8];
int map_temp[8][8];
bool check[8][8];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
vector<pair<int, int>> v;
int main() {
    cin >> N >> M;
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int s;
            cin >> s;
            map[i][j] = s;
            if (s == 0) {
                count++;
                v.push_back(make_pair(i, j));
            }
        }
    count -= 3;
    int ans = 0;
    for (int i = 0; i < v.size() - 2; i++) {
        for (int j = i + 1; j < v.size() - 1; j++) {
            for (int k = j + 1; k < v.size(); k++) {
                //-------------------------------------------------
                int safe = count;
                for (int ii = 0; ii < N; ii++) {
                    for (int jj = 0; jj < M; jj++) {
                        check[ii][jj] = false;
                        map_temp[ii][jj] = map[ii][jj];
                    }
                }
                int a = v[i].first;
                int b = v[i].second;
                map_temp[a][b] = 1;
                a = v[j].first;
                b = v[j].second;
                map_temp[a][b] = 1;
                a = v[k].first;
                b = v[k].second;
                map_temp[a][b] = 1;
                queue<pair<int, int>> q;
                for (int ii = 0; ii < N; ii++)
                    for (int jj = 0; jj < M; jj++) {
                        if (!check[ii][jj] && map_temp[ii][jj] == 2) {
                            q.push(make_pair(ii, jj));
                            check[ii][jj] = true;
                            safe++;
                            while (!q.empty()) {
                                int xx = q.front().first;
                                int yy = q.front().second;
                                q.pop();
                                safe--;
                                for (int kk = 0; kk < 4; kk++) {
                                    int nx = xx + dx[kk];
                                    int ny = yy + dy[kk];
                                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                                    if (!check[nx][ny] && map_temp[nx][ny] == 0) {
                                        check[nx][ny] = true;
                                        q.push(make_pair(nx, ny));
                                    }
                                }
                            }
                        }
                    }
                if (ans < safe) ans = safe;
            }
        }
    }
    cout << ans << '\n';
}