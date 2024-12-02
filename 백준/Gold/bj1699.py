import math
import sys

input = sys.stdin.readline
dp = [987654321]*100001
dp[0] =0
dp[1] = 1
for i in range(2,100001):
    num = i
    rootnum = int(math.floor(math.sqrt(num)))
    if num == math.pow(rootnum,2):
        dp[i] = 1
    else:
        for j in range(1, rootnum+1):
            dp[i] = min(dp[i], dp[j*j] + dp[i - j*j])

N = int(input())

print(dp[N])