#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define MOD_NUM 10000

using namespace std;

queue<int> q;
vector< char> s;
bool visited[MOD_NUM + 1] = { false };
vector<pair<short, char>>board[10001];
int N;
int num1, num2;
char ch[4]={'D','S','L','R'};
int translate(int d1, int d2, int d3, int d4, char type) {
	int cur = ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
	switch (type) {
		case 'D':
		{
			return (cur * 2) % MOD_NUM;
		}
		case 'S':
			return (cur - 1) % MOD_NUM;
		case 'L':
			return (((d2 * 10 + d3) * 10 + d4) * 10 + d1)%MOD_NUM;
		case 'R':
			return (((d4 * 10 + d1) * 10 + d2) * 10 + d3)%MOD_NUM;
	}
}

void bfs() {
	q.push(num1);
	visited[num1] = true;
	while (!q.empty()) {
		if (q.front() == num2) {
			int a = q.front();
			while (a != num1) {
				s.push_back(board[a].front().second);
				a = board[a].front().first;
			}
			return;
		}
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next = (translate(cur / 1000, (cur%1000)/100, (cur%100) / 10, cur % 10, ch[i]))%MOD_NUM;
			if (next < 0) next += 10000;
			if (!visited[next] && next>=0 &&next <MOD_NUM)
			{
				q.push({ next });
				visited[next] = true;
				board[next].push_back({ cur, ch[i] });
			}
		
		}
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		while (!q.empty()) q.pop(); 
		while (!s.empty()) s.pop_back();
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<10000; i++)
			board[i].clear();
		cin >> num1 >> num2;
		bfs();
		for (int i = s.size() - 1; i >= 0; i--)
		{
			cout << s[i];
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	solution();
	//cout << ( ( - 1) % 100) << "\n";
	return 0;
}