#include<bits/stdc++.h>
#define endl "\n"
#define MAX 201
#define ll long long
using namespace std;
ll dp[MAX][MAX]; // ���� i����, j�� ���� �� �ִ� ����� ��
int N, K;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;  // 0���� N������ ���� K���� ���ؼ� �� ���� N
	for (int j = 0; j < MAX; j++) {
		dp[1][j] = 1; // ���� 1���� j�� ���� �� �ִ� ���� 1��
	}
	
	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int j = 0; j <= n; j++) {
				dp[k][n] = dp[k][n] + dp[k - 1][j];
			}
			dp[k][n] %= 1000000000;
		}
	}
	cout << dp[K][N];
	return 0;
}