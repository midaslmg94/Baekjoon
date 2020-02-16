#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#define MAX 8
struct CCTV {
	int y;
	int x;
	int type;
};
using namespace std;
int n;
int m;
int map[MAX][MAX];

CCTV cctv[MAX];  // cctv는 최대 8개
int cctv_size;
int res = 1000;

void update(int dir, int y, int x) {
	if (dir == 0) {// 상
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) 	map[i][x] = -1;
		}
	}
	else if (dir == 1) {// 우
		for (int j = x + 1; j < m; j++) {
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;			
		}
	}
	else if (dir == 2) {// 하
		for (int i = y + 1; i < n; i++) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
	}
	else if (dir == 3 ) {// 좌
		for (int j = x - 1; j >= 0; j--) {
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
	}
}
void dfs(int cctv_idx) {
	if (cctv_idx == cctv_size) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					cnt++;
				}
			}
		}
		res = min(res, cnt);
		return;
	}
	int cctv_type = cctv[cctv_idx].type;
	int y = cctv[cctv_idx].y;
	int x = cctv[cctv_idx].x;
	int backup[MAX][MAX];
	memcpy(backup, map, sizeof(backup));

	// dir[0] == 상, dir[1]==우, dir[2] ==하, dir[3]==좌
	if (cctv_type == 1) {// 상, 하, 좌, 우로 감시 가능
		for (int dir = 0; dir < 4; dir++) { 
			update(dir, y, x); // 1개의 면을 각각 업데이트 하면 된다
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map)); 
		}
	}
	else if (cctv_type == 2) {// 상하, 좌우로 감시 가능
		for (int dir = 0; dir < 2; dir++) {// 2개의 면을 업데이트 해야한다.
			// dir==0, dir==2 일때 : 상&하 업데이트
			// dir==1, dir==3 일때 : 좌&우 업데이트
			update(dir, y, x); 
			update(dir + 2, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}
	}
	else if (cctv_type == 3) {// 상좌, 상우, 하좌, 하우 로 감시 가능
		for (int dir = 0; dir < 4; dir++) {// 2개의 면을 업데이트 해야한다.
			// dir==0, dir==1 일때 : 상&우 업데이트
			// dir==1, dir==2 일때 : 우&하 업데이트
			// dir==2, dir==3 일때 : 하&좌 업데이트
			// dir==3, dir==0 일때 : 좌&상 업데이트
			update(dir, y, x); 
			update((dir + 1)%4, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}
	}
	// dir[0] == 상, dir[1]==우, dir[2] ==하, dir[3]==좌

	else if (cctv_type == 4) {// 상좌우, 상좌하, 하좌우, 상하우 로 감시 가능
		for (int dir = 0; dir < 4; dir++) {// 3개의 면을 업데이트 해야한다.
			// dir==0, dir==1, dir==2 일때 : 상&우&하 업데이트
			// dir==1, dir==2, dir==3 일때 : 우&하&좌 업데이트
			// dir==2, dir==3, dir==0 일때 : 하&좌&상 업데이트
			// dir==3, dir==0, dir==1 일때 : 좌&상&우 업데이트
			update(dir, y, x);
			update((dir+1)%4, y, x);
			update((dir+2)%4, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}

	}
	else { // 상하좌우로 감시 가능
		// 4개의 면을 업데이트 해야한다.
		for (int dir = 0; dir < 4; dir++) {
			update(dir, y, x);
		}
		dfs(cctv_idx + 1); 		
		memcpy(map, backup, sizeof(map));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				cctv[cctv_size].y = i;
				cctv[cctv_size].x = j;
				cctv[cctv_size].type = map[i][j];
				cctv_size++;
			}
		}
	}
	dfs(0);
	cout << res;
}