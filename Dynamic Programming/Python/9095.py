# 1, 2, 3 만들기
n = int(input())
dp = [-1, 1, 2, 4]
for i in range(4, 11):
    dp.append(dp[i-1]+dp[i-2]+dp[i-3])
for i in range(n):
    x = int(input())
    print(dp[x])
