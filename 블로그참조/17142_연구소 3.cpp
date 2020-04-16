#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define MAX 50
#define endl "\n"
#define pii pair<int, int>
#define INF 987654321
using namespace std;
int map[MAX][MAX];
int visit[MAX][MAX];
bool choice[10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
int empty_space; // ��ĭ
int answer = INF;
vector<pii>virous; // ���̷����� ������ �ð�, y��ǥ, x��ǥ

void bfs(queue<pii>q) {
	int virous_cnt = 0; // ���� ���̷����� ����
	int spread_time = 0; // �����µ� �ɸ��� �ð�
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= n)continue; // ���� �ʰ� 
				if (map[ny][nx] != 1 && visit[ny][nx] == -1) { // ���� �ƴϰ�, �湮���� ���� ���� --> �̺κ��� ����
					visit[ny][nx] = visit[y][x] + 1;
					if (map[ny][nx] == 0) { // �� ������ ���, ���� ���̷����� ���� ����
						virous_cnt++;
						spread_time = visit[ny][nx];
					}
					q.push({ ny,nx });
				}
			}
		}
	}
	if (virous_cnt == empty_space) {
		answer = min(answer, spread_time);
	}
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		queue<pii>active_virous;
		memset(visit, -1, sizeof(visit));
		for (int i = 0; i < virous.size(); i++) {
			if (!choice[i])continue;
			active_virous.push({ virous[i].first, virous[i].second });
			visit[virous[i].first][virous[i].second] = 0;
		}
		bfs(active_virous);
		return;
	}
	for (int i = idx; i < virous.size(); i++) {
		if (choice[i])continue;
		choice[i] = true;
		dfs(i, cnt + 1);
		choice[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (map[i][j] == 0) {
				empty_space++;
			}
			else if (map[i][j] == 2) {
				virous.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	if (answer == INF) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}