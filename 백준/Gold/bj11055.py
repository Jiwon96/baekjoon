N = int(input())
A = list(map(int, input().split()))

sum = A[:]

for i in range(1, N):

    for j in range(i):
        if A[j] < A[i]:
            sum[i] = max(sum[i], sum[j] + A[i])
print(max(sum))