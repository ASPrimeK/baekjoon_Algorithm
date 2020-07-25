# 유기농 배추

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]


def dfs(tile, check, x, y):
    global dx
    global dy
    stack = []
    stack.append([x, y])
    while stack:
        x, y = stack.pop()
        check[x][y] = 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx > 49 or ny < 0 or ny > 49:
                continue
            if check[nx][ny] == 0 and tile[nx][ny] == 1:
                stack.append([nx, ny])


testCase = int(input())
for _ in range(testCase):
    count = 0
    tile = list([0 for _ in range(50)] for _ in range(50))
    check = list([0 for _ in range(50)] for _ in range(50))
    M, N, n = list(map(int, input().split()))
    for _ in range(n):
        a, b = list(map(int, input().split()))
        tile[a][b] = 1
    for i in range(50):
        for j in range(50):
            if check[i][j] == 0 and tile[i][j] == 1:
                count += 1
                dfs(tile, check, i, j)
    print(count)
