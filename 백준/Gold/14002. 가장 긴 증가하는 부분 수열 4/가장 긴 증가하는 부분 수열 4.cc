#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int length[1001]={0};
int number[1001] = { 0 };
stack<int> x;
int idx = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> number[i];
	
	for (int i = 1; i <= N; i++) {
		length[i] = 1;
		for (int j = 1; j < i; j++) {
			if (number[j] < number[i]) {
				length[i] = max(length[i], length[j] + 1);
				if (length[idx]+1 == length[i]) idx = i;
			}
		}

	}

	cout << length[idx] << "\n";

	x.push(idx);
	for (int i = idx - 1; i > 0; i--) {
		if (number[i] < number[idx] && length[i]== length[idx]-1) {
			x.push(i);
			idx = i;
		}
	}

	
	while(!x.empty()) {
		cout << number[x.top()] << " ";
		x.pop();
	}
	cout << "\n";
	return 0;

}