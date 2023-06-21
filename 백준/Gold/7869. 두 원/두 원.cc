#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

// 길이 알아냄
long double get_inter_middle(long double r1, long double r2, pair<long double, long double> center1, pair<long double, long double> center2) {
	return sqrt(pow(center1.first - center2.first, 2) + pow(center1.second - center2.second, 2));
}

// 코사인 법칙 사용해서 역함수 이용 각을 알아냄
long double get_angle(long double r1, long double r2, long double inter_middle) {
	return 2*acos((pow(r1, 2) + pow(inter_middle, 2) - pow(r2, 2)) / (2*r1*inter_middle));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pair<long double, long double> c1;
	pair<long double, long double> c2;
	long double r1;
	long double r2;
	long double inter_middle;
	long double angle1, angle2;

	cin >> c1.first >> c1.second >> r1 >> c2.first >> c2.second >> r2;

	if (r2 < r1) {
		swap(r1, r2);
		swap(c1, c2);
	}

	inter_middle = get_inter_middle(r1, r2, c1, c2);

	angle1 = get_angle(r1, r2, inter_middle);
	angle2 = get_angle(r2, r1, inter_middle);

	long double square = 0.5*(((pow(r1, 2) * angle1) + (pow(r2, 2) * angle2)) - (pow(r1,2)*sin(angle1) + pow(r2,2)*sin(angle2)));
	
	cout << fixed;
	cout.precision(3);
	long double cc = 0;
	if (inter_middle >= r1 + r2)cout << cc << "\n";
	else if(inter_middle +r1 <= r2) cout << pow(r1,2)*M_PI << "\n";
	else cout << square << "\n";


	return 0;
}