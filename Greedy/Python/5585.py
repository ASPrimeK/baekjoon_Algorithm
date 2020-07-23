# 거스름돈
n = int(input())
n = 1000-n
a = [500, 100, 50, 10, 5, 1]
count = 0
for i in a:
    count += n//i
    n %= i
print(count)
