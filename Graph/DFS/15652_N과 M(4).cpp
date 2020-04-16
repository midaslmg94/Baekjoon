#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 8
using namespace std;
int n, m;
int arr[MAX];
vector<int>result;
bool visit[MAX];
/*
	1부터 N까지 자연수 중에서 M개를 고른 수열
	같은 수를 여러 번 골라도 된다.
	고른 수열은 비내림차순이어야 한다.
	--> 중복 조합
*/

void dfs(int start, int depth) {
	if (depth == m) {
		visit[start] = true;
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++) {
		if (visit[i])continue;		
		result.push_back(i);
		dfs(i, depth + 1);
		result.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	dfs(1, 0);
	return 0;
}