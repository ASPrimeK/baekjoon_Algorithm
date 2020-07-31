import sys
n, m, k = map(int, sys.stdin.readline().split())
ans = 0
while n >= 2 and m >= 1 and (n-2+m-1) >= k:
    n -= 2
    m -= 1
    ans += 1
print(ans)
