#include<queue>
#include<iostream>
#include<algorithm>
#include<stack>
#include<climits>

using namespace std;

priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>> pq;
long long board[1001][1001] = { 0 };
int n, m;
bool visited[1001];
int _from, _to;
int root[1001] = { 0 };
long long ans[1001] = { 0 };
stack<int> s;
int cnt = 0;
void solve() {
	pq.push({0, _from});
	while (!pq.empty()) {
		int cur = pq.top().second;
		long long dist = pq.top().first;
		pq.pop();
		visited[cur] = true;
		//for (int i = 1; i <= n; i++)
			//cout << ans[i] << " ";
	//	cout << "\n";
		if (cur == _to) {
			int a = cur;
			while (a != _from)
			{
				cnt++;
				s.push(a);
				a = root[a];
			}
			cnt++;
			s.push(a);
			return;
		}

		//cout << board[4][3] << "4:3 \n";
		for(int next=1; next<=n; next++)
			if ((ans[next] > dist + abs(board[cur][next])) && (!visited[next]))
			{
				ans[next] = dist + board[cur][next];
				pq.push({dist+board[cur][next], next});
				root[next] = cur;
			}
	}
	return;
}

void solution() {
	for (int i = 1; i <= n; i++)
		ans[i] = LLONG_MAX-1;
	ans[_from] = 0;
	
	solve();
	cout << ans[_to] << "\n" << cnt << "\n";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			board[i][j] = 1000000000;

	for (int i = 0; i < m; i++)
	{
		int n1, n2;
		long long n3;
		cin >> n1 >> n2 >> n3;
		board[n1][n2] = min(board[n1][n2], n3);
		//board[n2][n1] = n3;
	}
	cin >> _from >> _to;
	solution();

	return 0;
}