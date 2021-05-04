#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;

map <long long, long long> ma;

int P, Q;
long long int N;
long long int result=0;
int recursive(long long root)
{
    if(ma.count(root))
        return ma[root];
    else{
        ma[root] =recursive(root/P)+recursive(root/Q);
    }
    return ma[N]; 
}


int main()
{
    cin >> N >> P >> Q;

    result = recursive(N);

    cout << result;

    return 0;
}