#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int board[1001][1001] = { 0 };
string s1, s2;
void print(int i, int j) {
	if (board[i][j] == 0) return;
	if (s1[i] == s2[j]) {
		print(i - 1, j - 1);
		cout << s1[i];
	}
	else {
		(board[i - 1][j] > board[i][j - 1]) ? print(i - 1, j) : print(i, j - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> s1 >> s2;
	s1 = "." + s1;
	s2 = "," + s2;

	for (int i = 1; i < s1.size(); i++) {//행
		for (int j = 1; j < s2.size(); j++) {//열
			if (s1[i]==s2[j]) {
				board[i][j] = board[i-1][j-1] + 1;
			}
			else {
				board[i][j] = max(board[i][j - 1], board[i - 1][j]);
			}
		}
	}
	cout << board[s1.size()-1][s2.size()-1];
	cout << "\n";
	print(s1.size() - 1, s2.size() - 1);
	
	
	return 0;
}