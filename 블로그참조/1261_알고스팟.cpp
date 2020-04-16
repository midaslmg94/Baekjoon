#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#define ppii pair<int, pair<int,int>>
#define MAX 100
using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int wall = 0;
void dijkstra(int y, int x) {
	priority_queue<ppii, vector<ppii>, greater<ppii>>pq; // 최소힙 - 깨트린 벽을 기준으로 
	pq.push({ 0,{0,0} });
	visit[0][0] = true;
	while (!pq.empty()) {
		wall = pq.top().first;
		y = pq.top().second.first;
		x = pq.top().second.second;
		pq.pop();
		if (y == n - 1 && x == m - 1) // 마지막에 도착 
			return;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m || visit[ny][nx]) continue;
			if (map[ny][nx] == 0) { // 빈 곳인 경우
				pq.push({ wall,{ny,nx} });
			}
			else { // 벽일 경우
				pq.push({ wall + 1,{ny,nx} });
			}
			visit[ny][nx] = true;
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	dijkstra(0, 0);
	cout << wall;
}