n = int(input())
a = list()
dp = list()
for i in range(n):
    a.append(list(map(int, input().split())))
    dp.append(list(map(lambda x: 0, a[i])))
dp[0][0] = a[0][0]
for i in range(1, n):
    for j in range(i+1):
        if j == 0:
            dp[i][j] = dp[i-1][0] + a[i][j]
        elif j == i:
            dp[i][j] = dp[i-1][j-1] + a[i][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+a[i][j]
print(max(dp[n-1]))
