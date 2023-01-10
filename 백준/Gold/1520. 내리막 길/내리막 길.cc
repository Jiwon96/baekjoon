#include<iostream>
#include<vector>
using namespace std;

int board[500][500] = { 0 };
int ret[500][500] = { 0 };
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,-1,0,1 };

int M, N; // M: 행, N: 열
int dfs(int currow, int curcol) {
	if (currow == (N-1) && curcol == (M-1)) return 1;
	if (ret[currow][curcol] != -1) return ret[currow][curcol];

	ret[currow][curcol] = 0;
	for (int i = 0; i < 4; i++) {
		int nextrow = currow + posx[i];
		int nextcol = curcol + posy[i];
		if (nextrow >= 0 && nextrow < N && nextcol >= 0 && nextcol < M) {
			if (board[currow][curcol] > board[nextrow][nextcol])
				ret[currow][curcol] = ret[currow][curcol] + dfs(nextrow, nextcol);
		}

	}
	return ret[currow][curcol];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			ret[i][j] = -1;
		}


	cout << dfs(0, 0) << "\n";

	return 0;
}