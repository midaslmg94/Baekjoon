#include<iostream>
#include<string>
#include<queue>
using namespace std;
int r, c;
char mineral[111][111];
bool cluster[111][111];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 좌우로 움직이면 c가 증감, x축
	// 상하로 움직이면 r이 증감, y축
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mineral[i][j];
		}
	}
	int n;
	cin >> n; // 막대를 던진 횟수
	bool left = true; // 왼쪽부터 던짐
	/*막대기 던져서 미네랄 파괴*/
	while (n--) {
		int height;
		cin >> height;
		height = r - height + 1;
		// 왼쪽 미네랄 파괴
		if (left == true) {
			for (int i = 1; i <= c; i++) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		// 오른쪽 미네랄 파괴
		else {
			for (int i = c; i >= 1; i--) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		left = !left;
		/*클러스터 확인*/
		memset(cluster, false, sizeof(cluster));
		for (int j = 1; j <= c; j++) {
			if (mineral[r][j] == 'x') { // 맨 밑바닥에 미네랄있는지 확인
				queue<pair<int, int>>q;
				q.push(make_pair(r, j)); // 주변에 클러스터를 확인하기 위함
				cluster[r][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (1 <= nx && nx <= c && 1 <= ny && ny <= r) {
							if (cluster[nx][ny] == false && mineral[nx][ny] == 'x') {
								cluster[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
		/*밑에서 위로 확인*/
		int down = r;
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (mineral[i][j] == 'x' && cluster[i][j] == false) {
					int col_down = r - i;

				}
			}
		}
	}


}