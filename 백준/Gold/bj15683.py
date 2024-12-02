
def move(d, cnt, num):
    ni, nj = r[cnt], c[cnt]
    while True:
        ni, nj = ni+dr[d], nj+dc[d]
        if ni < 0 or ni >=N or nj <0 or nj>=M:
            return
        if board[ni][nj] == 6:
            return
        if 1<=board[ni][nj] <=5:
            continue
        if board[ni][nj] == 0 or board[ni][nj] == cnt + 7:
            board[ni][nj] = num

def dfs(cnt, dist):
    global ans
    if cnt == cctvs:
        ret=0
        for i in range(N):
            for j in range(M):
                if board[i][j] == 0:
                    ret+=1
        ans = min(ret, ans)
        return

    cctv_num = board[r[cnt]][c[cnt]]  # 현재 CCTV의 번호
    cctvslist = dirs[cctv_num]
    for i in range(4):
        for d in cctvslist:
            move((d + i) % 4, cnt, 7+cnt)
        dfs(cnt + 1, dist+[(d+i)%4])
        for d in cctvslist:
            move((d + i) % 4, cnt, 0)


dirs = [[], [0], [0, 2], [0,1], [0,1,2], [0,1,2,3]]
r =[]
c =[]
dr = [0, -1, 0,1]
dc = [1,0,-1,0]
N, M = map(int, input().split())
board = []
cctvs=0
for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(M):
        if 1 <= temp[j] <= 5:
            r.append(i)
            c.append(j)
            cctvs+=1
    board.append(temp)

ans = 65
dfs(0, list())
print(ans)