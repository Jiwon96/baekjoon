#include<iostream>
#include<stack>
using namespace std;
int A[1000000];
int ret[1000000];

stack<int> S;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	S.push(0);
	ret[0] = (-1);
	for (int i = 0; i < (N - 1); i++)
	{
		while (!S.empty()&& A[S.top()] < A[i + 1]) {
			ret[S.top()] = A[i + 1];
			S.pop();
		}
		ret[i + 1] = ( - 1);
		S.push(i + 1);
	}

	for (int i = 0; i < N; i++)
		cout << ret[i] << " ";
	cout << "\n";

	return 0;
}