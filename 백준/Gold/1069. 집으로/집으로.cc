#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long double ans;
	long double x, y, d, t;
	long double dist = 0;
	int jump = 0;
	cin >> x >> y >> d >> t;
	dist = sqrt(pow(x, 2) + pow(y, 2));
	jump = (int)dist / d;
	ans = dist;
	//cout << jump << " "<< dist<<"\n";

	if (jump > 0) ans = min(ans, jump * t + (dist - jump * d));
	ans = min(ans, (long double)(jump + 1)*t +((jump+1)*d-dist));
	if(jump>0)
	ans = min(ans, (long double)(jump + 1) * t);
	else
	ans = min(ans, (long double)t * 2.0);

	cout << fixed;
	cout.precision(9);
	cout << ans << "\n";
	return 0;
}