#include<iostream>
#include<queue>
#include<string.h>
#define MAX 51
using namespace std;
int map[MAX][MAX]; // 0: 빈칸, 1: 벽 , -1:청소한 칸
bool clean[MAX][MAX];
int dy[4] = { -1,0,1,0 }; // 0 :북쪽, 1:동쪽 2:남쪽 3:서쪽
int dx[4] = { 0,1,0,-1 };
int n, m;
int r, c, d;
int result;

void bfs(int y, int x) {
	// 현재 위치 청소
	result = 1;
	map[y][x] = -1;
	clean[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		bool canClean = false; // 청소가능한 방이 있는지 확인
		for (int k = 0; k < 4; k++) { // 4방향 탐색
			d = (d + 3) % 4; // 현재 방향에서 왼쪽을 본다
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !clean[ny][nx]) {
				if (map[ny][nx] == 0) { // 왼쪽 방향에 청소하지 않은 공간이 존재한다면 해당방향으로 진행
					result++;
					map[ny][nx] = -1;// 청소를 했음
					clean[ny][nx] = true; 
					canClean = true;
					q.push({ ny,nx });
					break;
				}
				else { // 왼쪽 방향에 청소할 공간이 없음 -> 또 왼쪽방향으로 돌아가야 함
					continue;
				}
			}
		}
		if (!canClean) { //청소를 못했다면 후진 가능한지 확인			 
			int back = (d + 2) % 4; 
			int back_y = y + dy[back];
			int back_x = x + dx[back];
			if (0 <= back_y && back_y < n && 0 <= back_x && back_x < m) {
				if (map[back_y][back_x] != 1) { // 벽이 아니라면, 후진 가능
					q.push({ back_y,back_x });
					if (map[back_y][back_x] == 0 && !clean[back_y][back_x]) {
						clean[back_y][back_x] = true;
						result++;
					}
				}
				else { // 후진도 불가능 --> 작동을 멈춤
					cout << result<<endl;
					return;
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	cin >> r >> c >> d; // 로봇의 y좌표, x좌표, 방향 
	// 0 :북쪽, 1:동쪽 2:남쪽 3:서쪽
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bfs(r, c);
}