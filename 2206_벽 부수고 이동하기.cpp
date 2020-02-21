#include<iostream>
#include<queue>
#include<string.h>
#define MAX 1000
using namespace std;
struct INFO
{
	int y;
	int x;
	int block;
	int dist;
};
int n, m;
int map[MAX][MAX];//  �Է¹��� ����
bool visit[MAX][MAX]; //  ���� �μ����� �ִ���
bool is_finish = false; // ���� ��ΰ� �ϳ��� �ִٸ�
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int bfs(int y, int x) {//(0,0)���ͽ���	
	queue<INFO>q;
	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = dy[k] + y;
			int nx = dx[k] + x;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && backup[ny][nx] == 0 && !visit[ny][nx]) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				dist[ny][nx] += dist[y][x];
				if (ny == n - 1 && nx == m - 1) {//������ ����
					is_finish = true;
					return dist[ny][nx];
				}
			}
		}
	}
	// ���� ����
	if (!is_finish) {
		return 987654321;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	queue<pair<int, int>>wall;
	int tmp;
	for (int i = 0; i < n; i++) {
		string str; // �Է��� ������� ����
		cin >> str;
		for (int j = 0; j < m; j++) {
			tmp = str[j] - '0';
			map[i][j] = tmp;
			if (tmp == 1) {
				wall.push({ i,j });
			}
		}
	}
	int result = 987564;
	bfs(0, 0);
	cout << result;
}