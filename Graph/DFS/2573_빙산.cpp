#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 300
using namespace std;
struct ICE
{
	int y;
	int x;
	int seaside;
};
int n, m;
int map[MAX][MAX];
int check[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int answer = 0;
int idx = 1;
bool oneIceberg = true; // 한개의 빙산으로 쭉 살아남았는지 확인
queue<ICE>q;
queue<pair<int, int>>iceberg;

void seaCount(int y, int x) { // 4방향 중 바다인 지점의 개수를 센다.
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
		if (map[ny][nx] == 0) {
			cnt++;
		}
	}
	q.push({ y,x,cnt });
}

void masking(int y, int x, int mask) {
	check[y][x] = mask;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 > ny || ny >= n || 0 > nx || nx >= m || check[ny][nx]>0)continue;
		if (map[ny][nx] != 0) {
			check[ny][nx] = mask;
			masking(ny, nx, mask);
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		memset(check, 0, sizeof(check));		
		idx = 1;
		answer++; 
		oneIceberg = true;
		// 바닷물에 얼마나 접해있나 확인
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					seaCount(i, j);
					check[i][j] = -1; // 얼음인 경우 초기값을 -1로 해줌
				}
			}
		}
		// 바닷물에 접한 만큼 빙산이 녹음.
		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			int sea = q.front().seaside;
			q.pop();
			map[y][x] = map[y][x] - sea;
			if (map[y][x] < 0) map[y][x] = 0; // 0 미만으로는 못감 
		}

		// 빙산이 분리되었는지 확인(마스킹)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0 && check[i][j]==-1) {
					masking(i, j,idx);
					idx++; // idx가 3이상이면, 두 덩어리로 분리되었다는 뜻
				}
			}
		}
		// 두 덩어리 이상으로 분리 --> 종료
		if (idx >= 3) {
			break;
		}		

		// 끝까지 한 덩어리로 있다가 녹아서 없어져 버림 -> map의 값이 전부 0인지 확인
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					oneIceberg = false;
				}
			}
		}
		if (oneIceberg) {
			answer = 0;
			break;
		}
	}
	cout << answer;
	return 0;
}