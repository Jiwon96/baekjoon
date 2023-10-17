# kanpsack 풀이
* 재귀를 사용할 때에는 신중해야되는데
  * bottom-up 방식으로 풀 수 있는지 생각해보자
    * 이 때 특징은 순서, sequence에 예민했어야됨
      * knapsack 문제는 첫 번째 짐까지, 두 번째 짐까지, '누적'되는 양을 저장했음.
      * 반면 dfs를 사용하려면 순서가 뒤죽박죽이 되버림. 1->3->2->4-> 등등 이렇게 sequence가 정해지지 않았을 때 사용할 수 있음.
     
```cpp
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int pack[101][1001]; //최대 가질 수 있는 
vector<pair<int, int>> bag;
int N, K; //개수 부피
void init(){
 	   memset(pack, 0, sizeof(pack));
    	while(!bag.empty()){
     	bag.pop_back();   
    }
}
void input(){
    cin >> N >>K;
    for(int i=0; i<N; i++){
     	int n1, n2;
        cin >> n1 >>n2;
        bag.push_back({n1, n2}); // 부피, 가치
    }
}
int dfs(){	//부피일 때 최대 가치
    for(int j=0; j<N; j++){
    	for(int i=0; i<=K; i++){
     		   if(i - bag[j]. first >=0)
                   pack[j+1][i] = max(pack[j][i], pack[j][i-bag[j].first] + bag[j].second); //안넣거나 넣거나
               else
                   pack[j+1][i] = pack[j][i]; //안넣을 때
    	}
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		init();
        input();
        dfs();
        cout <<"#"<<test_case<<" " << pack[N][K]<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
```
