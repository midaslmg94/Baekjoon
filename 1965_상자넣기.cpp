#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
using namespace std;
int arr[MAX];
int dp[MAX];
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(dp[i],ans);
	}
	cout << ans;
}