#include<iostream>
#include<algorithm>

using namespace std;

pair<long double, long double> l[4];

long double ccw(pair<long double, long double>l1, pair<long double, long double> l2, pair<long double, long double> l3) {
	return (l2.first * l3.second + l1.first * l2.second + l3.first * l1.second) - (l1.first * l3.second + l2.first * l1.second + l3.first * l2.second);
}

void solution() {
	long double ret1 = ccw(l[0],l[1],l[2]);//ABC 
	long double ret2 = ccw(l[0],l[1],l[3]);//ABD
	long double ret3 = ccw(l[2], l[3], l[0]); // CDA
	long double ret4 = ccw(l[2], l[3], l[1]); //CDB

	cout.precision(16);
	long double alt = (l[1].first - l[0].first) * (l[3].second - l[2].second) - (l[3].first - l[2].first) * (l[1].second - l[0].second);
	long double dx = (-l[3].first + l[2].first) * (l[0].first * l[1].second - l[1].first * l[0].second) - (l[0].first - l[1].first) * (l[2].first * l[3].second - l[3].first * l[2].second);
	long double dy = (l[2].second - l[3].second)*(-l[1].first * l[0].second + l[0].first * l[1].second)   - (l[0].second - l[1].second) * (l[2].first * l[3].second - l[3].first * l[2].second);
	if ((ret1 * ret2) <= 0 && (ret3 * ret4) <= 0) {
		if ((ret1 * ret2 == 0) || (ret3 * ret4 == 0))
		{
			if (l[0] > l[1])
				swap(l[0], l[1]);
			if (l[2] > l[3])
				swap(l[2], l[3]);
			if (l[0] <= l[3] && l[2] <= l[1])
			{
				cout << "1\n";
				if (alt != 0)
				{
					cout <<  dx/ alt << " " << dy / alt;
					return ;
				}
				if (l[1] == l[2]) {
					cout << l[2].first << " " << l[2].second << "\n";
					return;
				}
				if (l[0] == l[3]) {
					cout << l[3].first << " " << l[3].second << "\n";
					return;
				}
				
			}
			else {
				cout << "0\n";
				return;
			}
			
				
		}
		if ((ret1 * ret2 < 0) || (ret3 * ret4 < 0)) {
			
			cout << "1\n";
			cout << dx / alt << " " << dy / alt;
			return;
		}
	}
	else cout << "0\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++) {
		long double x, y;
		cin >> x >> y;
		l[i] = { x, y };
	}

	solution();

	return 0;
}