#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
using namespace std;

double play, win;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> play >> win;
	int win_rate = (win * 100) / play;
	if (win_rate >= 99) {
		cout << -1;
		return 0;
	}

	long long left = 0;
	long long right = 1000000000;
	long long mid = (left + right) / 2;

	while (left <= right) {
		mid = (left + right) / 2;
		int tmp_win_rate = ((win + mid) * 100) / (play + mid);
		if (win_rate >= tmp_win_rate) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left;
	return 0;
}