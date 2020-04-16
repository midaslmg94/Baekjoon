#include<bits/stdc++.h>
#define endl "\n"
#define INF 987546
#define MAX 200
using namespace std;
int W, H;
int K;
int arr[MAX][MAX];
int visit[MAX][MAX][31];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int hy[8] = { -1,-2,-2,-1,1,2,2,1 };
int hx[8] = { -2,-1,1,2,-2,-1,1,2 };
int answer = INF;
void bfs() {
	queue<pair<int, pair<int, int>>>q;
	q.push(make_pair(0, make_pair(0, 0)));
	visit[0][0][0] = 0;
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int jump = q.front().first;
		q.pop();
		if (y == H - 1 && x == W - 1) {
			answer = min(answer, visit[y][x][jump]);
		}
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= H || 0 > nx || nx >= W)continue; // 범위 초과
			if (visit[ny][nx][jump] != -1 || arr[ny][nx]==1)continue; // 진행불가지점
			visit[ny][nx][jump] = visit[y][x][jump] + 1;
			q.push(make_pair(jump, make_pair(ny, nx)));
		}
		if (jump < K) {// 해당 위치에서 점프횟수가 남았다면
			for (int k = 0; k < 8; k++) {
				int ny = y + hy[k];
				int nx = x + hx[k];
				int njump = jump + 1;
				if (0 > ny || ny >= H || 0 > nx || nx >= W)continue; // 범위 초과
				if (visit[ny][nx][njump] != -1 || arr[ny][nx] == 1)continue;// 진행불가지점
				visit[ny][nx][njump] = visit[y][x][jump] + 1;
				q.push(make_pair(njump, make_pair(ny, nx)));
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}
	memset(visit, -1, sizeof(visit));
	bfs();
	if (answer == INF)answer = -1;
	cout << answer;
	return 0;
}