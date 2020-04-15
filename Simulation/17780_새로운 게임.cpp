#include<bits/stdc++.h>
#define endl "\n"
#define MAX 14
using namespace std;
struct CHESS { // ü������ ����
	int y;
	int x;
	int dir;
	bool bottom;
};
int N, K;
int turn = 0;
int board[MAX][MAX]; // ü������ ����
vector<CHESS>chess;  // 0����~ n-1������ ����
vector<int>v[MAX][MAX]; // ü������ ���� v[i][j] = {0,2}�̸� [i][j]��ġ�� 0��, 2�� ���� ������� �ִٴ� �ǹ�. v[i][j][0]�� �� ���� ��
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
int changeDir(int n) {
	if (n == 1)return 2;
	if (n == 2)return 1;
	if (n == 3)return 4;
	if (n == 4)return 3;
}
bool isFinish() { // �� �ڸ��� ���� 4�� �̻� ���ִ��� Ȯ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j].size() >= 4)return true;
		}
	}
	return false;
}
void moveChess(int y, int x, int ny, int nx) {  // {y,x}���� {ny,nx}�� ���� ���� �ű�
	for (int i = 0; i < v[y][x].size(); i++) {
		v[ny][nx].push_back(v[y][x][i]);
		chess[v[y][x][i]].y = ny;
		chess[v[y][x][i]].x = nx;
	}
	int num = v[ny][nx][0]; // �� ���� ���� true�� ���ش�
	chess[num].bottom = true;
	for (int i = 1; i < v[ny][nx].size(); i++) {
		num = v[ny][nx][i];
		chess[num].bottom = false;
	}
	v[y][x].clear(); // �̵� �� ���� �����
}
void moveReverse(int y, int x, int ny, int nx) {  // ������ �ٲ� -> �� �ں��� push_back(������ �ִ� ���� ������ ������ ����)
	for (int i = v[y][x].size() - 1; i >= 0; i--) {
		v[ny][nx].push_back(v[y][x][i]);
		chess[v[y][x][i]].y = ny;
		chess[v[y][x][i]].x = nx;
	}
	int num = v[ny][nx][0]; // �� ���� ���� true�� ���ش�
	chess[num].bottom = true;
	for (int i = 1; i < v[ny][nx].size(); i++) {
		num = v[ny][nx][i];
		chess[num].bottom = false;
	}
	v[y][x].clear();
}

void prt() {
	for (int i = 0; i < K; i++) {
		cout << " turn:" << turn << " idx:" << i << " y:" << chess[i].y << " x:" << chess[i].x 
			<< " dir:" << chess[i].dir 
			<<" isBottom:"<<chess[i].bottom<< endl;
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		y--; x--;
		chess.push_back({ y,x,dir,true });
		v[y][x].push_back(i);
	}
	while (true) {		
		turn++;
		for (int i = 0; i < K; i++) { // 0�� ������ ����
			int y = chess[i].y;
			int x = chess[i].x;
			int dir = chess[i].dir;
			int isBottom = chess[i].bottom;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			//prt(); cout << "-----" << endl;
			if (!isBottom)continue; // �� ���� �ƴϸ� �̵��Ұ�
			if (0 > ny || ny >= N || 0 > nx || nx >= N) { // ���� �ʰ� -> �Ķ����� �Ȱ��� ����				 
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir = ndir;
				if (0 > ny || ny >= N || 0 > nx || nx >= N) continue; // ���� �ʰ� -> ���⸸ �ٲ�� ��ǥ�� �״��				
				if (board[ny][nx] == 0) { // ��� : �׳� ����
					moveChess(y, x, ny, nx);
				}
				else if (board[ny][nx] == 1) { // ������ : ���� ������ �ٲٰ� ����
					moveReverse(y, x, ny, nx);
				}
				else if (board[ny][nx] == 2)continue; // �����Ϸ��� ������ �� �Ķ����̸� ���⸸ �ٲ�				
			}
			else if (board[ny][nx] == 0) { // ��� : �׳� ����
				moveChess(y, x, ny, nx);
			}
			else if (board[ny][nx] == 1) { // ������ : ���� ������ �ٲٰ� ����
				moveReverse(y, x, ny, nx);
			}
			else { // �Ķ��� : ���� �ٲٰ� 1ĭ ���� 
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir = ndir;
				if (0 > ny || ny >= N || 0 > nx || nx >= N) continue; // ���� �ʰ� -> ���⸸ �ٲ�� ��ǥ�� �״��				
				if (board[ny][nx] == 0) { // ��� : �׳� ����
					moveChess(y, x, ny, nx);
				}
				else if (board[ny][nx] == 1) { // ������ : ���� ������ �ٲٰ� ����
					moveReverse(y, x, ny, nx);
				}
				else if (board[ny][nx] == 2)continue; // �����Ϸ��� ������ �� �Ķ����̸� ���⸸ �ٲ�				
			}

			// �� �ڸ��� ���� �� ���ִ��� Ȯ��
			if (isFinish()) { // ���� ���� ������
				cout << turn;
				return 0;
			}
		}
		
		if (turn > 1000) { // ���ѽð� �ʰ�
			cout << -1;
			return 0;
		}
	}
}