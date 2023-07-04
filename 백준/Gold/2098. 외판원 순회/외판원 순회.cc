#include<iostream>
#include<algorithm>
#include<climits>
#include<string.h>

#define INF 987654321

using namespace std;

int N;
int dp[16][1 << 17];
int board[16][16]={0};

int dfs(int x, int visited) {
	if (((1 << N) - 1) == visited) { 
		if(board[x][0] != 0) return board[x][0];
		else return INF;
	}
	if (dp[x][visited] != -1) return dp[x][visited];

	dp[x][visited] = INF;

	for (int i = 0; i < N; i++) {
		if (board[x][i] == 0) continue;
		if (visited & (1 << i)) continue;

		dp[x][visited] = min(dp[x][visited], board[x][i] + dfs(i, visited | (1 << i)));
	}
	return dp[x][visited];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];


	cout << dfs(0,1) << "\n";

	return 0;
}