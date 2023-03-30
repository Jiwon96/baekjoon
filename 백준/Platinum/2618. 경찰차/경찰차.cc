#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int board[1001][1001] ={0};
//vector<pair<int, int>> cases;
vector<pair<int, int>> car1, car2;
int ans=0;
int N;
int case_number;
int getDist(int A, int B) {

	if (A == case_number || B == case_number)
		return 0;


	int& ret = board[A][B];
	if (ret != -1)
		return ret;

	ret = 9876543321;

	int nextcase = max(A, B) + 1;

	int distA = abs(car1[A].first - car1[nextcase].first) + abs(car1[A].second - car1[nextcase].second);
	int distB = abs(car2[B].first - car2[nextcase].first) + abs(car2[B].second - car2[nextcase].second);

	int cumdistA = getDist(nextcase, B) + distA;
	int cumdistB = getDist(A, nextcase) + distB;
	
	return ret = min(cumdistA, cumdistB);
}

void tracking(int A, int B) {
	if (A == case_number || B == case_number)
		return ;

	int nextcase = max(A, B) + 1;

	int distA = abs(car1[A].first - car1[nextcase].first) + abs(car1[A].second - car1[nextcase].second);
	int distB = abs(car2[B].first - car2[nextcase].first) + abs(car2[B].second - car2[nextcase].second);

	int cumdistA = getDist(nextcase, B) + distA;
	int cumdistB = getDist(A, nextcase) + distB;

	if (cumdistA < cumdistB) {
		cout << 1 << "\n";
		tracking(nextcase, B);
	}
	else
	{
		cout << 2 << "\n";
		tracking(A, nextcase);
	}

}

void solution() {
	cout << getDist(0, 0) <<"\n";
	tracking(0, 0);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N>>case_number;
	car1.push_back( { 1, 1 });
	car2.push_back({N, N});

	memset(board, -1, sizeof(board));

	for (int i = 0; i < case_number; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		car1.push_back({ num1, num2 });
		car2.push_back({ num1, num2 });
	}

	solution();

	return 0;
}