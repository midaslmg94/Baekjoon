#include<iostream>
#include<string>
#include<queue>
using namespace std;
int r, c;
char mineral[111][111];
bool cluster[111][111];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// �¿�� �����̸� c�� ����, x��
	// ���Ϸ� �����̸� r�� ����, y��
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mineral[i][j];
		}
	}
	int n;
	cin >> n; // ���븦 ���� Ƚ��
	bool left = true; // ���ʺ��� ����
	/*����� ������ �̳׶� �ı�*/
	while (n--) {
		int height;
		cin >> height;
		height = r - height + 1;
		// ���� �̳׶� �ı�
		if (left == true) {
			for (int i = 1; i <= c; i++) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		// ������ �̳׶� �ı�
		else {
			for (int i = c; i >= 1; i--) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		left = !left;
		/*Ŭ������ Ȯ��*/
		memset(cluster, false, sizeof(cluster));
		for (int j = 1; j <= c; j++) {
			if (mineral[r][j] == 'x') { // �� �عٴڿ� �̳׶��ִ��� Ȯ��
				queue<pair<int, int>>q;
				q.push(make_pair(r, j)); // �ֺ��� Ŭ�����͸� Ȯ���ϱ� ����
				cluster[r][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (1 <= nx && nx <= c && 1 <= ny && ny <= r) {
							if (cluster[nx][ny] == false && mineral[nx][ny] == 'x') {
								cluster[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
		/*�ؿ��� ���� Ȯ��*/
		int down = r;
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (mineral[i][j] == 'x' && cluster[i][j] == false) {
					int col_down = r - i;

				}
			}
		}
	}


}