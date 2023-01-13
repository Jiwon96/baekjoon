#include<iostream>
#include<stack>

using namespace std;
int Ai[1000000]={0};
int F[1000001] = { 0 };
int Fi[1000000] = { 0 };
int ret[1000000] = { 0 };
stack<int> S;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Ai[i];
		F[Ai[i]]++;
	}

	for (int i = 0; i < N; i++)
		Fi[i] = F[Ai[i]];


	S.push(0);
	ret[0] = -1;
	for (int i = 0; i < N - 1; i++)
	{
		
		while (!S.empty() && Fi[i + 1] > Fi[S.top()]) {
			ret[S.top()] = Ai[i + 1];
			S.pop();
		}
		S.push(i + 1);
		ret[i + 1] = ( - 1);
	}

	for (int i = 0; i < N; i++)
		cout << ret[i] << " ";
	cout << "\n";

	return 0;
}