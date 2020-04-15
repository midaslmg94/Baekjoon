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
int n;
int m;
bool broken[10];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n>> m;
	for (int i = 0; i < m; i++) {
		int ch;
		cin >> ch;
		broken[ch] = true;
	}
	int cur = abs(100 - n); // 현재 채널에서 +,-버튼으로 움직여서 갈 수 있는 경우



	return 0;
}