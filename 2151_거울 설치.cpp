#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define INF 987654321
#define MAX 50
using namespace std;
struct mirror {
	int y, x, dir;
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 }; // 상하좌우
int n;
char map[MAX][MAX];
int visit[MAX][MAX][4]; // i,j에서 빛이 k의 방향으로 진행할 때, 지금까지 설치한 문의 개수

pair<int, int>startDoor;
pair<int, int>endDoor;
queue<mirror>q;
pair<int, int> changeDir(int cur) { // 빛이 들어오는 방향에 따라 거울에 부딪혔을때 꺾이는 게 다르다.(2가지 형태의 거울에 부딪힘)
	pair<int, int>res;
	if (cur == 0 || cur == 1) { // 빛이 위쪽이나 아래쪽에서 들어옴 --> 빛은 왼쪽이나 오른쪽으로 진행
		res.first = 2; // 왼쪽으로 진행할 수도 있고
		res.second = 3; // 오른쪽으로 진행할 수도 있음
	}
	else if (cur == 2 || cur == 3) { // 빛이 왼쪽이나 아래쪽에서 들어옴 --> 빛은 위쪽이나 아래쪽으로 진행
		res.first = 0; // 위로 진행할 수도 있고
		res.second = 1;  // 아래로 진행할 수도 있음
	}
	return res;
}
void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int, int> ndir = changeDir(dir);

		if (0 > ny || ny >= n || 0 > nx || nx >= n)continue; // 범위 초과
		if (map[ny][nx] == '*') continue; // 벽 일 경우 : 진행불가
		else if (map[ny][nx] == '!') { // 거울일 경우
			if (visit[ny][nx][dir] > visit[y][x][dir]) { // 해당위치에 거울을 설치하지 않고 진행
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}			
			// 아래 2개의 if를 이해하는게 가장 어려웠다.
			// else if가 아닌 if를 사용해야함 --> 거울은 2가지 상태를 가질 수 있기 떄문
			if (visit[ny][nx][ndir.first] > visit[y][x][dir] + 1) {// 해당위치에 거울을 설치하고 진행
				visit[ny][nx][ndir.first] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.first });
			}
			if (visit[ny][nx][ndir.second] > visit[y][x][dir] + 1) {
				visit[ny][nx][ndir.second] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.second});
			}			
		}
		else if (map[ny][nx] == '.') { // 빈 곳일 경우 : 기존의 값이 더 작을경우 갱신
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}
		}
		else if (map[ny][nx] == '#') { // 문 일 경우 : 도착 지점이므로, 해당 방향으로 들어오는 값을 비교하여 최솟값 저장
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				if (flag) { // 시작하는 문
					startDoor.first = i;
					startDoor.second = j;
					flag = false;
				}
				else {// 도착하는 문
					endDoor.first = i;
					endDoor.second = j;
				}					
			}
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}

	for (int i = 0; i < 4; i++) {// 처음 문에서부터 시작
		q.push({ startDoor.first,startDoor.second,i });
		visit[startDoor.first][startDoor.second][i] = 0;
	}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++) { // 마지막 지점에서 4방향으로 들어온 경우 중 최솟값 출력
		if (result > visit[endDoor.first][endDoor.second][i]) {
			result = visit[endDoor.first][endDoor.second][i];
		}
	}
	cout << result;
	return 0;
}