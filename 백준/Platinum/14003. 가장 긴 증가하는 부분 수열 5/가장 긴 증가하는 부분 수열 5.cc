#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define NUMOFARRAY 1000000
#define INF 1000000000
using namespace std;

int number[NUMOFARRAY] = { 0 };
int dp[NUMOFARRAY] = { 0 };
vector<int> vt;
int N;
int ans = 0;
int max_index = 0;
stack<int> s;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cin >> number[0];
	vt.push_back(number[0]);
	dp[0] = 1;
	ans = 1;
	max_index = 0;
	for (int i = 1; i < N; i++) {
		cin >> number[i];
		dp[i] = 1;
		if (number[i] > vt.back()) {
			vt.push_back(number[i]);
			ans++;
			dp[i] = ans;
			max_index = i;
		}
		else {
			int idx = lower_bound(vt.begin(), vt.end(), number[i]) - vt.begin();
			vt[idx] = number[i];
			dp[i] = idx+1;
			//cout << idx << " ";
		}
	}

	cout << ans <<"\n";
	s.push(number[max_index]);
	for (int i = max_index-1; i >= 0; i--) {
		if (dp[i] + 1 == dp[max_index] && number[i] < number[max_index]) {
			s.push(number[i]);
			max_index = i;
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}


	return 0;
}