#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	ù°�� �Է�
		������ �ʺ� : w
		������ ���� : h
	��°�� �Է�
		������ �־���, 1:��, 0:�ٴ�
	�Է��� ������ �� : 0�� 2���־���

	��� : ���� ������ ���
	�����¿�밢������ ������ ����
*/
vector<vector<int>> map;
int visit[50][50];
int dx[8] = { 0, 0, 1, -1,-1, -1,  1, 1 };
int dy[8] = { 1,-1,0,  0, -1,  1, -1, 1 };

int bfs(int x, int y, int w, int h) {
	int island = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w)
			{
				if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
					island++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return island;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> tmp1;
	vector<int> answer;
	int w; int h;
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) { break; }
		int n;
		/*�׽�Ʈ ���̽� �Է�*/
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> n;
				tmp1.push_back(n);
			}
			map.push_back(tmp1);
			tmp1.clear();
		}
		/*���� ������*/
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j, w, h);
				}
			}
		}
		map.clear();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}