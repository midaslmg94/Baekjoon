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
int dx[4] = { 0,0,-1,1 }; // �����¿�
int n;
char map[MAX][MAX];
int visit[MAX][MAX][4]; // i,j���� ���� k�� �������� ������ ��, ���ݱ��� ��ġ�� ���� ����

pair<int, int>startDoor;
pair<int, int>endDoor;
queue<mirror>q;
pair<int, int> changeDir(int cur) { // ���� ������ ���⿡ ���� �ſ￡ �ε������� ���̴� �� �ٸ���.(2���� ������ �ſ￡ �ε���)
	pair<int, int>res;
	if (cur == 0 || cur == 1) { // ���� �����̳� �Ʒ��ʿ��� ���� --> ���� �����̳� ���������� ����
		res.first = 2; // �������� ������ ���� �ְ�
		res.second = 3; // ���������� ������ ���� ����
	}
	else if (cur == 2 || cur == 3) { // ���� �����̳� �Ʒ��ʿ��� ���� --> ���� �����̳� �Ʒ������� ����
		res.first = 0; // ���� ������ ���� �ְ�
		res.second = 1;  // �Ʒ��� ������ ���� ����
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

		if (0 > ny || ny >= n || 0 > nx || nx >= n)continue; // ���� �ʰ�
		if (map[ny][nx] == '*') continue; // �� �� ��� : ����Ұ�
		else if (map[ny][nx] == '!') { // �ſ��� ���
			if (visit[ny][nx][dir] > visit[y][x][dir]) { // �ش���ġ�� �ſ��� ��ġ���� �ʰ� ����
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}			
			// �Ʒ� 2���� if�� �����ϴ°� ���� �������.
			// else if�� �ƴ� if�� ����ؾ��� --> �ſ��� 2���� ���¸� ���� �� �ֱ� ����
			if (visit[ny][nx][ndir.first] > visit[y][x][dir] + 1) {// �ش���ġ�� �ſ��� ��ġ�ϰ� ����
				visit[ny][nx][ndir.first] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.first });
			}
			if (visit[ny][nx][ndir.second] > visit[y][x][dir] + 1) {
				visit[ny][nx][ndir.second] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.second});
			}			
		}
		else if (map[ny][nx] == '.') { // �� ���� ��� : ������ ���� �� ������� ����
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}
		}
		else if (map[ny][nx] == '#') { // �� �� ��� : ���� �����̹Ƿ�, �ش� �������� ������ ���� ���Ͽ� �ּڰ� ����
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
				if (flag) { // �����ϴ� ��
					startDoor.first = i;
					startDoor.second = j;
					flag = false;
				}
				else {// �����ϴ� ��
					endDoor.first = i;
					endDoor.second = j;
				}					
			}
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}

	for (int i = 0; i < 4; i++) {// ó�� ���������� ����
		q.push({ startDoor.first,startDoor.second,i });
		visit[startDoor.first][startDoor.second][i] = 0;
	}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++) { // ������ �������� 4�������� ���� ��� �� �ּڰ� ���
		if (result > visit[endDoor.first][endDoor.second][i]) {
			result = visit[endDoor.first][endDoor.second][i];
		}
	}
	cout << result;
	return 0;
}