#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#define NODES 100000

using namespace std;

queue<int> Q;
vector<int> board[NODES+1];
int arr[NODES+1]={0};
int N;
bool visited[NODES + 1] = { 0 };
void BFS() {
	Q.push(1);
	visited[1] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < board[cur].size(); i++) {
			int next = board[cur][i];
			if (!visited[next]) {
				arr[next] = cur;
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	return;
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
		board[num1].push_back(num2);
		board[num2].push_back(num1);
	}
	BFS();

	for (int i = 2; i <= N; i++) {
		cout << arr[i] <<"\n";
	}

	return 0;
}