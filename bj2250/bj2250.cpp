#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string.h>
#define MAX 10001

using namespace std;


int N, nodeidx;
int node[MAX]; //???? 역할이 뭐지 루트를 찾는다?
int low[MAX];
int high[MAX];
pair<int, int> tree[MAX];
int root;

void DFS(int nodeNum, int cnt) // cnt는 레벨을 의미함
{
    if(tree[nodeNum].first > 0)
        DFS(tree[nodeNum].first, cnt+1);
    
    low[cnt] = min(low[cnt], nodeidx);
    high[cnt] = max(high[cnt], nodeidx++); //nodeidx는 순서임 node가 붙여지는 순서

    if(tree[nodeNum].second > 0)
        DFS(tree[nodeNum].second, cnt+1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    
    fill(low, low+MAX, 9876321); //memset은 1byte 단위로 채워져서 배열을 초기화할 땐 좋은 대안이 아니다
    fill(high, high + MAX, 0);
    fill(node, node + MAX, 0);
    
    cin >> N;

    for(int i = 1; i<=N; i++)
    {
        int parent, left_child, right_child;
        cin >> parent >> left_child >> right_child;

        node[parent]++;

        if(left_child != -1)
            node[left_child]++;
        tree[parent].first = left_child;

        if(right_child != -1)
            node[right_child]++;
        tree[parent].second = right_child;

        
    }

    for(int i =1; i<=N; i++)
        if(node[i] == 1)
            root = i;

    nodeidx =1;                 //레벨을 의미한다.
    DFS(root, 1);               // 탐색

    // min, max 구하기
    

    int max_idx, max_len;
    max_len = 0;

    for(int i =1; i<=N; i++)
    {
        if( high[i]-low[i] + 1  > max_len){
            max_idx = i;
            max_len = high[i]-low[i] +1;
        }
    }
    cout << max_idx << " " << max_len;

    return 0;
}