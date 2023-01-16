#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int h[100001];
int ret;

int rect(int left, int right)
{
	if (left == right)
		return h[left];
	int mid = (left + right) / 2;
	int io, ro;
	int height;
	ret = max(rect(left, mid), rect(mid + 1, right));
	io = mid;
	ro = mid + 1;
	height = min(h[io], h[ro]);
	ret = max(height * 2, ret);

	while (io > left || ro < right)
	{
		if (ro < right && (io == left || h[io - 1] < h[ro + 1]))
		{
			ro++;
			height = min(height, h[ro]);
		}
		else
		{
			io--;
			height = min(h[io], height);
		}
		ret = max((ro - io + 1) * height, ret);
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> h[i];
	long long solve = rect(1, N);

	cout << solve << endl;

	return 0;
}