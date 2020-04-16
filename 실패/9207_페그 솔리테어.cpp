#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int n;
char map[5][9];
char backup[5][9];
bool visit[5][9];
/*
핀은 수평, 수직 방향으로 인접한 핀을 뛰어넘어서
그 핀의 '다음 칸'으로 이동하는 것만 허용된다.

인접한 핀의 다음 칸은 비어있어야 하고 그 인접한 핀은 제거된다.
현재 게임판에 꽂혀있는 핀의 상태가 주어진다.
이때, 핀을 적절히 움직여서 게임판에 남아있는 핀의 개수를 최소로 하려고 한다.
또, 그렇게 남기기 위해 필요한 최소 이동횟수를 구하는 프로그램을 작성하시오.
*/
// '.'는 빈 칸, 'o'는 핀이 꽂혀있는 칸, '#'는 구멍이 없는 칸
int dy[4] = { 0,0,-1,1 }; // dir[0] = 오른쪽, dir[1] = 왼쪽, dir[2] = 위쪽, dir[3] = 아래쪽
int dx[4] = { 1,-1,0,0 };
int move_cnt = 0;
queue<pair<pair<int, int>, int>>pin;
int bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({  y,x }); // 연결점의 좌표, 어떤 방향으로 연결되어 있는지
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;		
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < 5 && 0 <= nx && nx < 9 && !visit[ny][nx] && backup[ny][nx]=='o') { // 상하좌우 중 인접한 핀이 있으면
				q.push({ ny, nx });
				visit[ny][nx] = true;
				int dir = k; // dir[0] = 오른쪽, dir[1] = 왼쪽, dir[2] = 위쪽, dir[3] = 아래쪽
				dfs(ny, nx, dir); // 해당 지점으로 핀을 움직이며 백트래킹
			}
		}
	}
}

void dfs(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(0 <= ny && ny < 5 && 0 <= nx && nx < 9 && backup[ny][nx] == '.') { // 넘어가는 지점이 빈칸이어야 함
		backup[ny][nx] = 'o';
		backup[y][x] = '.';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	int res = 987654321;
	while (n--) {
		move_cnt = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
			}
		}
		memcpy(backup, map, sizeof(map));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (map[i][j] == 'o') {
					move_cnt=bfs(i, j); // 서로 연결된 핀 찾기
					res = min(res, move_cnt);
				}
			}
		}		
		memset(visit, false, sizeof(visit));
	}
	cout << res;
}