# RGB거리
n = int(input())
cost = []
cost.append([3])
for i in range(1, n+1):
    cost.append(list(map(int, input().split())))
dp = [[], cost[1]]
for i in range(2, n+1):
    R = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]
    G = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]
    B = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]
    dp.append([R, G, B])

print(min(dp[n]))
