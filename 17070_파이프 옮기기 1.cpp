#include<iostream>
#include<queue>
#include<vector>
#define MAX 17
using namespace std;
int n;
// 0:��ĭ, 1:��
int arr[MAX][MAX];
int cnt = 0;
//int ny, nx;
void hori(int y, int x);
void verti(int y, int x);
void diag(int y, int x);

void hori(int y, int x) { // ���� ���� : ����
	// ���η� �̵�
	int h_ny = y;
	int h_nx = x + 1;

	// �밢������ �̵�
	int d_ny = y + 1;
	int d_nx = x + 1;

	// ����
	if (h_ny <= n && h_nx <= n && arr[h_ny][h_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (h_ny == n && h_nx == n) {
			cnt++;
			return;
		}
		hori(h_ny, h_nx);
	}

	// �밢��
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (d_ny == n && d_nx == n) {
			cnt++;
			return;
		}
		diag(d_ny, d_nx);
	}

}
void verti(int y, int x) { // ���� ���� : ����
	// ���η� �̵�
	int v_ny = y + 1;
	int v_nx = x;

	// �밢������ �̵�
	int d_ny = y + 1;
	int d_nx = x + 1;

	// ����
	if (v_ny <= n && v_nx <= n && arr[v_ny][v_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (v_ny == n && v_nx == n) {
			cnt++;
			return;
		}
		verti(v_ny, v_nx);
	}

	// �밢��
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (d_ny == n && d_nx == n) {
			cnt++;
			return;
		}
		diag(d_ny, d_nx);
	}
}

void diag(int y, int x) { // ���� ���� : �밢��
	// ���η� �̵�
	int h_ny = y;
	int h_nx = x + 1;


	// ���η� �̵�
	int v_ny = y + 1;
	int v_nx = x;

	// �밢������ �̵�
	int d_ny = y + 1;
	int d_nx = x + 1;

	// ����
	if (h_ny <= n && h_nx <= n && arr[h_ny][h_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (h_ny == n && h_nx == n) {
			cnt++;
			return;
		}
		hori(h_ny, h_nx);
	}

	// ����
	if (v_ny <= n && v_nx <= n && arr[v_ny][v_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (v_ny == n && v_nx == n) {
			cnt++;
			return;
		}
		verti(v_ny, v_nx);
	}
	// �밢��
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//�������� �����ߴ��� Ȯ��
		if (d_ny == n && d_nx == n) {
			cnt++;
			return;
		}
		diag(d_ny, d_nx);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	/*
		���� ���⿡���� ������ ������ ����� �ٸ�
		1. ���� --> ���� or �밢��
		2. �밢�� --> ���� or �밢�� or ����
		3. ���� --> ���� or �밢��
	*/
	hori(1, 2); // ���κ�
	cout << cnt;


}