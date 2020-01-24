#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
char arr[12][6];
bool visit[12][6];
int chain = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void tmp_print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void move() { // �������� �߷¿� ���� �ѿ䰡 ������ �̵�
	for (int i = 11; i >= 0; i--) {
		for (int j = 5; j >= 0; j--) {
			int dist = 0;
			if (arr[i][j] == '.') {// ����(y��) �ö󰡸鼭 ���ִ� �ѿ䰡 �ִ��� Ȯ��
				for (int k = i; k >= 0; k--) {
					if (arr[k][j] == '.') {
						dist++;
					}
					else {
						// �ؿ��� ���� ������ �Ÿ���ŭ �ѿ並 ������ �̵�
						while (dist--) {
							arr[k + 1][j] = arr[k][j];
							arr[k][j] = '.'; // �̺κ� ������ �� ������
							k++;
						}
						break;
					}
				}
			}
		}
	}
}
void explode() { // 4���̻��� ��� �ѿ䰡 ����
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j] == true) { // �湮���η� Ȯ��
				arr[i][j] = '.';
			}
		}
	}
}

int bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	char color = arr[y][x];
	int cnt = 1; // ��� �ѿ䰡 ����Ǿ� �ִ���
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			char new_color = arr[ny][nx];
			// ������ �ѿ䰡 ���� �ȿ� �ְ�, �湮�� ���߾���� �ϰ�, color�� ���ƾ� ��
			if (0 <= nx && nx < 6 && 0 <= ny && ny < 12 && !visit[ny][nx] && new_color == color) {
				visit[ny][nx] = true;
				q.push({ ny,nx });
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	bool is_explode = true;
	while (is_explode) {
		int puyo = 0; // ����� �ѿ��� ����
		is_explode = false; // ������ �߻����� �ʱ�ȭ
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visit[i][j]) {
					puyo = bfs(i, j);
					//cout << "color:" << arr[i][j] << " puyo cnt:" << puyo << endl;
					if (puyo >= 4) { // 4���̻� �ѿ䰡 �����ִ� --> ����
						explode();
						//tmp_print(); 	cout << endl<<chain<<endl;
						is_explode = true; // ���� �߻�
					}
				}
			memset(visit, false, sizeof(visit));
			}
		}
		//���� �� �ִ� �ѿ䰡 ���� �׷��� �ִٸ� ���ÿ� ������ �ϰ� ���� �׷��� �������� �ѹ��� ���Ⱑ �߰��ȴ�.
		if(is_explode)
			chain++;
		
		move(); // ���ִ� �ѿ���� ������ ������
	}
	// �ϳ��� ������ �ʴ´ٸ� 0�� ����ؾ��Ѵ�
	cout << chain;
}