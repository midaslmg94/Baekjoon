#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX 100000
using namespace std;
int t;
int n;
int map[2][MAX];
int dp[2][MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		dp[0][0] = map[0][0];
		dp[0][1] = map[1][0];
		for (int i = 1; i < n; i++) {
			dp[0][i] = ;
			dp[1][i] = ;
		}
	}
	return 0;

}