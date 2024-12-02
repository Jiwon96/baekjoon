
def move(i, j, dr):
    back = -1
    for cnt in range(1, 10):
        ni, nj = i+di[dr]*cnt, j+dj[dr]*cnt
        if arr[ni][nj] =='#':
            return cnt+back
        if arr[ni][nj] =='O': return cnt
        #다른 공을 지나가다가 벽을 만났다면 한칸 뒤로
        if arr[ni][nj] =='B' or arr[ni][nj]=='R':
            back-=1

def dfs(n, ri, rj, bi, bj):
    global ans
    if n > 10: return
    if ans <= n: return
    if(n,ri,rj,bi,bj) in v_set:
        return

    v_set.add((n,ri,rj,bi,bj))

    for dr in range(4):

        # [1] 각 공의 이동거리 계산
        r_cnt = move(ri, rj, dr)
        b_cnt = move(bi, bj, dr)

        if r_cnt ==0 and b_cnt==0:
            continue

        # [2] 각공의 이동 반영

        nri, nrj = ri+di[dr] * r_cnt, rj+dj[dr]*r_cnt
        nbi, nbj=bi+di[dr]*b_cnt, bj+dj[dr]*b_cnt

        #[3] 처리, 이동한 위치가 홀인 경우(성공 /실패)

        if arr[nbi][nbj] == 'O':
            continue
        else:
            if arr[nri][nrj]=='O':
                ans=min(ans, n)
                return

        # [4] 둘다 홀이 아닌 경우 (next 좌표 기준으로 다음 시도)
        arr[ri][rj], arr[bi][bj] = '.', '.'
        arr[nri][nrj], arr[nbi][nbj] ='R', 'B'
        dfs(n+1, nri, nrj, nbi, nbj)
        arr[nri][nrj], arr[nbi][nbj] = '.', '.'
        arr[ri][rj], arr[bi][bj] = 'R', 'B'


di = [-1, 1, 0, 0]
dj = [0, 0, -1, 1]
N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'R':
            ri, rj = i, j
        elif arr[i][j] == 'B':
            bi,bj = i,j


v_set = set() # 해당 시도 회수때 R,B시도 회수가 똑같다면
ans = 11
dfs(1, ri, rj, bi, bj)
if ans==11:
    ans = -1
print(ans)