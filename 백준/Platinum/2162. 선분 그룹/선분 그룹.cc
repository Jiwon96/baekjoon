#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int parent[3001];
int cross[3001];
int N;
int group = 0;
bool visited[3001] = { false };
vector<int> v[3001];
pair<pair<long long, long long>, pair<long long, long long>> board[3001];
int ccw(pair<long long, long long> x1, pair<long long, long long> x2, pair<long long, long long> x3) {
	long long a = x1.first * x2.second + x2.first * x3.second + x3.first * x1.second;
	a -= (x1.first * x3.second + x2.first * x1.second + x3.first * x2.second);
	if (a > 0) return 1;
	else if (a == 0) return 0;
	else return -1;
}

int find(int r) {
	if (r == parent[r]) return r;
	else {
		int root = find(parent[r]);
		parent[r] = root;
		return root;
	}
}

void dfs(int start) {
	if (parent[start] == start) {
		v[start].push_back(start);
		return;
	}
	visited[start] = true;
	int root = -1;
	if (!visited[parent[start]])
	{
		int root = find(start);
		v[root].push_back(start);
		dfs(root);
	}
}


void merge(int r1, int r2) { // node를 받아서 합침
	int root1 = find(r1);
	int root2 = find(r2);
	if (root1 == root2) return;
	else {
		if (cross[root1] >= cross[root2]) {
			cross[root1] += cross[root2];
			parent[root2] = root1;
		}
		else {
			cross[root2] += cross[root1];
			parent[root1] = root2;
		}
	}
}

void solution() {
	// init
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		cross[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (
				ccw(board[i].first, board[i].second, board[j].first) * ccw(board[i].first, board[i].second, board[j].second) <= 0 &&
				ccw(board[j].first, board[j].second, board[i].first) * ccw(board[j].first, board[j].second, board[i].second) <= 0) {

				//merge(i, j);

				if (ccw(board[i].first, board[i].second, board[j].first) * ccw(board[i].first, board[i].second, board[j].second) < 0 &&
					ccw(board[j].first, board[j].second, board[i].first) * ccw(board[j].first, board[j].second, board[i].second) < 0) {
					merge(i, j);
					//cout << i << " " << j << "?!?!?!? \n";
				}
				if (ccw(board[i].first, board[i].second, board[j].first) * ccw(board[i].first, board[i].second, board[j].second) == 0 ||
					ccw(board[j].first, board[j].second, board[i].first) * ccw(board[j].first, board[j].second, board[i].second) == 0) {
					if (board[i].first > board[i].second) swap(board[i].first, board[i].second);
					if (board[j].first > board[j].second) swap(board[j].first, board[j].second);
					if ((board[i].first <= board[j].second) && (board[j].first <= board[i].second)) {
						merge(i, j);
					}
					//if ((board[i].first.first >= board[j].first.first) && (board[i].second.first <= board[j].second.first)) {

						//merge(i, j);
						
					//}

				}

			}

		}
	}
	for (int i = 1; i <= N; i++) 
		if(!visited[i]) dfs(i);

	for (int i = 1; i <= N; i++)
		if (v[i].size() != 0) group++;
	cout << group << "\n";
	int max_num = 0;
	for (int i = 1; i <= N; i++)
	{
		max_num = max(max_num, cross[i]);
	}
	cout << max_num << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		board[i] = { {x1, y1},{x2,y2} };
	}

	solution();

	return 0;
}