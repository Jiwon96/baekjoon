#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int board[1001][1001]={0};
int N, M;
int parent[1001]={0};
int parent_num;
int ret[1001]={0};
bool flag = true;

int find(int x) {
	if (parent[x] == x) return x;
	else {
		int parent_x = find(parent[x]);
		parent[x] = parent_x;
		return parent_x;
	}
}

void merge(int x, int y) // y를 x의 child로 만들기
{

	int parent_x = find(x);
	int parent_y = find(y);
	if (parent_x == parent_y) return;
	parent[parent_y] = parent_x;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
}


void solution() {
	

	Input();
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (board[i][j] == 1) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		ret[i] = find(num);
	}

	for (int i = 1; i < M; i++)
	{
		flag = flag && (ret[i] == ret[i - 1]);
	}
	if (flag) cout << "YES" << "\n";
	else cout << "NO" << "\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}