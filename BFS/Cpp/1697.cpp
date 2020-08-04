// 숨바꼭질
#include <iostream>
#include <queue>

#define MAX 100000

using namespace std;

bool visit[MAX + 1];

int main() {
    int N, K;
    cin >> N >> K;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    while (!q.empty()) {
        int index = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (index == K) {
            cout << cost << '\n';
            return 0;
        }
        if (index < K && 2 * index <= MAX && !visit[2 * index]) {
            visit[2 * index] = true;
            q.push(make_pair(2 * index, cost + 1));
        }
        if (0 <= index - 1 && !visit[index - 1]) {
            visit[index - 1] = true;
            q.push(make_pair(index - 1, cost + 1));
        }
        if (index + 1 <= MAX && !visit[index + 1]) {
            visit[index + 1] = true;
            q.push(make_pair(index + 1, cost + 1));
        }
    }
    return -1;
}