#include<iostream>
using namespace std;

int main() {
	int dp[1001];
	dp[1] = 1;
	dp[2] = 3;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		if (i % 2 != 0) {
			dp[i] = ((dp[i - 2] * 4) + 1) % 10007;
		}
		else {
			dp[i] = ((dp[i - 2] * 4) - 1) % 10007;
		}
	}
	cout << dp[n];
} 