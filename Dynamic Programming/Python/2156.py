n = int(input())
wine = [0]
wine.extend([int(input()) for _ in range(n)])
wine.extend([0, 0, 0, 0])
d = [0, wine[1], wine[2] + wine[1]]
for i in range(3, n+1):
    d.append(max(
        d[i - 2] + wine[i],
        d[i - 3] + wine[i - 1] + wine[i],
        d[i - 1]))
print(d[n])
