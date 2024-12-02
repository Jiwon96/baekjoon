N = int(input())
lst = list(map(int, input().split()))

reverse_lst = lst[::-1]

dp =[1]*len(lst)

for i in range(1, len(lst)):

    for j in range(i):
        if reverse_lst[j] < reverse_lst[i]:
            dp[i] = max(dp[i], dp[j]+1)


print(max(dp))
