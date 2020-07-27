# 토마토
from collections import deque
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]
M, N = map(int, input().split())
box = []
q = deque()
for i in range(N):
    b = []
    a = list(map(int, input().split()))
    for j in range(M):
        if a[j] == 1:
            b.append(True)
            q.append([0, [i, j]])
        elif a[j] == -1:
            b.append(True)
        else:
            b.append(False)
    box.append(b)
max_day = 0
while q:
    a = q.popleft()
    day = a[0]
    x = a[1][0]
    y = a[1][1]
    if max_day < day:
        max_day = day
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if not box[nx][ny]:
            box[nx][ny] = True
            q.append([day+1, [nx, ny]])
isUnchecked = False
for i in range(N):
    for j in range(M):
        if not box[i][j]:
            isUnchecked = True
            break
    if isUnchecked:
        break
if isUnchecked:
    print(-1)
else:
    print(max_day)
