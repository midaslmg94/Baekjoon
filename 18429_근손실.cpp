#include<iostream>
#include<vector>
#define MAX 8
using namespace std;
int arr[MAX];
vector<int>plan;
bool visit[MAX];
int n, k;

int result=0;
void dfs(int idx) { // 순열 구하기
	if (idx == n) {
		// 항상 500이상인지 확인
		int check = 500;
		for (int i = 0; i < plan.size(); i++) {
			check = check - k + plan[i];
			if (check < 500) {
				return;
			}
		}
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			plan.push_back(arr[i]);
			dfs(idx + 1);
			plan.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> k;	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(1);
	cout << result;
}