#include<algorithm>
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#include<cmath>
using namespace std;
vector<pair<long long, long long>> Nodes;
vector<pair<long double, int>> dist[1001];
int N, M;
int parent[1001];
int edges_cnt[1001] = { 0 };
long double ret_sum = 0.0L;
bool visited[1001] = { false };
struct compare {
	bool operator()(const pair<double, pair<int, int>> a, const pair<double, pair<int, int>> b) {
		return a.first > b.first;
	}
};

priority_queue<pair<double,pair<int, int>>, vector<pair<double, pair<int, int>>>, compare> pq;



int find(int node) {
	if (parent[node] == node) return node;
	int parentx= find(parent[node]);
	parent[node] = parentx;
	return parentx;
}

void merge(int node1, int node2) {
	int parent1 = find(node1);
	int parent2 = find(node2);
	if (parent1 == parent2) return;
	if (edges_cnt[parent1] >= edges_cnt[parent2]) {
		edges_cnt[parent1] = edges_cnt[parent1] + edges_cnt[parent2] + 1;
		parent[parent2] = parent1;
	}
	else {
		edges_cnt[parent2] = edges_cnt[parent1] + edges_cnt[parent2] + 1;
		parent[parent1] = parent2;
	}

}

double get_dist(long long node1, long long node2) {
	double x_dist = (double) ((Nodes[node1].first - Nodes[node2].first)* (Nodes[node1].first - Nodes[node2].first));
	double y_dist = (double)((Nodes[node1].second - Nodes[node2].second)* (Nodes[node1].second - Nodes[node2].second));
	return sqrt(x_dist + y_dist);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(2);
	cin >> N >> M;
	Nodes.push_back({ 0,0 });

	//input
	for (int i = 1; i <= N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		Nodes.push_back({ num1, num2 });
	}
	
	// init
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	//solution

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);			//그래프 만들기
		//ret_sum += get_dist(x,y);	//간선 추가
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			for (int j = 1; j <= N; j++) {
				if (i != j) {
					pq.push({ get_dist(i, j), {i, j} });
				}
			}
		}
	}

	while(!pq.empty()){
		if (find(pq.top().second.first) != find(pq.top().second.second)) {
			merge(pq.top().second.first, parent[pq.top().second.second]);
			ret_sum += pq.top().first;
		}
		pq.pop();
	}
	
	cout << round(ret_sum*100)/100 << "\n";

	return 0;
}