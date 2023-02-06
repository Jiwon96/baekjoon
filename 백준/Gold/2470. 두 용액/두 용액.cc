#include<iostream>
#include<algorithm>
#include<climits>
typedef long long ll;

using namespace std;

ll MIN = 2000000000;
int N;
ll num[100000] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll stt = 0;
	ll min_s = 0;
	ll _end = 0;
	ll min_e = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	_end = N - 1;
	min_e = N - 1;

	sort(num, num + N, less<ll>());
	
	
	while (stt < _end) {
		
		if (MIN > llabs(num[stt]+num[_end]))
		{
			min_s = stt;
			min_e = _end;
			MIN = llabs(num[stt]+num[_end]);
			if (llabs(num[stt]) > llabs(num[_end])) {
				stt++;
			}
			else {
				_end--;
			}
		}
		else {
			if (llabs(num[stt]) > llabs(num[_end])) {
				stt++;
			}
			else {
				_end--;
			}
        }
	}
	cout << num[min_s] << " " << num[min_e] << "\n";
	
	return 0;
}