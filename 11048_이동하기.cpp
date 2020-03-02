#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;
int n, m;
int dy[3] = { 0,1,1}; // ������, �Ʒ�, �밢��(�밢���� �ȱ��ص� �Ǳ� ��)
int dx[3] = { 1,0,1};
int map[MAX][MAX];
int candy[MAX][MAX]; // �ش� ������ �������� �� ���� �� �ִ� �ִ� ���� ��

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	candy[0][0] = map[0][0]; 
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			for (int dir = 0; dir < 3; dir++) {
				int ny = dy[dir] + y;
				int nx = dx[dir] + x;
				if (0 > ny || ny >= n || 0 > nx || nx >= m )continue;			
				candy[ny][nx] = max(candy[y][x] + map[ny][nx], candy[ny][nx]);				
			}
		}
	}

	cout << candy[n-1][m-1];
}