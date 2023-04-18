#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>

#define NODES 100000

using namespace std;

vector <pair<int, int>> board[NODES];
queue<pair<int, int>> q; // 노드 , 길이
priority_queue<int> pq; // 길이만
int V;
bool visited[NODES];
int ret = 0;
// DFS로 짜야된다. root에서 다른 갈래끼리의 거리를 구해야됨 그리고 그 중 최대값 리턴해야됨 부모한테
/*
void BFS() {
	q.push({ 1 ,0});
	visited[1] = true;
	while (!q.empty()) {
		int dist = q.front().second;
		int cur = q.front().first;
		q.pop();
		bool Node_End_Flag = true; // 끝 노드 확인
		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i].first;
			if (!visited[next]) {
				q.push({ next , dist + board[cur][i].second });
				visited[next] = true;
				Node_End_Flag = false;
			}
			if (Node_End_Flag) pq.push(dist);
		}
	}
}
*/

int DFS(int cur) {
	vector<int > dist;
	dist.push_back(0);
	bool Node_End_Flag = true; // 끝 노드 확인
	visited[cur] = true;
	for (int i = 0; i < board[cur].size(); i++) {
		int next = board[cur][i].first;
		if (!visited[next]) {
			dist.push_back( board[cur][i].second + DFS(next));
			visited[next] = true;
			Node_End_Flag = false;
		}
	}
	if (Node_End_Flag) return 0;
	else {
		sort(dist.begin(), dist.end(), greater<int>());
		ret = max(ret, dist[0]+dist[1]);
		return dist[0];
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < V; i++) {
		int n1;
		cin >> n1;
		int n2 = 0;
		int n3 = 0;
		while (1) {
			cin >> n2;
			if (n2 != -1) {
				cin >> n3;
				board[n1].push_back({ n2, n3 });
			}
			else break;
		}
	}

	//cout << "end" << "\n";
	DFS(1);
	//int ret = pq.top();
	//pq.pop();
	//ret += pq.top();
	cout << ret << "\n";

	return 0;
}