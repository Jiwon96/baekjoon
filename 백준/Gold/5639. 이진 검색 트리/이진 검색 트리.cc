#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int t;
int v1[10001]; // 전위 순회용
int v2[10001];//중위 순회용
int arrsize = 0;


void getorder(int infirst, int inend, int prefirst, int preend) {
	if (infirst > inend || prefirst > preend) {
		return;
	}
	int rootindex = lower_bound(v2+1, (v2+arrsize+1), v1[prefirst]) - v2;
	int left_size = rootindex - infirst;
	int right_size = inend - rootindex;

	getorder(infirst, rootindex-1, prefirst+1, prefirst + left_size);
	getorder(rootindex+1, inend, prefirst+left_size+1, preend);
	cout << v2[rootindex] << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	while (cin >> t) { v1[++arrsize] = t; }
	//cout << arrsize << "\n";
	for (int i = 1; i <= arrsize; i++)
	{
		v2[i] = v1[i];
	}

	sort(v2+1, v2+(arrsize+1));

	//for (int i = 1; i <= arrsize; i++)
	//	cout << v2[i] <<" ";

	getorder(1, arrsize, 1, arrsize);

	return 0;
}