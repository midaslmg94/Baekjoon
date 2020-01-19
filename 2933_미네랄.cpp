#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int r, c, n;
char map[101][101];
bool visit[101][101];
int height[101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool isground = false;
void throwing(int height, bool oper) { // ���� ������
	if (oper) { // ���ʿ��� ����
		for (int j = 1; j <= c; j++) {
			if (map[height][j] == 'x') {
				map[height][j] = '.';
				break;
			}
		}
	}
	else {// �����ʿ��� ����
		for (int j = c; j >= 1; j--) {
			if (map[height][j] == 'x') {
				map[height][j] = '.';
				break;
			}
		}
	}
}
int min_dist = 999999999;
void moving() {//visit�� true�� ���� ��������(�ؿ��� ���� �ȱ�)
	bool flag = false;
	for (int i = r; i >= 1; i--) {
		for (int j = c; j >= 1; j--) {
			if (visit[i][j] == true && map[i][j] == 'x') {
				// ���� ���� �������� ���̰� ������ Ȯ��
				int dist = 0; int cur = i;
				//cout << "cur = " << cur<<" j = "<<j << endl;
				while (cur < r) {
					cur++;
					dist++;
					if (map[cur][j] == 'x') {
						break;
					}
				}
				min_dist = min(dist, min_dist);
				flag = true; // ���߿� ���ִ� Ŭ�������� ���� �� �κ��� üũ
			}
		}
		if (flag) { break; } 
	}
	//cout << "min_dist " << min_dist << endl;
	// min_dist ��ŭ �̳׶� �̵�
	for (int i = r; i >= 1; i--) {
		for (int j = c; j >= 1; j--) {
			if (visit[i][j] == true && map[i][j] == 'x') {
				map[i + min_dist][j] = map[i][j];
				map[i][j] = '.';
			}
		}
	}
	memset(visit, false, sizeof(visit));
}
void bfs(int y, int x) {
	isground = false;
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		//cout << "y : " << y << " x : " << x << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= r && 1 <= nx && nx <= c && !visit[ny][nx] && map[ny][nx] == 'x') {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				if (ny == r) { // �ٴڱ��� �̳׶��� ���� --> ���߿� ������ ����
					isground = true;						
				}
			}
		}
	}
	if (!isground) { // ���Ⱑ �ѹ� �� ��
		moving();
	}
}


void destory(int height, bool oper) {
	throwing(height, oper);//���븦 ����	
	/*for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n\n";*/

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == 'x' && !visit[i][j]) {			
				//cout << "i = " << i << " j = " << j << endl;
				bfs(i, j);// Ŭ������ Ȯ��
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}
	cin >> n;
	bool left = true;
	int height = 0;
	for (int i = 0; i < n; i++) {
		cin >> height;
		destory(r - height + 1, left);// ���̸� �迭�� �ε����� ��ȯ, true:����, false:������
		left = !left;
		memset(visit, false, sizeof(visit));
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}