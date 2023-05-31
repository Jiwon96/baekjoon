#include<iostream>
#include<algorithm>
#include<vector>

#define NUMOFNODES 10000

using namespace std;

vector<int> v[NUMOFNODES + 1];
int N;
bool visited[NUMOFNODES + 1]={false};
int ret[NUMOFNODES+1][2]={0};
int people[NUMOFNODES+1] = { 0 };
void DFS(int cur) {
	visited[cur] = true;
	ret[cur][1] = people[cur]; //사람
	ret[cur][0] = 0;		//사람 없음

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (visited[next]) continue;
		DFS(next);
		ret[cur][1] += ret[next][0];
		ret[cur][0] += max(ret[next][0], ret[next][1]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> people[i];

	for (int i = 1; i < N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	DFS(1);
	cout << max(ret[1][0], ret[1][1]) << "\n";

	return 0;
}
