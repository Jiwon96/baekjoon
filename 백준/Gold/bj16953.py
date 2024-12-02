A, B = map(int, input().split())

count = 0

while B > A:
    if B % 2 == 0:
        B //=2
    elif B % 10 == 1:
        B //= 10
    else:
        print(-1)
        break
    count+=1
else:
    if A==B:
        print(count+1)
    else:
        print(-1)