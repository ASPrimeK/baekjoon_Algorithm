#  로또


def foo(k, lo):
    comb = [-1 for _ in range(6)]

    def dfs(start, depth):
        if depth == 6:
            for a in comb:
                print(a, end=' ')
            print()
            return
        for i in range(start, k):
            comb[depth] = lo[i]
            dfs(i+1, depth+1)

    dfs(0, 0)


n = list(map(int, input().split()))
while n[0] != 0:
    foo(n[0], n[1:])
    print()
    n = list(map(int, input().split()))
