#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define MAX 100+1 // 최대 곡수
#define MAXV 1000+1 // 최대 볼륨
#define endl "\n"
using namespace std;
int n, s, m;
int song[MAX];
int dp[MAX][MAXV]; // i번째 노래일 때 변경하여 연주가능한 볼륨정보. 현재 소리가 6이고, song[i]가 3이면 dp[6][3] = 1, dp[6][9] = 1
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> song[i];
	}
	// 첫번째 곡 
	if (s + song[0] <= m)dp[0][s + song[0]] = 1;
	if (s - song[0] >= m)dp[0][s - song[0]] = 1;

	//두번째 곡 부터 계산
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