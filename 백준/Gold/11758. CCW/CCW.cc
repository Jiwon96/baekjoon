#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

vector<pair<long long, long long>> v;
int N;
long long triangle_area(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

//bool compare(pair<long double, long double> a, pair<long double, long double> b) {
//	if (a.second+a.first == b.first+ b.second) return a.first < b.first;
//	else return a.second + a.first < b.first + b.second;
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ret = 0;
	for (int i = 0; i < 3; i++)
	{
		long long x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 2; i < 3; i++) {
		ret += triangle_area(v[0], v[i - 1], v[i]);
	}
	if (ret > 0) cout << "1" << "\n";
	else if (ret == 0) cout << "0" << "\n";
	else cout << "-1\n";

	return 0;
}