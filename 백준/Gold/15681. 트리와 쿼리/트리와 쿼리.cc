#include<iostream>
#include<vector>
#define NUMOFN 100000
using namespace std;

int N, R, Q;
vector <int> tree[NUMOFN + 1];
bool visited[NUMOFN+1] = { false, };
int cnt[NUMOFN + 1] = { 0 };
int DFS(int root) {
	visited[root] = true;
	cnt[root] = 1;

	for (int i = 0; i < tree[root].size(); i++) {
		int next = tree[root][i];
		if (visited[next]) continue;
		cnt[root] += DFS(next);
	}
	return cnt[root];
}

int main() { 
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>> N >> R >> Q;
	for (int i = 1; i < N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}
	DFS(R);
	for (int i = 0; i < Q; i++) {
		int num1;
		cin >> num1;
		cout << cnt[num1] << "\n";
	}

	return 0;
}