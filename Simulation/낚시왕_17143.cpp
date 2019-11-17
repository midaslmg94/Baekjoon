#include<iostream>
#include<vector>
using namespace std;
const int MAX = 100;
int R, C, M = 0; //������ ũ��, ����
vector<pair<int, pair<int, int>>>shark[MAX][MAX]; // ũ��, (�̵�����, �ӷ�)
int check[MAX][MAX]; //������ ������ �ƴ��� Ȯ��
int sum = 0; // ����� ������

void catchShark(int cur) {
	for (int i = 0; i < R; i++) {
		if (shark[i][cur].front().first > 0) {
			sum += shark[i][cur].front().first;
			shark[i][cur].front().first = 0;
			shark[i][cur].front().second.first = 0;
			shark[i][cur].front().second.second = 0;
			break;
		}
	}
	return;
}
void moveShark() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//s�� d�� Ȯ���Ͽ� �̵�����, �Ÿ� Ȯ��
			if (shark[i][j].front().first != 0 && check[i][j] == 0) {
				int x = i;
				int y = j;
				int size = shark[i][j].front().first; //ũ��
				int dir = shark[i][j].front().second.first; //�̵�����
				int dist = shark[i][j].front().second.second; //�̵��Ÿ�
				/* �� ������
				d�� 1�� ���� ��, 	2�� ���� �Ʒ�,
				3�� ���� ������, 4�� ���� ������ �ǹ��Ѵ�.*/
				cout << "�̵� �� ũ��: " << size << " ��ġ" << x << "," << y << " ����" << dir << " �Ÿ�" << dist << "\n";
				for (int k = 0; k < dist; k++) {
					if (dir == 1) {//���� �� , ���� �ε����� dir = 2
						x = x - 1;
						if (x == 0) { dir = 2; }
					}
					else if (dir == 2) {//�Ʒ��� ��, ���� �ε����� dir = 1
						x = x + 1;
						if (x == R - 1) { dir = 1; }
					}
					else if (dir == 3) {//���������� ��, ���� �ε����� dir = 4
						y = y + 1;
						if (y == C - 1) { dir = 4; }
					}
					else if (dir == 4) {//�������� ��, ���� �ε����� dir = 3
						y = y - 1;
						if (y == 0) { dir = 3; }
					}
				}
				cout << "�̵� �� ũ��: " << size << " ��ġ" << x << "," << y << " ����" << dir << " �Ÿ�" << dist << "\n";
				// ���� ĭ�� �� ������ 
				if (shark[x][y].front().first != 0) {
					if (size > shark[x][y].front().first) {// x, y�� �ִ� �� �� ����. ���� 
						shark[x][y].front().first = shark[i][j].front().first;
						shark[x][y].front().second.first = shark[i][j].front().second.first;
						shark[x][y].front().second.second = shark[i][j].front().second.second;
					}
				}
				// ���� ĭ�� �� ������
				else if (shark[x][y].front().first == 0) {
					shark[x][y].front().first = shark[i][j].front().first;
					shark[x][y].front().second.first = shark[i][j].front().second.first;
					shark[x][y].front().second.second = shark[i][j].front().second.second;
				}
				//�����̱� ����(i,j)�� �ִ� ���� 0���� �ٲ�
				cout << "�ο� �� ũ��: " << size << " ��ġ" << x << "," << y << " ����" << dir << " �Ÿ�" << dist << "\n";
				shark[i][j].front().first = 0;
				shark[i][j].front().second.first = 0;
				shark[i][j].front().second.second = 0;
				check[x][y] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*
		(r, c)�� ����� ��ġ, s�� �ӷ�, d�� �̵� ����, z�� ũ���̴�.
		d�� 1�� ���� ��, 	2�� ���� �Ʒ�,
		3�� ���� ������, 4�� ���� ������ �ǹ��Ѵ�.
	*/
	cin >> R >> C >> M;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			shark[i][j].push_back(make_pair(0, make_pair(0, 0)));
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[r - 1][c - 1].front().first = z;
		shark[r - 1][c - 1].front().second.first = d;
		shark[r - 1][c - 1].front().second.second = s;
	}


	for (int j = 0; j < C; j++) {
		cout << endl;
		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				printf("%d ", shark[a][b].front().first);
			}
			cout << endl;
		}
		catchShark(j);
		moveShark();
	}
	cout << sum;
}