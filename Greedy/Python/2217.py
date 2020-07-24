# 로프
N = int(input())
lope = []
for i in range(N):
    lope.append(int(input()))
lope.sort(reverse=True)
maxx = -1
for i in range(N):
    weight = lope[i] * (i+1)
    if maxx < weight:
        maxx = weight
print(maxx)
