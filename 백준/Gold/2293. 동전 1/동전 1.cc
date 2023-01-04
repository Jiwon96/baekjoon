#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N, K;
int cost[100] = { 0 };
int dp[100001] = { 0 };
/*
int solution(int cur, int money) {
	if (cur <= 0 || money < 0) return 0;
	if (money == 0) {
		return dp[cur][money]+1;
	}
	if (visited[cur][money]) return dp[cur][money];

	int & ret = dp[cur][money];
	visited[cur][money] = true;

	return ret = solution(cur, money - cost[cur]) + solution(cur -1, money);
}					
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> cost[i];

	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = cost[i]; j <= K; j++)
			dp[j] += dp[j - cost[i]];
	}

	cout << dp[K] << "\n";

	return 0;
}
/*
int dfs(int cur) {
	if (cur == 0) return 1;
	if (cur < 0) return 0;

	int & ans = ret[cur];
	visited[cur] = true;
	for (int j = 0; j < arr.size(); j++) {
		int next = cur - arr[j];
		if(visited[next]==false)
			ans = arr[next] + dfs(cur - arr[j]);
	}
	return ans;
}

void solution() {
	
	dfs(K);
	cout << ret[K] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end(), less<>());
	
	solution();

	return 0;
}*/