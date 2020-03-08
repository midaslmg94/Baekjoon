#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
using namespace std;
int n;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	deque<int>dq;
	deque<char>oper;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			int num = str[i] - '0';
			dq.push_back(num);
		}
		else {
			oper.push_back(str[i]);
		}

	}
	return 0;
}