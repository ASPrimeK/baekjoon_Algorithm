import sys
sys.setrecursionlimit(10000)


def dfs(u):
    check[u] = True
    for v in arr[u]:
        if not check[v]:
            dfs(v)


N, M = map(int, sys.stdin.readline().split())
arr = [[] for _ in range(N+1)]
check = [False] * (N+1)
count = 0
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    arr[a].append(b)
    arr[b].append(a)
for i in range(1, N+1):
    if not check[i]:
        dfs(i)
        count += 1
print(count)
