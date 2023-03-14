#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll arr[30] = { 0 };
int N;
ll C;
void DFS(int s, int e, vector<ll> & group1, ll elements) {

	if (s > e) {
		group1.push_back(elements);
		return;
	}
	else {
		DFS(s + 1, e, group1, elements);
		DFS(s + 1, e, group1, elements + arr[s]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<ll> group1, group2;
	ll ans = 0;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	DFS(0, N / 2-1, group1, 0);
	DFS(N / 2, N-1, group2, 0);
	sort(group1.begin(), group1.end(), less<ll>());

	for (int i = 0; i < group2.size(); i++) {
		ans+= (upper_bound(group1.begin(), group1.end(), C - group2[i]) - group1.begin());
	}

	cout << ans<< "\n";


	return 0;
}