#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#define NUMOFNODES 1000000
using namespace std;

int ret[NUMOFNODES + 1] = { 0 };
int parent[NUMOFNODES + 1] = { 0 };
int n, m;

int find(int x) {
	if (parent[x] == x) return x;
	else {
		return parent[x] = find(parent[x]);
	}
}

bool merge(int x, int y) {
	int parent_x = find(x);
	int parent_y = find(y);
	if (parent_x == parent_y) return true;
	parent[parent_y] = parent_x;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("C:/Users/Jiwon/Desktop/Testcase/case2.in", "r", stdin);
	cin >> n >> m;
	
	/*init*/
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	/*end init*/

	/* algorithm */

	for (int i = 1; i <= m; i++) {
		int num1, num2; // input
		cin >> num1 >> num2;
		int parentx = find(num1);
		int parenty = find(num2);
		
		if(merge(parentx, parenty))
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "0" << "\n";
	
	return 0;
}