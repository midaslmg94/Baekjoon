#include<iostream>
#include<queue>
using namespace std;
int map[50][50];
bool visit[50][50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int	N, L, R;
/*
	�湮���� �ʱ�ȭ
	���� �������� Ȯ��
		- ���� ������ ��� : ���� ������ ����, ���� ������ �α��� �� Ȯ��
*/

bool is_update = true; // �α��̵��� �߻��ߴ��� Ȯ��
int country;// ������ ����
int people; // �α� ��

struct INFO{
	int y;
	int x;
};

void bfs(int y, int x) {
	visit[y][x] = true;
	queue<INFO>q; // �湮 ��ġ�� ��� ť
	queue<INFO>u; // ���� ������ ��ġ�� ��� ť
	q.push({ y,x });
	u.push({ y,x });
	people = map[y][x];
	country = 1;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;	
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visit[ny][nx]) continue;
			int diff = abs(map[ny][nx]-map[y][x]);
			if (L <= diff && diff <= R) { // �α��̵� ����
				visit[ny][nx] = true;
				q.push({ ny,nx });
				u.push({ ny,nx });
				is_update = true;
				country++;
				people += map[ny][nx];					
			}
		}
	}
	/*���⼭ �α��̵��� �ϸ� �ȵ��� �ʳ�?..*/
	int avg = people / country;
	while (!u.empty()) {
		int y = u.front().y;
		int x = u.front().x;
		u.pop();
		map[y][x] = avg;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j]; 
		}
	}
	int count = 0;
	while (is_update) {
		is_update = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++){
				if (!visit[i][j]) {
					bfs(i, j);				
				}
			}
		}
		/*���� ���ƾ� �ϹǷ� �湮 �迭 �ʱ�ȭ*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		if(is_update)
			count++;
	}
	cout << count;
}