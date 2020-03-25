#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define MAX 100+1 // �ִ� ���
#define MAXV 1000+1 // �ִ� ����
#define endl "\n"
using namespace std;
int n, s, m;
int song[MAX];
int dp[MAX][MAXV]; // i��° �뷡�� �� �����Ͽ� ���ְ����� ��������. ���� �Ҹ��� 6�̰�, song[i]�� 3�̸� dp[6][3] = 1, dp[6][9] = 1
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> song[i];
	}
	// ù��° �� 
	if (s + song[0] <= m)dp[0][s + song[0]] = 1;
	if (s - song[0] >= m)dp[0][s - song[0]] = 1;

	//�ι�° �� ���� ���
	for (int i = 1; i < n; i++) {
		int changeVolume = song[i];
		for (int j = 0; j <= m; j++) {
			if (j + changeVolume <= m)dp[i][j + changeVolume] = 1;
			if (j - changeVolume >= 0)dp[i][j - changeVolume] = 1;
		}
	}


	for (int i = m; i >= 0; i--) {
		if (dp[n - 1][i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}