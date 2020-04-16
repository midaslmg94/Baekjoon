#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 7
using namespace std;
int n, m;
int arr[MAX];
vector<int>result;
bool visit[MAX];
/*
	- 1���� N���� �ڿ��� �߿��� M���� �� ����
	- ���� ���� ���� �� ��� �ȴ�.
	--> �ߺ� ����
*/

void dfs(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < result.size(); i++) {
			cout<<result[i]<<' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		result.push_back(i);
		dfs(i, depth + 1);
		result.pop_back();
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