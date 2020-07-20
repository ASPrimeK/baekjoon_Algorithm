n = int(input())
a = list(map(int, input().split()))
a.sort()
summ = 0
result = 0
for i in range(n):
    summ += a[i]
    result += summ
print(result)
