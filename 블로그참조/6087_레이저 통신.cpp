#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 100
#define INF 987654231
using namespace std;
int dy[4] = {-1,1,0,0}; // �����¿�
int dx[4] = { 0,0,-1,1 };

struct mirror
{
	int y;
	int x;
	int dir;
};
int n, m;
char map[MAX][MAX];
int visit[MAX][MAX][4]; // ���� �������� ���⺰�� �ſ��� ��ġ�� ����
pair<int, int> start_pos, end_pos;
queue<mirror>q;


pair<int, int> changeDir(int dir) {
	pair<int, int> result;
	if (dir == 0 || dir == 1) { // �������� ����or�Ʒ��ʿ��� ������ ����or���������� ����
		result.first = 2;
		result.second = 3;
	}
	else { // �������� ����or�����ʿ��� ������ ����or�Ʒ������� ����
		result.first = 0;
		result.second = 1;
	}
	return result;
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		pair<int,int> ndir = changeDir(dir);
		q.pop();
		if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
		if (map[ny][nx] == '*')continue;

		if (map[ny][nx] == '.') {
			// �ſ��� ��ġ ���Ѵ� --> ������ �ȹٲ�
			if (visit[ny][nx][dir] > visit[y][x][dir]) { // �ش���ġ�� �ſ��� ��ġ���� �ʰ� ����
				visit[ny][nx][dir] = visit[y][x][dir];
				q.push({ ny,nx,dir });
			}
			// �ſ��� ��ġ �Ѵ� --> ������ �ٲ�
			if (visit[ny][nx][ndir.first] > visit[y][x][dir] + 1) {// �ش���ġ�� �ſ��� ��ġ�ϰ� ����
				visit[ny][nx][ndir.first] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.first });
			}
			if (visit[ny][nx][ndir.second] > visit[y][x][dir] + 1) {
				visit[ny][nx][ndir.second] = visit[y][x][dir] + 1;
				q.push({ ny,nx,ndir.second });
			}
		}
		else if (map[ny][nx] == 'C') { // �� �� ��� : ���� �����̹Ƿ�, �ش� �������� ������ ���� ���Ͽ� �ּڰ� ����
			if (visit[ny][nx][dir] > visit[y][x][dir]) {
				visit[ny][nx][dir] = visit[y][x][dir];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> m >> n;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') { 
				if (flag) {
					start_pos.first = i;
					start_pos.second = j;					
					flag = false;
				}
				else {
					end_pos.first = i;
					end_pos.second = j;
				}
			}
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}
	for (int k = 0; k < 4; k++) {
		q.push({ start_pos.first, start_pos.second, k });
		visit[start_pos.first][start_pos.second][k] = 0;
	}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, visit[end_pos.first][end_pos.second][i]);
	}
	cout << result;
	return 0;
}