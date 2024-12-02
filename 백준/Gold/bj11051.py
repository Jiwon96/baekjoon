dp = [[0] * 1001 for _ in range(1001)]

def comb(n, k):

    if dp[n][k] != 0:
        return dp[n][k]
    if k == 0:
        return 1
    if k == n:
        return 1

    dp[n][k] = (comb(n - 1, k - 1) % 10007 + comb(n - 1, k) % 10007) % 10007

    return dp[n][k]

n, k = map(int, input().split())

print(comb(n,k))