#include<iostream>
#include<algorithm>
#define NUMOFARRAY 100000
using namespace std;

int N;
int h[NUMOFARRAY] = { 0 };

int main() {
	int start, end;
	int sum;
	int cnt = 0;
	int hsum = 0;
	start = end = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> h[i];
	cin >> sum;
	sort(h, h + N, less<int>());

	start = 0;
	end = N - 1;
	while (start < end) {
		hsum = h[start] + h[end];
		if (hsum < sum) {
			start++;
		}
		if(hsum > sum) {
			end--;
		}
		if (hsum == sum) {
			end--;
			cnt++;
		}
		
	}

	cout << cnt << "\n";

	return 0;
}