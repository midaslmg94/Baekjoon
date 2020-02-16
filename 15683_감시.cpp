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

CCTV cctv[MAX];  // cctv�� �ִ� 8��
int cctv_size;
int res = 1000;

void update(int dir, int y, int x) {
	if (dir == 0) {// ��
		for (int i = y - 1; i >= 0; i--) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) 	map[i][x] = -1;
		}
	}
	else if (dir == 1) {// ��
		for (int j = x + 1; j < m; j++) {
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;			
		}
	}
	else if (dir == 2) {// ��
		for (int i = y + 1; i < n; i++) {
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
	}
	else if (dir == 3 ) {// ��
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

	// dir[0] == ��, dir[1]==��, dir[2] ==��, dir[3]==��
	if (cctv_type == 1) {// ��, ��, ��, ��� ���� ����
		for (int dir = 0; dir < 4; dir++) { 
			update(dir, y, x); // 1���� ���� ���� ������Ʈ �ϸ� �ȴ�
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map)); 
		}
	}
	else if (cctv_type == 2) {// ����, �¿�� ���� ����
		for (int dir = 0; dir < 2; dir++) {// 2���� ���� ������Ʈ �ؾ��Ѵ�.
			// dir==0, dir==2 �϶� : ��&�� ������Ʈ
			// dir==1, dir==3 �϶� : ��&�� ������Ʈ
			update(dir, y, x); 
			update(dir + 2, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}
	}
	else if (cctv_type == 3) {// ����, ���, ����, �Ͽ� �� ���� ����
		for (int dir = 0; dir < 4; dir++) {// 2���� ���� ������Ʈ �ؾ��Ѵ�.
			// dir==0, dir==1 �϶� : ��&�� ������Ʈ
			// dir==1, dir==2 �϶� : ��&�� ������Ʈ
			// dir==2, dir==3 �϶� : ��&�� ������Ʈ
			// dir==3, dir==0 �϶� : ��&�� ������Ʈ
			update(dir, y, x); 
			update((dir + 1)%4, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}
	}
	// dir[0] == ��, dir[1]==��, dir[2] ==��, dir[3]==��

	else if (cctv_type == 4) {// ���¿�, ������, ���¿�, ���Ͽ� �� ���� ����
		for (int dir = 0; dir < 4; dir++) {// 3���� ���� ������Ʈ �ؾ��Ѵ�.
			// dir==0, dir==1, dir==2 �϶� : ��&��&�� ������Ʈ
			// dir==1, dir==2, dir==3 �϶� : ��&��&�� ������Ʈ
			// dir==2, dir==3, dir==0 �϶� : ��&��&�� ������Ʈ
			// dir==3, dir==0, dir==1 �϶� : ��&��&�� ������Ʈ
			update(dir, y, x);
			update((dir+1)%4, y, x);
			update((dir+2)%4, y, x);
			dfs(cctv_idx + 1);
			memcpy(map, backup, sizeof(map));
		}

	}
	else { // �����¿�� ���� ����
		// 4���� ���� ������Ʈ �ؾ��Ѵ�.
		for (int dir = 0; dir < 4; dir++) {
			update(dir, y, x);
		}
		dfs(cctv_idx + 1); 		
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
				cctv[cctv_size].y = j;
				cctv[cctv_size].x = i;
				cctv[cctv_size].type = map[i][j];
				cctv_size++;
			}
		}
	}
	dfs(0);
	cout << res;
}