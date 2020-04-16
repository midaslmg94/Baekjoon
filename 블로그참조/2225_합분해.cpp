#include<bits/stdc++.h>
#define endl "\n"
#define MAX 201
#define ll long long
using namespace std;
ll dp[MAX][MAX]; // 숫자 i개로, j를 만들 수 있는 경우의 수
int N, K;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;  // 0부터 N까지의 정수 K개를 더해서 그 합이 N
	for (int j = 0; j < MAX; j++) {
		dp[1][j] = 1; // 숫자 1개로 j를 만들 수 있는 경우는 1개
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