#include<iostream>
#include<map>

using namespace std;

map <long long, long long> ma;
int P, Q;
long long int N;
long long int result=0;

long long recursive(long long root)
{
    if(ma.count(root))
        return ma[root];
    else{
        return ma[root] = recursive(root/P)+recursive(root/Q);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> P >> Q;

    ma[0] = 1;

    cout << recursive(N);

    return 0;
}