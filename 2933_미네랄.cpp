#include<iostream>
#include<vector>
using namespace std;
string arr[100];
int r = 0;
int c = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool canGo(int x, int y) {
	bool check = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (c <= nx || nx < 0 || r <= ny || ny < 0) {
			check = false; break;
		}
	}
	return check;
}
void goDown(int x, int y) {
	if (canGo(x, y)) { 

	}
}
int main() {
	// �̳׶� ���� �Է�
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> arr[i];
	}
	int n = 0; // ���븦 ���� Ƚ��
	cin >> n;
	// ���븦 ���� ����, 
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		int height = v[i];
		if (i % 2 == 0) { //¦�� �ε��� : ����->������ ���� ����
			for (int j = 0; j < r; j++) {
				if (arr[r - height][j] == 'x') {
					arr[r - height][j] = '.';
					goDown(r - height, j);
					break;
				}
			}
		}
		else { // Ȧ�� �ε��� : ������->�������� ���� 
			for (int j = 0; j < c; j++) {
				if (arr[r - height][c - j] == 'x') {
					arr[r - height][c - j] = '.';
					goDown(r - height, c - j);
					break;
				}
			}
		}

	}
	for (int i = 0; i < r; i++) {
		cout << arr[i] << "\n";
	}
}