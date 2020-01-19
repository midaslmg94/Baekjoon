//https://luvery93.github.io/articles/2018-11/boj-2933 ����

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int r, c;
char mineral[111][111];
bool cluster[111][111]; // �� �ڵ忡�� visit
int dx[4] = { -1, 1 , 0 , 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mineral[i][j];
		}
	}
	int n;
	cin >> n;
	bool left = true;
	while (n--) {
		int height;
		cin >> height;
		height = r - height + 1;
		if (left) { // ���ʿ��� ����
			for (int j = 1; j <= c; j++) {
				if (mineral[height][j] == 'x') {
					mineral[height][j] = '.';
					break;
				}
			}
		}
		else {// �����ʿ��� ����
			for (int j = c; j >= 1; j--) {
				if (mineral[height][j] == 'x') {
					mineral[height][j] = '.';
					break;
				}
			}
		}
		left = !left;


		//check
		memset(cluster, false, sizeof(cluster));
		for (int j = 1; j <= c; j++) { // �� �غκи� bfs Ž������. �� j�� bfs ó��?
			if (mineral[r][j] == 'x') {
				queue<pair<int, int>>q;
				q.push({ r,j });
				cluster[r][j] = true;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (1 <= ny && ny <= r && 1 <= nx && nx <= c && !cluster[ny][nx] && mineral[ny][nx] == 'x') {
							cluster[ny][nx] = true;
							q.push({ ny, nx });
						}
					}
				}
			}
		}

		// down : ���ذ� �� �Ȱ���.
		int down = r;
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (mineral[i][j] == 'x' && cluster[i][j] == false) { // �ؿ��� ���� �ö�
					int col_down = r - i;
					for (int k = i + 1; k <= r; k++) {
						if (cluster[k][j] == true) {
							col_down = k - i - 1;
							break;
						}
					}
					if (down > col_down) {
						down = col_down;
					}
				}
			}
		}

		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (i + down <= r && down != 0 && mineral[i][j] == 'x' && cluster[i][j] == false) {
					mineral[i + down][j] = mineral[i][j];
					mineral[i][j] = '.';
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << mineral[i][j];
		}
		cout << '\n';
	}

}