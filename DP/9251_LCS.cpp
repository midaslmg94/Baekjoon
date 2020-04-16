#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[1001][1001];
int main() {
	string s1, s2;
	string s3 = "";
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				s3 += s1[i - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[s1.size()][s2.size()];
	cout << endl << s3;
}   