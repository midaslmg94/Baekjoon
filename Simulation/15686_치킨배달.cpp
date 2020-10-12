#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
int board[51][51];
bool visited[14];
vector<pair<int, int>>chicken;
vector<pair<int, int>>home;
// 0은 빈 칸, 1은 집, 2는 치킨집이다.
vector<pair<int, int>>choice;
int answer = 1e9;
int cal_distance(int y, int x, int r, int c) {
	return abs(y - r) + abs(x - c);
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int ret = 0;
		for (int i = 0; i < home.size(); i++) { // 선택된 치킨집과 집들까지의 최소거리를 구함
			int res = 1e9;
			for (int j = 0; j < choice.size(); j++) {
				res = min(res, cal_distance(home[i].first, home[i].second, choice[j].first, choice[j].second));
			}
			ret += res;
		}
		answer = min(ret, answer);
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (visited[i])continue;
		visited[idx] = true;
		choice.push_back({ chicken[i].first, chicken[i].second });
		dfs(i + 1, cnt + 1);
		visited[idx] = false;
		choice.pop_back();
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				home.push_back({ i,j });
			}
			else if (board[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << answer;
}