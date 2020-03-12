#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100+1
#define INF 987654231
using namespace std;
int dp[2][MAX];
int people[MAX];
bool clean[MAX];
int answer = INF;
vector<int>clean_day;
vector<int>day;
int n, m;
int calc() {
	int dirty[MAX]; // 더러움(아침)
	int unpleasant = 0; // 당일의 불쾌함
	int result = 0; // 누적 불쾌함
	memset(dirty, 0, sizeof(dirty));
	for (int i = 1; i <= n; i++) {
		if (clean[i]) { // 청소를 한 날
			dirty[i] = 0;
		}
		else {
			dirty[i] = dirty[i - 1] + people[i - 1];
		}
		unpleasant = dirty[i] * people[i];
		result += unpleasant;
	}
	return result;
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		day.clear();
		for (int i = 1; i <= n; i++) {
			if (!clean[i])continue;
			day.push_back(i); // 청소하는 날			
		}
		if (answer > calc()) {
			answer = calc();
			clean_day.clear();
			for (int i = 0; i < day.size(); i++) {
				clean_day.push_back(day[i]-1);
			}
		}
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (clean[i])continue;
		clean[i] = true;
		dfs(i + 1, cnt + 1);
		clean[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	dfs(1, 0);

	cout << answer << endl;
	sort(clean_day.begin(), clean_day.end());
	for (int i = 0; i < clean_day.size(); i++) {
		cout << clean_day[i] << ' ';
	}
	return 0;
}