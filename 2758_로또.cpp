#include<bits/stdc++.h>
#define endl "\n"
#define MAX 2001
using namespace std;
int n, m;
long long dp[11][2001]; // i��° �ڸ��� j�� ���� �� ���� �� �ִ� ����� ��

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
		cin >> n >> m; // �ڸ���, ���� ����  : 4 20�� ���Դٰ� ����
		cout << dp[n][m] << endl;
	}
	return 0;
}