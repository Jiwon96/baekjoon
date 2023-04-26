#include<iostream>
#define NUMOFNODE 100001
using namespace std;
// https://donggoolosori.github.io/2020/10/15/boj-2263/
//느낀점: post은 탐색은 root를 가장 마지막에 한다. 따라서 이 문제는 이 부분을 이용할 수 있는지를 물어보는 것
// 출제자는 문제를 내려는 포인트가 있다. 이 부분을 항상 생각해야 한다. 문제의 핵심점이 무엇인지.(출제 문제는 speciality가 있음)
// find the speciality and use it
typedef struct node {
	int root;
	int left;
	int right;
}NODE;

NODE tree[NUMOFNODE];
int N;

int inorder[NUMOFNODE];
int postorder[NUMOFNODE];
int index[NUMOFNODE];
void sorttree(int instart, int inend, int poststart, int postend) {
	if ((instart > inend) || (poststart > postend)) return;

	int rootindex = index[postorder[postend]];
	int leftsize = rootindex - instart;
	int rightsize = inend - rootindex;
	cout << inorder[rootindex] << " ";

	sorttree(instart, rootindex - 1, poststart, poststart+leftsize-1); // 왼쪽
	sorttree(rootindex + 1, inend, postend-rightsize, postend - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int j = 0; j < 2; j++) {
		for (int i = 1; i <= N; i++) {
			if (j == 0) {
				cin >> inorder[i];
				index[inorder[i]] = i; // 역함수
			}
			else
				cin >> postorder[i];
		}
	}
	sorttree(1, N, 1, N);


	return 0;
}