N = int(input())
numbers = list(map(int, input().split()))

max_number = int(input())

s, e = 1, max(numbers)

ret=0

while s<=e:
    mid = (s+e)//2

    sum =0

    for num in numbers:
        if num <= mid:
            sum+= num
        else:
            sum+=mid

    if sum <= max_number:
        ret = mid
        s = mid+1
    else:
        e = mid-1

print(ret)