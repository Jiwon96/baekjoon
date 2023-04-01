#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool visited[100001] = { false};
int board[100001] = { 0 };
vector<int> s;
void bfs(int su, int brother) {
	queue <pair<int, int>>  q;
	q.push({ su, 0 });
	visited[su] = true;
	while (!q.empty()) {
		if (q.front().first == brother) {
			int a = q.front().first;
			cout << q.front().second << "\n";
			while (a != su) {
				s.push_back(a);
				a = board[a];
			}
			s.push_back(su);
			return;
		}
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur + 1 <= 100000 && !visited[cur + 1]) {
			board[cur + 1] = cur;
			visited[cur + 1] = true;
			q.push({ cur + 1, cnt + 1 });
		}
		if (cur * 2 <= 100000 && !visited[cur *2]) {
			board[cur *2] = cur;
			visited[cur *2] = true;
			q.push({ cur *2, cnt + 1 });
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			board[cur - 1] = cur;
			visited[cur - 1] = true;
			q.push({ cur -1 , cnt + 1 });
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int su, brother;
	cin >> su >> brother;

	bfs(su, brother);
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i] << " ";
	cout << "\n";
	return 0;
}