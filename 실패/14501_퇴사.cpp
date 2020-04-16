#include<iostream>
#include<algorithm>
#define MAX 16
int T[MAX]; // ����
int P[MAX]; // ����
int n;
int ans;
using namespace std;

// dfs
void dfs(int day, int sum) {
	if (day == n + 1) {
		ans = max(ans, sum);
		return;
	}
	// ����� �ϴ� ���
	if (day + T[day] <= n + 1)
		dfs(day + T[day], sum + P[day]);
	// �����  ���ϴ� ���
	dfs(day + 1, sum);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
	dfs(1, 0);
	cout << ans;
}