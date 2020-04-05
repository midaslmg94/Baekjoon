#include<bits/stdc++.h>
#define endl "\n"
#define MAX 2001
using namespace std;
int n, m;
long long dp[11][2001]; // i번째 자리에 j가 들어갔을 때 나올 수 있는 경우의 수

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int j = 1; j < MAX; j++) {
		dp[1][j] = j;
	}
	for (int i = 2; i < 11; i++) {
		for (int j = 2; j < MAX; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j / 2];
		}
	}

	while (tc--) {
		cin >> n >> m; // 자리수, 들어가는 숫자  : 4 20이 들어왔다고 가정
		cout << dp[n][m] << endl;
	}
	return 0;
}