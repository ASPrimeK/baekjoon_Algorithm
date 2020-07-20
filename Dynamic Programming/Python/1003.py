n = int(input())

one = [0, 1]
zero = [1, 0]

for i in range(39):
    one.append(one[i]+one[i+1])
    zero.append(zero[i]+zero[i+1])
for i in range(n):
    x = int(input())
    print(zero[x], one[x])
