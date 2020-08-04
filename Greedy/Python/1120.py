#  문자열
a, b = input().split()
la = len(a)
lb = len(b)
if la < lb:
    a, b = b, a
    la, lb = lb, la
min = 100000
for i in range(la-lb + 1):
    wrong = 0
    for j in range(i, i+lb):
        if a[j] != b[j-i]:
            wrong += 1
    if min > wrong:
        min = wrong
print(min)
