#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stdlib.h>
#include<string>
#include<string.h>
#define endl "\n"
using namespace std;
string str;
bool canUse[10];
int m;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> str;
	cin >> m;
	memset(canUse, true, sizeof(canUse));
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		canUse[tmp] = false;
	}

	vector<char>num;
	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - '0';
		int idx = 1;
		while (true) {
			if (canUse[n] == true) {
				num.push_back(n + 48); // int를 char로 변환
				break;
			}
			else {
				if (n + idx <= 9) {
					if (canUse[n + idx]) { // 숫자 한개 더 큰거 확인
						num.push_back(n + idx + 48);
						break;
					}
				}
				if (n - idx >= 0) {
					if (canUse[n - idx]) { // 숫자 하나 더 작은거 확인
						num.push_back(n - idx + 48);
						break;
					}
				}
			}
			idx++;
		}
	}

	string s = "";
	for (int i = 0; i < num.size(); i++) {
		s += num[i];
	}
	int candi = stoi(s);
	int curChannel = 100;

	int curToTarget = abs(curChannel - stoi(str));
	int candiToTarget = abs(candi - stoi(str)) + num.size();
	int result = 0;
	result = min(curToTarget, candiToTarget);
	cout << result;
	return 0;
}