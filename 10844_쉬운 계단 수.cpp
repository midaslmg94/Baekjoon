#include<iostream>
#define mod 1000000000
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int dp[101][10] = { 0, };
	// dp[N][L] = dp[N-1][L-1] + dp[N-1][L+1]
	// 길이 N, 마지막 숫자가 L일 경우
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % mod;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % mod;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}  
		}
	}
	for (int i = 1; i < 10; i++) {
		sum = (sum + dp[n][i]) % mod;
	}
	cout << sum % mod;

}