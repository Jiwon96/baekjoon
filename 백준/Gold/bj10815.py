N = int(input())
numbers = list(map(int, input().split()))

M = int(input())
candidate = list(map(int, input().split()))

numbers.sort()
numbers
ret = []

for num in candidate:

    s = 0
    e = len(numbers) - 1

    while s<=e:
        mid = (s+e)//2
        if num == numbers[mid]:
            ret.append(1)
            break
        elif num < numbers[mid]:
            e = mid-1
        else:
            s = mid+1
    else:
        ret.append(0)
print(*ret)