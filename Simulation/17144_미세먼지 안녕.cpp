#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 50
#define pii pair<int,int>
using namespace std;
int r, c, t;
int map[MAX][MAX];
int backup[MAX][MAX];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> r >> c >> t;
	vector<pii>air;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air.push_back({ i,j });
			}
		}
	}

	while (t--) {
		// 먼지 확산
		queue<pii>q; // 확산되는 먼지의 위치가 담김
		memset(backup, 0, sizeof(backup));
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {				
				if (map[y][x] != 0) {
					int cnt = 0; // 확산 가능한 지점
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (0 > ny || ny >= r || 0 > nx || nx >= c)continue; // 경계선 초과
						if (map[ny][nx] == -1)continue; // 공기청정기로는 확산 불가
						q.push({ ny,nx });
						cnt++;
					}
					int spread = map[y][x] / 5;
					map[y][x] = map[y][x] - (spread*cnt);
					while (!q.empty()) {
						backup[q.front().first][q.front().second] += spread;
						q.pop();
					}
				}
			}
		}
		// 먼지를 합친다.
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {
				map[y][x] += backup[y][x];
			}
		}

		// 공기청정기 가동 -> 먼지 이동	
		memcpy(backup, map, sizeof(backup));
		// 위쪽 공기청정기 가동 
		int air_up_y = air[0].first;
		int air_up_x = air[0].second;

		// 오른쪽 확산
		
		for (int j = air_up_x+1; j < c-1; j++) {
			backup[air_up_y][j + 1] = map[air_up_y][j];
		}
		backup[air_up_y][air_up_x+1] = 0;
		// 위쪽 확산
		for (int i = air_up_y; i > 0; i--) {
			backup[i - 1][c - 1] = map[i][c - 1];
		}
		// 왼쪽 확산
		for (int j = c - 1; j > 0; j--) {
			backup[0][j - 1] = map[0][j];
		}
		// 아래쪽 확산
		for (int i = 0; i < air_up_y-1; i++) {
			backup[i + 1][0] = map[i][0];
		}

		// 아래쪽 공기청정기 가동
		int air_down_y = air[1].first;
		int air_down_x = air[1].second;
		// 오른쪽 확산 
		for (int j = air_down_x+1; j < c - 1; j++) {
			backup[air_down_y][j + 1] = map[air_down_y][j];
		}
		backup[air_down_y][air_up_x + 1] = 0;
		// 아래쪽 확산	
		for (int i = air_down_y; i < r - 1; i++) {
			backup[i + 1][c-1] = map[i][c-1];
		}
		// 왼쪽 확산
		for (int j = c - 1; j > 0; j--) {
			backup[r-1][j - 1] = map[r-1][j];
		}
		// 위쪽 확산
		for (int i = r-1; i > air_down_y+1; i--) {
			backup[i - 1][0] = map[i][0];
		}
		memcpy(map, backup, sizeof(map));		
	}

	// 남은 먼지 세기
	int result = 0;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if(map[y][x]!=-1)
				result += map[y][x];
		}
	}
	cout << result;
	return 0;
}