#include<iostream>
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
vector<INFO>shark[MAX][MAX];

int R, C, M;// ����, ����, ��� ��

void catchShark(int pos) { //  ���ÿ��� �� ����
	for (int i = 1; i <= R; i++) {
		if (shark[i][pos].size()) {// �� ������
			sum += shark[i][pos][0].size;
			shark[i][pos].clear();
			break;
		}
	}
}
void moveShark() { // �� ������
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			
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
		shark[r][c].push_back({ s, d, z });
	}
	for (int i = 1; i <= C; i++) {
		int pos = i; // ���ÿ��� ��ġ
		catchShark(pos);
		moveShark();
	}
	cout << sum;
}