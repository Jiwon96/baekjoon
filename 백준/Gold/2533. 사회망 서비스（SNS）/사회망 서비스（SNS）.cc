#include<iostream>
#include<vector>
#include<string.h>
#define NUMOFNODES 1000000
using namespace std;

int N;
vector<int> v[NUMOFNODES+1];
bool visited[NUMOFNODES + 1];
int ret[NUMOFNODES + 1][2];
void DFS(int cur) {
	visited[cur] = true;
	ret[cur][0] = 1;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (visited[next]) continue;
		DFS(next);
		ret[cur][0] += min(ret[next][0], ret[next][1]);
		ret[cur][1] += ret[next][0];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(visited, false, sizeof(visited));

	cin >> N;
	for (int i = 1; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	DFS(1);
	cout << min(ret[1][0], ret[1][1]) <<"\n";

	return 0;
}