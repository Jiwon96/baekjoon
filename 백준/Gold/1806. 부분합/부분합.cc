#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

int MIN_NUMBER = 100001;
int N;
ll S;
ll SUM=0;
ll arr[100000] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int S_start, S_end;
	S_start = S_end = 0;
	
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (S_start < N) {
		if (S <= SUM)
		{
			MIN_NUMBER = min(MIN_NUMBER, S_end - S_start);
			SUM -= arr[S_start];
			S_start++;
		}
		else {
			if (S_end > N) {
				break;
			}
			SUM+= arr[S_end];
			S_end++;
		}
		
	}

	if (MIN_NUMBER > 100000) {
		cout << "0 \n";
	}
	else {
		cout << MIN_NUMBER << "\n";
	}

	return 0;
}

