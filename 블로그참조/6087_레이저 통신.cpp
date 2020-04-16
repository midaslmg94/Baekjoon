#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100
#define INF 987654231
using namespace std;
int dy[4] = {-1,1,0,0}; // 상하좌우
int dx[4] = { 0,0,-1,1 };

struct mirror
{
	int y;
	int x;
	int dir;
};
int n, m;
char map[MAX][MAX];
int visit[MAX][MAX][4]; // 현재 지점에서 방향별로 거울을 설치한 개수
pair<int, int> start_pos, end_pos;
queue<mirror>q;


pair<int, int> changeDir(int dir) {
	pair<int, int> result;
	if (dir == 0 || dir == 1) { // 레이저가 위쪽or아래쪽에서 들어오면 왼쪽or오른쪽으로 진행
		result.first = 2;
		result.second = 3;
	}
	else { // 레이저가 왼쪽or오른쪽에서 들어오면 위쪽or아래쪽으로 진행
		result.first = 0;
		result.second = 1;
	}
	return result;
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int,int> ndir = changeDir(dir);
		q.pop();
		if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
		if (map[ny][nx] == '*')continue;

		if (map[ny][nx] == '.') {
			// 거울을 설치 안한다 --> 방향은 안바뀜
			if (visit[ny][nx][dir] > visit[y][x][dir]) { // 해당위치에 거울을 설치하지 않고 진행
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}
			// 거울을 설치 한다 --> 방향이 바뀜
			if (visit[ny][nx][ndir.first] > visit[y][x][dir] + 1) {// 해당위치에 거울을 설치하고 진행
				visit[ny][nx][ndir.first] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.first });
			}
			if (visit[ny][nx][ndir.second] > visit[y][x][dir] + 1) {
				visit[ny][nx][ndir.second] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.second });
			}
		}
		else if (map[ny][nx] == 'C') { // 문 일 경우 : 도착 지점이므로, 해당 방향으로 들어오는 값을 비교하여 최솟값 저장
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> m >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') { 
				if (flag) {
					start_pos.first = i;
					start_pos.second = j;					
					flag = false;
				}
				else {
					end_pos.first = i;
					end_pos.second = j;
				}
			}
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}
	for (int k = 0; k < 4; k++) {
		q.push({ start_pos.first, start_pos.second, k });
		visit[start_pos.first][start_pos.second][k] = 0;
	}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, visit[end_pos.first][end_pos.second][i]);
	}
	cout << result;
	return 0;
}