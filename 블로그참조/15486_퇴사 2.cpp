#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define endl "\n"
#define MAX 1500000+1
using namespace std;
int n;
int times[MAX];
int pay[MAX];
int dp[MAX]; // ���� �������� �� �� �ִ� �ִ� �׼�. dp[3]�� ��� 1~2�ϱ��� �� �� �ִ� �ִ� �ݾ�.

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> times[i] >> pay[i];
		dp[i] = 0;
	}
	int answer = 0;
	for (int i = 1; i <= n+1; i++) { // �� n+1 ����?
		answer = max(dp[i], answer);
		if (i + times[i] > n + 1)continue;
		dp[i + times[i]] = max(answer + pay[i], dp[i + times[i]]);

	}
	cout << answer;
}