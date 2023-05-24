#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define MAX_NUM 10000

using namespace std;

int answer[MAX_NUM + 1][2] = {0};
vector<int> tree[MAX_NUM + 1];
int N;
int dist[MAX_NUM + 1] = {0,};
bool visited[MAX_NUM + 1] = {true,};

void DFS(int cur) {
	visited[cur] = true;
	answer[cur][1] = dist[cur];
	answer[cur][0] = 0;
	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (visited[next]) continue;
		DFS(next);
		answer[cur][0] += max(answer[next][1], answer[next][0]);
		answer[cur][1] += answer[next][0];
	}
}

vector<int> listoftree;
//이거 실수 메커티즘 생각하기
void back_list(int idx, int prev) {
	
	// visited[idx] = true; 여기가 아니라
	if ((answer[idx][1] > answer[idx][0]) && !visited[prev]) {
		listoftree.push_back(idx);
		visited[idx] = true; // 여기에 했어야 됨
	}

	for (int i = 0; i < tree[idx].size(); i++) {
		int next = tree[idx][i];
		if (next == prev) continue;
		back_list(next, idx);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> dist[i];

	for (int i = 1; i < N; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}
	//solve
	DFS(1);
	cout << max(answer[1][0], answer[1][1]) << "\n";

	memset(visited, false, sizeof(visited));
	back_list(1, 0);
	sort(listoftree.begin(), listoftree.end());
	//

	for (int i = 0; i < listoftree.size(); i++)
		cout << listoftree[i] << " ";
	cout << "\n";
	return 0;
}