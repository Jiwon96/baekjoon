#include<iostream>
#include<string>
#include<queue>
using namespace std;
string word;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str >> word;
	string t = "";

	int a_len = str.length();
	int b_len = word.length();
	
	for (int i = 0; i < str.length(); i++)
	{
		t += str[i];
		if (t.length() >= b_len) {
			bool flag = true;
			for (int j = 0; j < b_len; j++) {
				if (word[j] != t[t.length() - b_len + j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				t.erase(t.end() - b_len, t.end());
			}
		}
		
	}

	if (t.empty()) {
		cout << "FRULA\n";
	}
	else {
		cout << t << "\n";
	}


	return 0;
}