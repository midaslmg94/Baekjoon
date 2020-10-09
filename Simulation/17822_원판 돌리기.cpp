#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int n, m, t;
int x, d, k; // 번호가 x의 배수인 원판을 d방향(0:시계방향, 1:반시계방향)으로 k칸 회전
int board[51][51];
bool check[51][51]; // 인접해서 지울 수 있는지
void prt() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}
// 원판 회전
void rotate(int idx) {	
	if (d == 0) { // 시계방향 회전 : 맨 뒤의 원소가 맨 앞으로 오고, 나머지는 앞에 있는 원소가 내 자리로 옴
		for (int i = 0; i < k; i++) { // k칸 회전
			int last_idx = board[idx][m];
			for (int j = m; j > 1; j--) {
				board[idx][j] = board[idx][j - 1];
			}
			board[idx][1] = last_idx;
		}
	}
	else { // 반시계 방향 회전 : 맨 앞의 원소가 맨 뒤로 가고, 나머지는 뒤에 있는 원소가 내 자리로 옴
		for (int i = 0; i < k; i++) {
			int first_idx = board[idx][1];
			for (int j = 1; j < m; j++) {
				board[idx][j] = board[idx][j + 1];
			}
			board[idx][m] = first_idx;
		}
	}
	/*prt();
	cout << "\n\n";*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k; // 번호가 x의 배수인 원판을 d방향(0:시계방향, 1:반시계방향)으로 k칸 회전
		for (int i = x; i <= n; i += x) {
			rotate(i);
		}
		memset(check, false, sizeof(check));
		bool flag = false; // 인접하는게 있는지 확인
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				//(i, 1)은 (i, 2), (i, M)과 인접하다.
				if (board[i][1] == board[i][2] && board[i][1] != 0) {
					check[i][1] = true; check[i][2] = true;
					flag = true;
				}
				if (board[i][1] == board[i][m] && board[i][1] != 0) {
					check[i][1] = true; check[i][m] = true;
					flag = true;
				}

				//(i, M)은 (i, M-1), (i, 1)과 인접하다.
				if (board[i][m] == board[i][m - 1] && board[i][m] != 0) {
					check[i][m] = true; check[i][m - 1] = true;
					flag = true;
				}
				if (board[i][m] == board[i][1] && board[i][m] != 0) {
					check[i][m] = true; check[i][1] = true;
					flag = true;
				}

				//(i, j)는 (i, j-1), (i, j+1)과 인접하다. (2 ≤ j ≤ M-1) 
				if (j >= 2) {
					if (board[i][j] == board[i][j - 1] && board[i][j] != 0) {
						check[i][j] = true; check[i][j - 1] = true;
						flag = true;
					}
				}
				if (j <= m - 1) {
					if (board[i][j] == board[i][j + 1] && board[i][j] != 0) {
						check[i][j] = true; check[i][j + 1] = true;
						flag = true;
					}
				}
				//(1, j)는 (2, j)와 인접하다. 
				if (board[1][j] == board[2][j] && board[1][j] != 0) {
					check[1][j] = true; check[2][j] = true;
					flag = true;
				}
				//(N, j)는 (N-1, j)와 인접하다. 
				if (board[n][j] == board[n - 1][j] && board[n][j] != 0) {
					check[n][j] = true; check[n - 1][j] = true;
					flag = true;
				}

				//(i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1) 
				if (i >= 2) {
					if (board[i][j] == board[i - 1][j] && board[i][j] != 0) {
						check[i][j] = true; check[i - 1][j] = true;
						flag = true;
					}
				}
				if (i <= n - 1) {
					if (board[i][j] == board[i + 1][j] && board[i][j] != 0) {
						check[i][j] = true; check[i + 1][j] = true;
						flag = true;
					}
				}
			}
		}

		// 인접하면서 수가 같은 것이 없으면 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
		if (!flag) {
			int sum = 0;
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					sum += board[i][j];
					if (board[i][j] != 0)cnt++;
				}
			}
			//int avg = sum / cnt; // 소숫점 때문에 평균을 구할 때 나누기를 하지 않음
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (board[i][j]*cnt > sum)board[i][j] -= 1; // board[i][j] > avg 인데, avg = sum/cnt 이므로 분모를 좌측으로 넘겨준다
					else if (board[i][j]*cnt < sum && board[i][j] != 0)board[i][j] += 1; // 소숫점 때문에
					// board[i][j]가 평균과 같은 경우는 아무것도 하지 않음
				}
			}
		}
		else { //인접한 수 삭제
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (check[i][j]) {
						board[i][j] = 0;
					}
				}
			}
		}
		/*prt();
		cout << endl;*/
	}

	// 원판에 적힌 수의 합 구하기

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			answer += board[i][j];
		}
	}
	cout << answer;
}