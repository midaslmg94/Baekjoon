#include<bits/stdc++.h>
#define endl "\n"
#define MAX 50
#define pii pair<int, int>
using namespace std;
int lab[MAX][MAX];
int spread[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int answer = 987654321;
int wall_cnt = 0;
vector<pii>candi;

int bfs(vector<pii>v){
	memset(spread, -1, sizeof(spread));
	int res = 0;
	queue<pii>q;
	for (int i = 0; i < v.size(); i++) {
		spread[v[i].first][v[i].second] = 0;
		q.push({ v[i].first, v[i].second });
	}
	while (!q.empty()) {
		int q_size = q.size();
		res++;
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= n)continue;
				if (spread[ny][nx] != -1)continue; // 이미 바이러스가 퍼진 지점
				if (lab[ny][nx] == 1)continue; // 벽
				spread[ny][nx] = res;
				q.push({ ny,nx });
			}
		}
	}
	// 모든 칸에 바이러스가 퍼졌는지 확인
	int empty_space = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (spread[i][j] == -1)
				empty_space++;
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << spread[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << res << endl << endl;

	if (empty_space != wall_cnt)
		return 987654321;
	else
		return res-1;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		vector<pii>virous;
		for (int i = 0; i < candi.size(); i++) {
			int y = candi[i].first;
			int x = candi[i].second;
			if (!visited[y][x])continue;
			virous.push_back({ y,x });
		}
		answer = min(answer,bfs(virous));
		return;
	}

	for (int i = idx; i < candi.size(); i++) {
		int y = candi[i].first;
		int x = candi[i].second;
		if (visited[y][x])continue;
		visited[y][x] = true;
		dfs(i, cnt + 1);
		visited[y][x] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1)
				wall_cnt++;
			else if (lab[i][j] == 2) {
				candi.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	// 만약 바이러스를 퍼트릴 수 없으면 -1을 출력
	if (answer == 987654321) 
		cout << -1;
	else
		cout << answer;
	return 0;
}