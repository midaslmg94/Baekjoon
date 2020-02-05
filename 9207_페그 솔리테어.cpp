#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int n;
char map[5][9];
char backup[5][9];
bool visit[5][9];
/*
���� ����, ���� �������� ������ ���� �پ�Ѿ
�� ���� '���� ĭ'���� �̵��ϴ� �͸� ���ȴ�.

������ ���� ���� ĭ�� ����־�� �ϰ� �� ������ ���� ���ŵȴ�.
���� �����ǿ� �����ִ� ���� ���°� �־�����.
�̶�, ���� ������ �������� �����ǿ� �����ִ� ���� ������ �ּҷ� �Ϸ��� �Ѵ�.
��, �׷��� ����� ���� �ʿ��� �ּ� �̵�Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
// '.'�� �� ĭ, 'o'�� ���� �����ִ� ĭ, '#'�� ������ ���� ĭ
int dy[4] = { 0,0,-1,1 }; // dir[0] = ������, dir[1] = ����, dir[2] = ����, dir[3] = �Ʒ���
int dx[4] = { 1,-1,0,0 };
int move_cnt = 0;
queue<pair<pair<int, int>, int>>pin;
int bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({  y,x }); // �������� ��ǥ, � �������� ����Ǿ� �ִ���
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;		
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < 5 && 0 <= nx && nx < 9 && !visit[ny][nx] && backup[ny][nx]=='o') { // �����¿� �� ������ ���� ������
				q.push({ ny, nx });
				visit[ny][nx] = true;
				int dir = k; // dir[0] = ������, dir[1] = ����, dir[2] = ����, dir[3] = �Ʒ���
				dfs(ny, nx, dir); // �ش� �������� ���� �����̸� ��Ʈ��ŷ
			}
		}
	}
}

void dfs(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if(0 <= ny && ny < 5 && 0 <= nx && nx < 9 && backup[ny][nx] == '.') { // �Ѿ�� ������ ��ĭ�̾�� ��
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
					move_cnt=bfs(i, j); // ���� ����� �� ã��
					res = min(res, move_cnt);
				}
			}
		}		
		memset(visit, false, sizeof(visit));
	}
	cout << res;
}