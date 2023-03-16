#include<iostream>

using namespace std;

int arr[1000000 + 1]={0};
int cnt[1000000 + 1] = { 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i= 0; i <= 1000000; i++)
		arr[i] = 1000001;

	arr[1] = 0;
	cnt[1] = 0;

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i - 1] + 1 < arr[i]) {
			arr[i] = arr[i - 1] + 1;
			cnt[i] = i - 1;
		}
		if (i % 3 == 0 && arr[i / 3]+1 < arr[i]) {
			arr[i] = arr[i / 3] + 1;
			cnt[i] = i / 3;
		}
		if (i % 2 == 0 && (arr[i / 2]+1 < arr[i])) {
			arr[i] = arr[i / 2] + 1;
			cnt[i] = i / 2;
		}
	}
	int j = N;
	cout << arr[N] << "\n";
	while (j != 0) {
		cout << j << " ";
		j = cnt[j];
	}

	return 0;
}