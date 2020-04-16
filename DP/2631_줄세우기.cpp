#include<iostream>
using namespace std;

int arr[200];
int dp[200]; // 각 인덱스 마다 증가 수열의 길이

/* 3 7 5 2 6 1 4 */
/*dp[0] = 1
	dp[1] = 1 , arr[1]>arr[0] && dp[1] <= dp[0]+1
	dp[1] = dp[0]+1 = 2
	dp[2] = 1, arr[2]>arr[0] && dp[2] <dp[0]+1
	dp[2] = 2, arr[2]>arr[1] False&& 
*/
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