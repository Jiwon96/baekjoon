#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int number;
int a[4000001];
vector<int> prime_vec;

void primeNumberSieve() {

    // 1. 배열을 생성하여 초기화한다.
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }

    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
    // (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
    for (int i = 2; i <= number; i++) {
        if (a[i] == 0) continue; // 이미 지워진 수라면 건너뛰기

        // 이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 지우기
        for (int j = 2 * i; j <= number; j += i) {
            a[j] = 0;
        }
    }

    // 3. 2부터 시작하여 남아있는 수를 모두 출력한다.
    for (int i = 2; i <= number; i++) {
        if (a[i] != 0) prime_vec.push_back(a[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int vector_start = 0;
    int vector_end = 0;
    int SUM = 0;
    int cnt = 0;
    cin >> N;

    number = N;

    primeNumberSieve();

    while (vector_start < prime_vec.size()) {
        if (SUM == N) {
            cnt++;
            if (vector_end >= prime_vec.size()) {
                SUM -= prime_vec[vector_start];
                vector_start++;
                continue;
            }
            SUM += prime_vec[vector_end];
            vector_end++;
        }
        else {
            if (SUM > N) {
                SUM -= prime_vec[vector_start];
                vector_start++;
            }
            else {
                if (vector_end == prime_vec.size())
                    break;
                SUM += prime_vec[vector_end];
                vector_end++;
            }
        }
    }

    cout << cnt << "\n";
    
    return 0;
}