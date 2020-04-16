#include<iostream>
#include<queue>

using namespace std;
int N = 0;
char map[100][100];
bool visit[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	int red, blue, green = 0;
	char cur = map[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N) {
				if (cur == 'R' && map[nx][ny] == 'R' && !visit[nx][ny]) { // ťĄ°Ł Ä­
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
				else if (cur == 'B' && map[nx][ny] == 'B' && !visit[nx][ny]) { // ĆÄśő Ä­
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
				else if (cur == 'G' && map[nx][ny] == 'G' && !visit[nx][ny]) { // łěťö Ä­
					q.push({ nx, ny });
					visit[nx][ny] = true;
				}
			}
		}		
	}
}

int main() {
	cin >> N;
	// ŔĎšÝŔÎ 
	for (int i = 0; i < N; i++) {
		string str;
		cin >>str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
			visit[i][j] = false;
		}
	}

	int normal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) { 
				bfs(i, j); normal++;
			}
		}
	}
	
	// ťöžŕ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') { // łěťöŔť ťĄ°ŁťöŔ¸ˇÎ ´Ů šŮ˛Ţ
				map[i][j] = 'R';
			}
			visit[i][j] = false;
		}
	}
	int abnormal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) { 
				bfs(i, j); abnormal++;
			}
		}
	}

	cout << normal << ' ' << abnormal;
}