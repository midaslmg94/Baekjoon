#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int map[500][500];
bool visit[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int max_cnt = 1;	 // �׸��� �ִ� ����
int pic_cnt = 1; // �׸��� ���� ����
int cnt = 0; // �׸��� ����
bool is_picture = false;
void bfs(int x, int y) {
	queue<pair<int,int>>q; // ť�� i�� j�� �ִ´�
	q.push({ x,y });
	visit[x][y] = true;
	pic_cnt = 0;
	is_picture = false;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		is_picture = true; // ť�� ���� ���� �׸���
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) { // �̵� ����
				if (map[nx][ny] == 1 && visit[nx][ny] == false) { // �׸� ����
					q.push({ nx, ny });
					visit[nx][ny] = true;
					if (pic_cnt == 0) { // �׸��� ���� ��� 0�� ����ؾ� �ϹǷ� �׸��� ������� ��� 1 1 �̸� 2���� �ȴ�.
						pic_cnt = 1;
					}
					pic_cnt++;					
				}
			}
		}
	}
	max_cnt = max(max_cnt, pic_cnt);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				bfs(i,j);
				if (is_picture) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	if (cnt == 0) {
		max_cnt = 0;
	}
	cout << max_cnt << endl;

}
