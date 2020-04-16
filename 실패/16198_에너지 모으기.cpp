#include<bits/stdc++.h>
#define endl "\n"
#define MAX 11
using namespace std;
int n;
int arr[MAX];

vector<int>res;
bool visit[MAX];
int answer = 0;
int go() {
	int result = 0;
	vector<int>backup;
	for (int i = 0; i < n; i++) {
		backup.push_back(arr[i]);
	}
	for (int i = 0; i < res.size(); i++) {
		result += backup[res[i - 1]] * backup[res[i + 1]];

	}
	return result;
}
void dfs(int cnt) {
	if (cnt == n - 2) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << endl;
		answer = max(answer, go());
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (visit[i])continue;
		visit[i] = true;
		res.push_back(i);
		dfs(cnt + 1);
		res.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0);
	cout << answer;
	return 0;
}