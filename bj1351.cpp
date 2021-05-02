#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int P, Q;
long long int N;
long long int result=0;
int recursive(int root)
{
    if(root == 0)
        return 1;
    return recursive(root/P)+recursive(root/Q);
}


int main()
{
    cin >> N >> P >> Q;

    result = recursive(N);

    cout << result;

    return 0;
}