#include<iostream>
#include<algorithm>
#define MAX 2000
using namespace std;
int n;
int soldier[MAX];
int dp[MAX];


// LIS 문제
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> soldier[i];
	}
	
	int result = 1;
	
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (soldier[i] < soldier[j] && dp[i] < dp[j] + 1) { // 내림차순이므로 뒤에 병사가 더 작아야 함
				dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);
	}
	cout << n - result;
}