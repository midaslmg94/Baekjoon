#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	첫째줄 입력
		지도의 너비 : w
		지도의 높이 : h
	둘째줄 입력
		지도가 주어짐, 1:땅, 0:바다
	입력의 마지막 줄 : 0이 2개주어짐

	출력 : 섬의 개수를 출력
	상하좌우대각선으로 움직임 가능
*/
vector<vector<int>> map;
int visit[50][50];
int dx[8] = { 0, 0, 1, -1,-1, -1,  1, 1 };
int dy[8] = { 1,-1,0,  0, -1,  1, -1, 1 };

int bfs(int x, int y, int w, int h) {
	int island = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < h && 0 <= ny && ny < w)
			{
				if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
					island++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return island;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> tmp1;
	vector<int> answer;
	int w; int h;
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) { break; }
		int n;
		/*테스트 케이스 입력*/
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> n;
				tmp1.push_back(n);
			}
			map.push_back(tmp1);
			tmp1.clear();
		}
		/*섬을 세보자*/
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j, w, h);
				}
			}
		}
		map.clear();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}