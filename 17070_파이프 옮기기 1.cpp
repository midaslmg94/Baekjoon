#include<iostream>
#include<queue>
#include<vector>
#define MAX 17
using namespace std;
int n;
// 0:빈칸, 1:벽
int arr[MAX][MAX];
int cnt = 0;
//int ny, nx;
void hori(int y, int x);
void verti(int y, int x);
void diag(int y, int x);

void hori(int y, int x) { // 현재 상태 : 가로
	// 가로로 이동
	int h_ny = y;
	int h_nx = x + 1;

	// 대각선으로 이동
	int d_ny = y + 1;
	int d_nx = x + 1;

	// 가로
	if (h_ny <= n && h_nx <= n && arr[h_ny][h_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (h_ny == n && h_nx == n) {
			cnt++;
			return;
		}
		hori(h_ny, h_nx);
	}

	// 대각선
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (d_ny == n && d_nx == n) {
			cnt++;
			return;
		}
		diag(d_ny, d_nx);
	}

}
void verti(int y, int x) { // 현재 상태 : 세로
	// 세로로 이동
	int v_ny = y + 1;
	int v_nx = x;

	// 대각선으로 이동
	int d_ny = y + 1;
	int d_nx = x + 1;

	// 세로
	if (v_ny <= n && v_nx <= n && arr[v_ny][v_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (v_ny == n && v_nx == n) {
			cnt++;
			return;
		}
		verti(v_ny, v_nx);
	}

	// 대각선
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (d_ny == n && d_nx == n) {
			cnt++;
			return;
		}
		diag(d_ny, d_nx);
	}
}

void diag(int y, int x) { // 현재 상태 : 대각선
	// 가로로 이동
	int h_ny = y;
	int h_nx = x + 1;


	// 세로로 이동
	int v_ny = y + 1;
	int v_nx = x;

	// 대각선으로 이동
	int d_ny = y + 1;
	int d_nx = x + 1;

	// 가로
	if (h_ny <= n && h_nx <= n && arr[h_ny][h_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (h_ny == n && h_nx == n) {
			cnt++;
			return;
		}
		hori(h_ny, h_nx);
	}

	// 세로
	if (v_ny <= n && v_nx <= n && arr[v_ny][v_nx] == 0) {
		//끝지점에 도착했는지 확인
		if (v_ny == n && v_nx == n) {
			cnt++;
			return;
		}
		verti(v_ny, v_nx);
	}
	// 대각선
	if (d_ny <= n && d_nx <= n && arr[d_ny][d_nx - 1] == 0
		&& arr[d_ny - 1][d_nx] == 0
		&& arr[d_ny][d_nx] == 0) {
		//끝지점에 도착했는지 확인
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
		현재 방향에따라 다음에 가능한 모양이 다름
		1. 가로 --> 가로 or 대각선
		2. 대각선 --> 가로 or 대각선 or 세로
		3. 세로 --> 세로 or 대각선
	*/
	hori(1, 2); // 끝부분
	cout << cnt;


}