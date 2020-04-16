#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define INF 1000000009
using namespace std;
int t;
int n;
long long diff = 0;
long long increment = 0;
vector<long long>dp;
long long num[1000001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	// base case 
	dp.push_back(0); // n=0
	dp.push_back(1); // n=1
	dp.push_back(2); // n=2
	dp.push_back(4); // n=3
	dp.push_back(7); // n=4
	for (int i = 5; i <= 1000001; i++) {
		/*	diff = dp[i - 1] - dp[i - 4];
			increment = (dp[i - 1] + diff) % INF;
			dp.push_back(increment);*/
		diff = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % INF;
		dp.push_back(diff);

	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}