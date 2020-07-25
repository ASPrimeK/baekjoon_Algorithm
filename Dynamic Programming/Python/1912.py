# 연속합
n = int(input())
a = list(map(int, input().split()))
sum = max = a[0]
for i in a[1:]:
    if sum+i < 0 or sum < 0:
        sum = i
    else:
        sum += i
    if max < sum:
        max = sum
print(max)
