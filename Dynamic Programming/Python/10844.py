N = int(input())
mod = 1000000000
dp = [[], [0, 1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 1, 2, 2, 2, 2, 2, 2, 2, 1]]
i = 3
while i <= N:
    a = [dp[i-1][1] % mod]
    for j in range(1, 9):
        a.append((dp[i-1][j+1]+dp[i-1][j-1]) % mod)
    a.append(dp[i-1][8] % mod)
    dp.append(a)
    i += 1

print(sum(dp[N]) % mod)
