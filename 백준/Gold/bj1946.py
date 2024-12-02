import sys

input = sys.stdin.readline
T = int(input())

ret=[]
for i in range(T):
    N = int(input())

    L = [0 for _ in range(N+1)]

    for i in range(N):
        a, b = map(int, input().split())
        L[a] = b

    last = L[1]
    ans=1
    for second in L[1:]:
        if last > second:
            ans+=1
            last = second

    print(ans)


