#include<bits/stdc++.h>
#define endl "\n"
#define MAX 101
#define INF 9876
using namespace std;
struct INFO {
	int y; // y��ǥ
	int x; // x��ǥ
	bool isSword; // �� ȹ�� ����
};

struct VISIT {
	int take_time; // �ش���ġ���� ���µ� �ɸ� �ð�
	bool isSword; // �� ȹ�� ����
};
int n, m, limit_time;
int castle[MAX][MAX];
VISIT visit[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int res = INF;
void prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j].take_time << ' ';
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}
int bfs(int y, int x, bool sword) {
	queue<INFO>q;
	q.push({ y, x, sword });
	visit[y][x].take_time = 0;
	visit[y][x].isSword = false;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		sword = q.front().isSword;
		q.pop();
		prt();
		if (y == n - 1 && x == m - 1) { // ���ָ� ã��
			if (visit[y][x].take_time <= limit_time)
				return visit[y][x].take_time;
			else
				return INF;
		}
		//cout << " y:" << y << " x:" << x << " sword:" << sword << endl;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
			if (visit[ny][nx].take_time != 0)continue;

			if (sword == true) { // ���� Į�� ���� ����
				if (castle[ny][nx] == 0 || castle[ny][nx] == 1) {
					visit[ny][nx].take_time = visit[y][x].take_time + 1;
					visit[ny][nx].isSword = true;
					q.push({ ny,nx,true });
				}
			}
			else { // ���� Į�� ����
				if (castle[ny][nx] == 0) {
					visit[ny][nx].take_time = visit[y][x].take_time + 1;
					q.push({ ny,nx,visit[ny][nx].isSword });
				}
				else if (castle[ny][nx] == 1) { // ����
					continue;
				}
				else { // Į�� ã��
					visit[ny][nx].take_time = visit[y][x].take_time + 1;
					visit[ny][nx].isSword = true;
					q.push({ ny,nx,true });
				}
			}
		}
	}
	return INF;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> limit_time;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castle[i][j];
			visit[i][j].isSword = false;
			visit[i][j].take_time = 0;
		}
	}
	int answer = min(res, bfs(0, 0, false));
	if (answer == INF) {
		cout << "Fail";
	}
	else {
		cout << answer;
	}
	return 0;
}