#include<iostream>
#include<queue>
#include<string.h>
#define MAX 51
using namespace std;
int map[MAX][MAX]; // 0: ��ĭ, 1: �� , -1:û���� ĭ
bool clean[MAX][MAX];
int dy[4] = { -1,0,1,0 }; // 0 :����, 1:���� 2:���� 3:����
int dx[4] = { 0,1,0,-1 };
int n, m;
int r, c, d;
int result;

void bfs(int y, int x) {
	// ���� ��ġ û��
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
		bool canClean = false; // û�Ұ����� ���� �ִ��� Ȯ��
		for (int k = 0; k < 4; k++) { // 4���� Ž��
			d = (d + 3) % 4; // ���� ���⿡�� ������ ����
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !clean[ny][nx]) {
				if (map[ny][nx] == 0) { // ���� ���⿡ û������ ���� ������ �����Ѵٸ� �ش�������� ����
					result++;
					map[ny][nx] = -1;// û�Ҹ� ����
					clean[ny][nx] = true; 
					canClean = true;
					q.push({ ny,nx });
					break;
				}
				else { // ���� ���⿡ û���� ������ ���� -> �� ���ʹ������� ���ư��� ��
					continue;
				}
			}
		}
		if (!canClean) { //û�Ҹ� ���ߴٸ� ���� �������� Ȯ��			 
			int back = (d + 2) % 4; 
			int back_y = y + dy[back];
			int back_x = x + dx[back];
			if (0 <= back_y && back_y < n && 0 <= back_x && back_x < m) {
				if (map[back_y][back_x] != 1) { // ���� �ƴ϶��, ���� ����
					q.push({ back_y,back_x });
					if (map[back_y][back_x] == 0 && !clean[back_y][back_x]) {
						clean[back_y][back_x] = true;
						result++;
					}
				}
				else { // ������ �Ұ��� --> �۵��� ����
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
	cin >> r >> c >> d; // �κ��� y��ǥ, x��ǥ, ���� 
	// 0 :����, 1:���� 2:���� 3:����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bfs(r, c);
}