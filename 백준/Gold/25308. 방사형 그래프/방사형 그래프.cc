#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

pair<long double, long double> board[8] = { 
	{0,1}, {1 / sqrt(2) ,1 / sqrt(2)}, {1, 0}, {1 / sqrt(2), -1 / sqrt(2)},
	{0,-1}, {-1 / sqrt(2), -1 / sqrt(2)}, {-1, 0}, {-1 / sqrt(2), 1 / sqrt(2)}
};


bool visited[8]={false};

int ret = 0;
int arr[8];


bool ccw(pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> p3) {		//외적
	return ((p1.first - p2.first)*(p3.second-p2.second) - (p1.second - p2.second)*(p3.first-p2.first))>0 ? true : false;
}

pair<long double, long double> next_board(int cur, int idx) { //다음 좌표 구하는 함수
	return { board[idx].first * arr[cur], board[idx].second * arr[cur] };
}

void dfs(int cur, int idx, vector < pair<long double, long double>>v) { //cur: 크기를 나타내는 배열의 인덱스
																		//idx : 몇 번째 45도 이루는지에 대한 인덱스
	if ((v.size() == 8) && ccw(v[6], v[7], v[0]) && ccw(v[7], v[0], v[1])) {												//끝을 나타냄
		ret++;
		return;
	}

	for (int next = 0; next < 8; next++) {								//탐색
		int now_len = v.size();															
		if ((!visited[next] && v.size() < 2) || cur < 0)				// 벡터가 2개 이하면 알 수 없으므로 || 초기값이 -1이면
		{
			visited[next] = true;
			v.push_back(next_board(next, idx+1));						//다음 좌표를 구함
			
			dfs(next, idx + 1, v);										//다음 탐색
			v.pop_back();												//다시 뺌
			
			visited[next] = false;						
			continue;
		}
		
		if (!visited[next] && ccw(v[now_len - 2], v[now_len - 1], next_board(next, idx + 1)))		//3개 이상일 때 다음 벡터가 외적이 0보다 크면 넣을 것
		{
			visited[next] = true;																	
			v.push_back(next_board(next, idx+1));													//다음 것 넣고 탐색 할 것
			dfs(next, idx + 1, v);
			v.pop_back();
			visited[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	vector<pair<long double, long double>> v;

	dfs(-1, -1, v);
	
	cout << ret << "\n";

	return 0;
}