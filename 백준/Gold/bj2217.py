N = int(input())
numbers = [int(input()) for _ in range(N)]
numbers.sort(reverse=True)

ret = numbers[0]
for idx, num in enumerate(numbers):
    if num * (idx+1) > ret:
        ret = num * (idx+1)

print(ret)