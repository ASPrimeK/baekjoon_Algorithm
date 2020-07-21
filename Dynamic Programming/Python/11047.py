n, k = list(map(int, input().split()))
a = []
for i in range(n):
    a.append(int(input()))
result = 0
for i in a[::-1]:
    result += k//i
    k = k % i
print(result)
