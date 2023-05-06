#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#include<map>
#define NUMOFNODES 200000

using namespace std;
int Case, N;
int parent[NUMOFNODES + 1];
vector<string> v;
bool visited[NUMOFNODES + 1];
int childs[NUMOFNODES + 1];

int find(int x) {
	if (parent[x] == x) return x;
	else {
		int parent_x = find(parent[x]);
		parent[x] = parent_x;
		return parent_x;
	}
}

void merge(int x, int y) {
	int parent_x = find(x);
	int parent_y = find(y);
	if (parent_x == parent_y) return;
	parent[parent_y] = parent_x;
}
/*
int cound_size(int x) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(find(x));
	visited[q.front()] = true;
	int count_size = 1;
	
	while (!q.empty()) {
		int parent_x = q.front();
		q.pop();
		visited[parent_x] = true;
		for (int i = 0; i < v.size(); i++) {
			if (parent[i] == parent_x && (!visited[i])) {
				q.push(i);
				count_size++;
			}
		}
	}
	return count_size;
}

int find_str_index(string s) {	//string이 있는지 아닌지 확인
	for (int i = 0; i < v.size(); i++) {
		if (s == v[i]) return i;
	}
	v.push_back(s);
	return (v.size() - 1);
	
}
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> Case;
	
	for (int i = 0; i < Case; i++) {
		cin >> N;
		v.clear();
		map<string, int> friends;
		map<string, int> ::iterator it;
		int cnt = 0;
		for (int j = 0; j < NUMOFNODES; j++) { //init 
			parent[j] = j;
			childs[j] = 1;
		}

		for (int j = 0; j < N; j++) {	
			string s1, s2;
			cin >> s1 >> s2;

			it = friends.find(s1);
			if (it != friends.end()) {
				it->second;
			}
			else {
				friends[s1] = cnt++;
			}
			it = friends.find(s2);
			if (it != friends.end()) {
				it->second;
			}
			else {
				friends[s2] = cnt++;
			}

			int root_s1 = find(friends.find(s1)->second);
			int root_s2 = find(friends.find(s2)->second);
			if (root_s1 != root_s2) {
				childs[root_s1] += childs[root_s2];
				merge(root_s1, root_s2);
				cout << childs[root_s1] << "\n";
			}
			else  {
				cout << max(childs[root_s1], childs[root_s2]) << "\n";
			}
		}
	}

	return 0;
}