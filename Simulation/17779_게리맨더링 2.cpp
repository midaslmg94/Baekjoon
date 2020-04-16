#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 21
using namespace std;

struct INFO {
	int sector;
	int people;
};
INFO map[MAX][MAX];
int n;
int cnt[5]; // 선거구 별 인구수

int calculate() { // 선거구 별 인구수 차이를 구함
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int idx = map[i][j].sector;
			cnt[idx - 1] += map[i][j].people;  // 이렇게 합을 따로 구해주니까 맞았음
		}
	}
	sort(cnt, cnt + 5);
	return cnt[4] - cnt[0];
}
void bfs(int x, int y, int d1, int d2) {

	//초기화
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j].sector = 0;
		}
	}

	// 5번 선거구 경계선 채우기
	int up_x = x; int up_y = y; // 제일 위쪽 5번 선거구 : 1번 경계
	if (up_x - 1 >= 1) {
		map[up_x - 1][up_y].sector = 1;
	}
	while (up_x <= x + d1 && up_y >= y - d1) {
		map[up_x][up_y].sector = 5;
		up_x++; up_y--;
	}

	int left_x = x + d1; int left_y = y - d1; // 가장 왼쪽 5번 선거구 : 3번 경계
	if (left_y - 1 >= 1) {
		map[left_x][left_y].sector = 3;
	}
	while (left_x <= x + d1 + d2 && left_y <= y - d1 + d2) {
		map[left_x][left_y].sector = 5;
		left_x++; left_y++;
	}

	int down_x = x + d1 + d2; int down_y = y - d1 + d2; // 가장 아래쪽 5번 선거구 : 4번 경계
	if (down_x + 1 <= n) {
		map[down_x][down_y].sector = 4;
	}
	while (down_x >= x + d2 && down_y <= y + d2) {
		map[down_x][down_y].sector = 5;
		down_x--; down_y++;
	}

	int right_x = x + d2; int right_y = y + d2; // 가장 오른쪽 5번 선거구 : 2번 경계
	if (right_y + 1 <= n) {
		map[right_x][right_y].sector = 2;
	}
	while (right_x >= x && right_y >= y) {
		map[right_x][right_y].sector = 5;
		right_x--; right_y--;
	}

	int x1 = x;
	int x2 = x;
	int x3 = x;
	int x4 = x;
	int y1 = y;
	int y2 = y;
	int y3 = y;
	int y4 = y;
	// 1번 선거구 채우기
	for (int i = 1; i < x1 + d1; i++) {
		for (int j = 1; j <= y1; j++) {
			if (map[i][j].sector != 0) {
				y1--;
				continue;
			}
			map[i][j].sector = 1;
			//cnt[0] += map[i][j].people; // 이렇게 했더니 틀렸음
		}
	}
	// 2번 선거구 채우기
	for (int i = 1; i <= x2 + d2; i++) {
		for (int j = y2 + 1; j <= n; j++) {
			if (map[i][j].sector != 0) {
				y2++;
				continue;
			}
			map[i][j].sector = 2;
			//cnt[1] += map[i][j].people;
		}
	}
	// 3번 선거구 채우기
	for (int i = n; i >= x3 + d1; i--) {
		for (int j = 1; j < y3 - d1 + d2; j++) {
			if (map[i][j].sector != 0) {
				y3--;
				continue;
			}
			map[i][j].sector = 3;
			//cnt[2] += map[i][j].people;

		}
	}
	// 4번 선거구 채우기
	for (int i = n; i > x4 + d2; i--) {
		for (int j = y4 - d1 + d2; j <= n; j++) {
			if (map[i][j].sector != 0) {
				y4++;
				continue;
			}
			map[i][j].sector = 4;
			//cnt[3] += map[i][j].people;
		}
	}
	// 5번 선거구 채우기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].sector == 0 || map[i][j].sector == 5) {
				map[i][j].sector = 5;
				//cnt[4] += map[i][j].people;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j].people;
			map[i][j].sector = 0;
		}
	}

	/*bfs(3, 5, 2, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j].sector << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j].people << ' ';
		}
		cout << endl;
	}*/

	int res = 0;
	int ans = 987654321;
	res = calculate();
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (1 <= y - d1 && y + d2 <= n && x + d1 + d2 <= n) {
						bfs(x, y, d1, d2);
						res = calculate();
						ans = min(ans, res);
					}
				}
			}
		}
	}
	cout << ans;
}