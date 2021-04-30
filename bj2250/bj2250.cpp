#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


int main()
{
    map<int, pair<int, int>> t;
    int arr[10001][2] ={0}; // min, max 구할 array
    int n;
    int a, b, c; //노드 입력 변수
    stack < int > s;
    
    cin >> n;

    for(int i =1; i<=n; i++)
    {
        cin >> a >> b >> c;
        t[a] = make_pair(b, c);
    }
    
    int i =1;
    while(1)
    {
        while(t[i].first != -1)
        {
            s.push(t[i].first);
            i = t[i].first;
        }           
        while(t[i].first == -1)
        {
            arr[i][0] = i;
            i=s.top();
            s.pop();
        }
         


        if(t[i].second == -1) continue;
        
        i++;
    }

}