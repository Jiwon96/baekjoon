N, M = map(int, input().split())

video_time = list(map(int ,input().split()))

s , e = max(video_time), sum(video_time)
ret=e
while s<=e:
    mid = (s+e)//2

    sum = 0
    count=1
    for i in range(len(video_time)):
        if sum + video_time[i] > mid:
            sum = video_time[i]
            count+=1
        else :
            sum+=video_time[i]

    if count <= M:
        e = mid-1
        ret = min(mid, ret)
    else:
        s = mid+1
print(ret)