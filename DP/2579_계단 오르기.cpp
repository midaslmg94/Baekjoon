#include<iostream>
#include<algorithm>
using namespace std;
int dp[301];
int arr[301];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	/*
		1. 현재 있는 계단 이전의 계단을 밟은 경우
		2. 현재 있는 계단 이전의 계단을 밟지 않은 경우
	*/
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	// dp[3] = max(1번 + 3번 or 2번 + 3번)
	dp[3] = max(arr[1]+arr[3], arr[2]+arr[3]);

	/*
		1. dp[i-2] 를 더하는 경우 : 어차피 연속 3칸이 나올수 없으므로 현재 위치만 더하면 된다.
		2. dp[i-3]+arr[i-1]을 더하는 경우 : dp[i-1]+arr[i]를 하면 연속 3칸이다.  이전칸(arr[i-1])을 밟고 싶은데 연속 3칸이면 안되기 때문에 dp[i-3]을 해준다
		
	*/
	for (int i = 4; i <= n; i++){
		dp[i] = max(arr[i]+dp[i-2], arr[i]+dp[i-3]+arr[i-1]);
	}
	cout << dp[n];
}