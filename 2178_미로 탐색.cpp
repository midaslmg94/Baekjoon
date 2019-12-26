#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int n, m;
int map[100][100];
int dist[100][100];
int dx[4] = {0,1,-1,0 }; // 오른쪽, 아래, 위, 왼쪽 순으로 탐색
int dy[4] = {1,0, 0,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	dist[x][y] = 1; // 처음 정점은 1
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) { // map 내부
				if (map[nx][ny] == 1 && dist[nx][ny]==-1) {  //이동 가능					
					dist[nx][ny] = dist[x][y]+1;
					//cout << "방문정점 : " << nx << ' ' << ny << "  이동거리 : "<< dist[nx][ny]<<endl;
					if (nx == n - 1 && ny == m - 1) {
						cout << dist[nx][ny] << endl;
						return;
					}
					q.push({ nx, ny });
				 }
			}
		}	
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]); 		
			dist[i][j] = -1;
			/*
				또는 
        for (int i = 0; i < N; i++){
             string temp;
             cin >> temp;
             for (int j = 0; j < M; j++){
                   map[i][j] = temp[j]-'0';
			}
        }
			*/
		}
	}
	bfs(0, 0);
}