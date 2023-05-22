#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define PII pair<int, int>
#define N 1005
#define INF 214000000
using namespace std;
priority_queue<PII, vector<PII>, greater<PII>> dist;
bool visited[N];
vector<PII> ad[N];
void add_edge(int node) {
	for (auto edge : ad[node])	//ad[node]의 시작주소부터 끝주소 까지 값을 edge에 복사하겠음
		dist.push(edge);
}

long long prim(int pn) {
	long long ret = 0;
	long long min_dist = INF;
	
	dist.push(PII(0, 1));
    int edges = 0;
	while (!dist.empty()) {
		int now = dist.top().second;
        int cur_dist = dist.top().first;
		dist.pop();
		if (visited[now]) continue;
		ret += cur_dist;
		visited[now] = true;
		add_edge(now);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(visited, false, sizeof(visited));
	int n, m;
	cin >> n >> m;
	while (m--) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		ad[v1].push_back({ PII(c, v2) });
        ad[v2].push_back({ PII(c, v1) });
	}
	cout << prim(n) << "\n";
	return 0;
}
