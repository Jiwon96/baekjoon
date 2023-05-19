#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int N, M;
bool visited[11][11];
int island=0;
int board_min_max[8][4] = { 0 };
vector<pair<int, pair<int, int>>> v; //dist, 시작 섬 - 도착 섬
int movrow[4] = {0, 0, -1, 1};
int movcol[4] = { 1, -1, 0, 0 };
int board[11][11] = { 0 };		// 1, 0 만으로 이뤄진 입력 보드
int island_id[11][11] = { 0 };		//섬 id를 저장하는 변수
int parent[8] = { 0 };

int find(int x) {
	if (parent[x] == x) return x;
	int parentx = find(parent[x]);
	return parent[x] = parentx;
}

void merge(int island1, int island2) {
	int root1 = find(island1);
	int root2 = find(island2);
	if (root1 == root2) return;
	if (root1 <= root2)
		parent[root2] = root1;
	else 
	parent[root1] = root2;
}

bool isGraph(int island1, int island2) {
	int root1 = find(island1);
	int root2 = find(island2);
	if (root1 == root2) return true; else return false;
}

void DFS(int row, int col) {
	visited[row][col] = true;
	island_id[row][col] = island;
	
	board_min_max[island][0] = min(board_min_max[island][0], row); //row min
	board_min_max[island][1] = max(board_min_max[island][1], row); //row max
	board_min_max[island][2] = min(board_min_max[island][2], col); //col min
	board_min_max[island][3] = max(board_min_max[island][3], col); //col max

	for (int i = 0; i < 4; i++) {
		int nextrow = row + movrow[i];
		int nextcol = col + movcol[i];

		if (nextrow >= 1 && nextrow <= N && nextcol >= 1 && nextcol <= M && board[nextrow][nextcol]!=0) {
			if (!visited[nextrow][nextcol]) {
				
				DFS(nextrow, nextcol);
			}
		}
	}

}

void dist(int now, int row, int col) {
	for (int i = 0; i < 4; i++) {
		int nowrow = row;
		int nowcol = col;
		int dist = 0;

		while (true) {
			nowrow += movrow[i];
			nowcol += movcol[i];

			if (nowrow <1 || nowrow >N || nowcol < 1 || nowcol > M || island_id[nowrow][nowcol] == now) break;

			if (board[nowrow][nowcol]!=0) {
				v.push_back({ dist, {now, island_id[nowrow][nowcol]}});
				break;
			}
			dist++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(visited, false, sizeof(visited));
	//init
	for (int i = 1; i <= 7; i++)
		parent[i] = i;

	//input
	cin >> N >> M; // row, col num
	
	for (int row = 1; row <= N; row++) {
		for (int col = 1; col <= M; col++) {
			cin >> board[row][col];
		}
	}
	
	for(int i=1; i<=N; i++)
		for (int j = 1; j <= M; j++) {
			if (board[i][j] != 0 && !visited[i][j]) {
				island++;
				board_min_max[island][0] = N;
				board_min_max[island][2] = M;
				DFS(i, j);
			}
		}
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cout << island_id[i][j] << " ";
		cout << "\n";
	}
	*/
	
	//거리 구하기
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (board[i][j] != 0) {
				dist(island_id[i][j], i, j);
			}
		}
	
	sort(v.begin(), v.end());
	int edge_num = 0;
	int dist_sum = 0;
	
	//
	
	for (int i = 0; i < v.size(); i++) {

		if (v[i].first < 2) continue;
		if (!isGraph(v[i].second.first, v[i].second.second))
		{
			edge_num++;
			merge(v[i].second.first, v[i].second.second);
			dist_sum += v[i].first;
		}
	}

	if (edge_num + 1 == island)
		cout << dist_sum << "\n";
	else cout << -1 << "\n";
	
	return 0;
}