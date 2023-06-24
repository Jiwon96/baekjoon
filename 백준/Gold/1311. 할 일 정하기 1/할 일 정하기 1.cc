#include<iostream>
#include<algorithm>
#include<climits>
#include<string.h>
using namespace std;

int board[20][20]={0};
int dp[20][1<<21];
int N;
int dfs(int x, int visited) {
	if (visited == (1 << N) - 1) return 0;
	if (dp[x][visited] != -1) return dp[x][visited];

	dp[x][visited] = INT_MAX;

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue;
		dp[x][visited] = min(dp[x][visited], board[x][i] + dfs(x + 1, visited | (1 << i)));
	}
	return dp[x][visited];

	/*
	bool flag = true; // 다 돔
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			flag = false;
			break;
		}
		
	}
	if (flag) return board[prev][cur];
	
	int& ret = ans[prev][cur];

	for (int next = 0; next < N; next++) {
		if (!visited[next]) {
			visited[next] = true;
			ret = min(ret, board[prev][cur] + dfs(cur, next));
			visited[next] = false;
		}
	}
	return ret;
	*/


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ret = INT_MAX;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}

	cout << dfs(0,0) << "\n";

	return 0;
}