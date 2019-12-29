#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int w,h=0;
vector<vector<char>>map;

int dist[1000][1000];
deque<pair<int, int>>fire; // 불의 위치

bool isAlive(int x, int y) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '@') {
				return true;
			}
		}
	}
	return false;
}


bool canGo(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			if (map[nx][ny] == '.') { // 하나라도 빈공간이 있으면 이동 가능
				return true;
			}
		}
	}	
	return false;
}

void movefire(){ // 벽을 제외하고 주변을 * 로 바꿈
	int size = fire.size();
	for (int i = 0; i < size; i++) {
		int x = fire[0].first;
		int y = fire[0].second;
		fire.pop_front();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (map[nx][ny] == '.' ) { 
					map[nx][ny] = '*';
					fire.push_back({ nx,ny });
				}
			}
		}		
	}

}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		movefire();
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int nx; int ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] == '.') {// 상근이가 이동 가능
				// 이동할 때 다음에 불이 번질 곳은 가면 안됨. 상근이가 먼저 이동해야 함.
				// 이동하는 모든 곳에 @를 넣어두자.
				map[nx][ny] = '@';
				q.push({ nx,ny });				
				dist[nx][ny] = dist[x][y] + 1;
			}
			
		// 탈출 가능한지 확인 : 가장 자리에 상근이가 있으면 된다.
		if (nx == 0 || nx == h-1 || ny == 0 || ny == w-1) {
			cout << dist[nx][ny] + 1<<endl;
			return;
		}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int startX = 0; int startY = 0; // 상근이의 시작점
		cin >> w >> h;
		map.clear();  fire.clear();
		map.resize(h); 
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < w; j++) {
				map[i].push_back(str[j]);
				dist[i][j]=0;
				if (str[j] == '@') {// 상근이의 위치
					startX = i;
					startY = j;
				}
				else if (str[j] == '*') { // 불
					fire.push_back({ i,j });
				}
			}
		}

		// 벽 or 불로 둘러쌓인지 확인
		if (!canGo(startX, startY)) {
			cout << "IMPOSSIBLE" << endl;
		}
		 //	상근이, 불 이동
		else {			
			bfs(startX, startY);
		}		
	}

}