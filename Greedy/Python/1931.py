n = int(input())
a = []
for i in range(n):
    a.append(list(map(int, input().split())))
a = sorted(a, key=lambda x: [x[1], x[0]])
count = 1
e = a[0][1]
for i in range(1, n):
    if e <= a[i][0]:
        count += 1
        e = a[i][1]
print(count)
