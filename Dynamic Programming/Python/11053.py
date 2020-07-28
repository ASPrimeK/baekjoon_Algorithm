n = int(input())
arr = list(map(int, input().split()))
total = 0
dp = []
for i in range(n):
    here = 0
    for j in range(0, i):
        if arr[i] > arr[j]:
            if here < dp[j]:
                here = dp[j]
    dp.append(here+1)
    if total < dp[i]:
        total = dp[i]
print(total)
