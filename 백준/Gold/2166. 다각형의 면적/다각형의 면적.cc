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
	cin >> N;
	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		long long x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	//sort(v.begin(), v.end());

	//for (int i = 0; i < N; i++)
//		cout << v[i].first << " " << v[i].second << "\n";

	for (int i = 2; i < N; i++) {
		ret += triangle_area(v[0], v[i - 1], v[i]);
	}
	ret = abs(ret);

	printf("%lld.%lld", ret >> 1, (ret & 1) * 5);

	return 0;
}