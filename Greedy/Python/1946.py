#  신입사원

def f():
    n = int(input())
    v = []
    for _ in range(n):
        v.append(list(map(int, input().split())))
    v.sort(key=lambda x: [x[0], -x[1]])
    cri = v[0][1]
    cnt = 0
    for i in range(1, n):
        if cri >= v[i][1]:
            cnt += 1
            cri = v[i][1]
    print(cnt+1)


n = int(input())
for _ in range(n):
    f()
