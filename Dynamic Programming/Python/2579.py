# 계단 오르기
n = int(input())
stair = list()
for i in range(n):
    stair.append(int(input()))
if n == 1:
    stair.append(-100000)
    stair.append(-100000)
if n == 2:
    stair.append(-100000)
dp = [stair[0], stair[0] + stair[1]]
dp.append(max(stair[0]+stair[2], stair[1]+stair[2]))

for i in range(3, n):
    dp.append(max(
        dp[i - 2] + stair[i],
        dp[i - 3] + stair[i - 1] + stair[i]
    ))
print(dp[n-1])
