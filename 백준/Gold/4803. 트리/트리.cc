#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

vector<int> V[501];
bool visited[501];

bool dfs(int Node) {
	int cnt = 0;
	bool ret = true;
	visited[Node] = true;
	for (int i = 0; i < V[Node].size(); i++)
	{   
		int next = V[Node][i];
        if (visited[next]) {
			cnt++;
            if (cnt >= 2) ret = false;
		}
        else { 
            ret = dfs(next) && ret; 
        }
	}
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	int ret;
	int numcase = 1;
	while (1) {
		
		ret = 0;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++)
			V[i].clear();
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < M; i++)
		{
			int num1, num2;
			cin >> num1 >> num2;
			V[num1].push_back(num2);
			V[num2].push_back(num1);
		}
		
		for (int i = 1; i <= N; i++)
			if (!visited[i]) {
                //cout << "node : " << i <<"\n";
				if (dfs(i)) ret++;
			}
	
		switch (ret) {
		case 0:
		{
			cout << "Case "<< numcase++ <<": No trees.\n";
			break;
		}
		case 1:
		{
			cout << "Case " << numcase++ << ": There is one tree.\n";
			break;
		}
		default:
		{
			cout << "Case " << numcase++ << ": A forest of " << ret << " trees.\n";
			break;
		}
		}
	}

	return 0;
}