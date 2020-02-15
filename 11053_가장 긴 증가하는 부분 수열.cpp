#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX 1000
using namespace std;
int n;
int arr[MAX];
int dp[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	int tmp = arr[0];
	for (int i = 1; i < n; i++) {		
		for (int j = 0; j <i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	sort(dp, dp + n);	
	cout << dp[n-1];
}