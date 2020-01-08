#include<iostream>
using namespace std;

int arr[200];
int dp[200]; // 각 인덱스 마다 증가 수열의 길이


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 0;
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) { // 0부터 i-1까지 증가 길이
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { // dp[i]<dp[j]+1이 왜 그런지 잘 모르겠다.
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << n - ans;
}