#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define MAX 1000
#define INF 99
using namespace std;
struct INFO
{
	int dist;
	bool isBreak;
};

int n, m;
int map[MAX][MAX];//  �Է¹��� ����
INFO dist[MAX][MAX];// �Ÿ�
bool visit[MAX][MAX];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

void bfs(int y, int x, bool flag) {//(0,0)���ͽ���	
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	dist[y][x].dist = 1;
	dist[y][x].isBreak = flag;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		flag = dist[y][x].isBreak;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = dy[k] + y;
			int nx = dx[k] + x;
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx]) {
				if (map[ny][nx] == 1 && flag == true)// ���̸鼭, �ν���
					continue;
				if (map[ny][nx] == 1 && flag == false) { // ��������, ���� �Ⱥν�
					dist[ny][nx].dist = min(dist[ny][nx].dist,dist[y][x].dist + 1);
					dist[ny][nx].isBreak = true;					
				}
				if(map[ny][nx] == 0) { // ���
					dist[ny][nx].dist = min(dist[ny][nx].dist, dist[y][x].dist + 1);
					dist[ny][nx].isBreak = flag;
				}				
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dist[i][j].dist << ' ';
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << dist[i][j].isBreak << ' ';
			}
			cout << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		string str; // �Է��� ������� ����
		cin >> str;
		for (int j = 0; j < m; j++) {
			tmp = str[j] - '0';
			map[i][j] = tmp;
			dist[i][j].dist = INF;
			dist[i][j].isBreak = false;
		}
	}

	bfs(0, 0, false);
	if (dist[n - 1][m - 1].dist == INF)
		cout << -1;
	else
		cout << dist[n - 1][m - 1].dist;
}