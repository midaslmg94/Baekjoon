#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int>podo;
int dp[3][10000];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		podo.push_back(tmp);
	}
	dp[0][0] = 0; 
	dp[1][0] = podo[0];
	dp[2][0] = 0;

	for (int i = 1; i < n; i++) {
		dp[0][i] = max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1])); // �̹��� �ȸ��� 
		dp[1][i] = podo[i] + dp[0][i-1]; // ù��°�� ����
		dp[2][i] = podo[i] + dp[1][i-1]; // �ι�°�� ����
	}
	cout << max(dp[0][n - 1],max(dp[1][n - 1], dp[2][n - 1]));
}