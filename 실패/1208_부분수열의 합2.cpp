#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define MAX 40
#define endl "\n"
using namespace std;
long long result = 0;
int n, s;
vector<int>v;
bool visit[40];
void dfs(int idx, int cnt,int depth) {
	if (cnt == depth) {
		int tmp = 0;
		for (int i = 0; i < v.size(); i++) {
			if (visit[i]) {
				tmp += v[i];
			}
		}
		if (tmp == s)
			result++;
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (visit[i])continue;
		visit[i] = true;
		dfs(i, cnt+1,depth);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	for (int i = 1; i <= v.size(); i++) {
		dfs(0,0,i);
		memset(visit, false, sizeof(visit));
	}
	cout << result;
	return 0;
}