#  숨바꼭질
import collections

N, K = map(int, input().split())
visit = list(False for _ in range(100001))
q = collections.deque()
q.append([N, 0])
visit[N] = True
while q:
    index, cost = q.popleft()
    if index == K:
        print(cost)
        exit()
    if index < K and index*2 < 100001 and not visit[2*index]:
        visit[2*index] = True
        q.append([2*index, cost+1])
    if index+1 < 100001 and not visit[index+1]:
        visit[index+1] = True
        q.append([index+1, cost+1])
    if 0 <= index-1 and not visit[index-1]:
        visit[index-1] = True
        q.append([index-1, cost+1])
