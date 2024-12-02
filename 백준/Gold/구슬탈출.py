def move(d, r, c):
    cnt=0
    back =1
    for i in range(1, 10):
        cnt+=1
        nr, nc = r + dir[d][0] * i, c +dir[d][1] *i
        if arr[nr][nc] == '#':
            return cnt-back
        if arr[nr][nc] =='O':
            return cnt
        if arr[nr][nc] =='B' or arr[nr][nc] =='R':
            back+=1
def dfs(cnt, ri, rj, bi, bj):
    global ans, rset
    if cnt > 10:
        return
    if (cnt, ri, rj, bi, bj) in rset:
        return
    rset.add((cnt, ri, rj, bi, bj))
    for d in range(4):
        count = move(d, ri, rj)
        nri, nrj = ri + dir[d][0]*count, rj+dir[d][1]*count

        count = move(d, bi, bj)
        nbi, nbj = bi+dir[d][0]*count, bj+dir[d][1]*count

        if (ri, rj) == (nri, nrj) and (bi, bj) == (nbi, nbj):
            continue
        if arr[nbi][nbj] == 'O':
            continue
        if arr[nri][nrj] == 'O':
            ans = min(ans, cnt)
            return

        arr[bi][bj], arr[ri][rj] = '.', '.'
        arr[nbi][nbj], arr[nri][nrj] = 'B','R'
        dfs(cnt+1, nri, nrj, nbi, nbj)
        arr[nbi][nbj], arr[nri][nrj] = '.','.'
        arr[bi][bj], arr[ri][rj] = 'B', 'R'


dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]
ans=11
ri, rj, bi, bj = 0,0,0,0
rset = set()
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'R':
            ri, rj = i,j
        elif arr[i][j] == 'B':
            bi, bj = i,j

dfs(1, ri, rj, bi, bj)

print(-1 if ans == 11 else ans)