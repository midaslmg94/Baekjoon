#include<iostream>
#include<string.h>
#include<vector>
#define MAX 101
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int sum; // ��������� �� ũ��
struct INFO {
	int speed;
	int dir;
	int size;
};
INFO shark[MAX][MAX];
vector<bool>visit[MAX][MAX];
int R, C, M;// ����, ����, ��� ��

void catchShark(int pos) { //  ���ÿ��� �� ����
	for (int i = 1; i <= R; i++) {
		if (shark[i][pos].size) {// �� ������
			sum += shark[i][pos].size;
			shark[i][pos] = { 0,0,0 };
			return;
		}
	}
}
void moveShark() { // �� ������, ������ �� üũ
	// ���� ������ 2���� �̻��� �� ���� �� ó��
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (shark[i][j].size) {//�� ������
				// ��輱�� �ִ� ����� ���, �ݴ������� ������ ������

				// �� ������
				int cur_dir = shark[i][j].dir;
				int cur_speed = shark[i][j].speed;
				if (cur_dir == 1) { // R�� ����
					
				}
				else if(cur_dir == 2) { // R�� ����

				}
				else if (cur_dir == 3) { // C�� ����

				}
				else { // C�� ����

				}
			}

		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);

	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z; // d�� 1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4�� ���� ����
		shark[r][c].speed = s;
		shark[r][c].dir = d;
		shark[r][c].size = z;		
	}
	for (int i = 1; i <= C; i++) {
		int pos = i; // ���ÿ��� ��ġ
		catchShark(pos);
		moveShark();
		memset(visit, false, sizeof(visit));
		
	}


	cout << sum;
}