#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define endl "\n"
#define MAX 300
using namespace std;
int map[MAX][MAX];
bool visit[MAX][MAX];
int t;
int length;
int dy[8] = { -2,-1,1,2,2,1,-1,-2 }; //맨 처음은 자기 자신, 시계 반대방향으로 가는 경로
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int start_y, start_x, end_y, end_x;
int result = 0;
int bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		// 현재 위치가 도착지인지 확인
		if (y == end_y && x == end_x) {
			return map[y][x];
		}
		for (int k = 0; k < 8; k++) {
			int ny = dy[k] + y;
			int nx = dx[k] + x;			
			if (0 <= ny && ny < length && 0 <= nx && nx < length && !visit[ny][nx]) {
				visit[ny][nx] = true;
				map[ny][nx] = map[y][x] + 1;
				if (ny == end_y && nx == end_x) {
					return map[ny][nx];
				}
				q.push({ ny,nx });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		result = 0;
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		cin >> length;
		cin >> start_y >> start_x;
		cin >> end_y >> end_x;
		result = bfs(start_y, start_x);
		cout << result << endl;
	}

}
