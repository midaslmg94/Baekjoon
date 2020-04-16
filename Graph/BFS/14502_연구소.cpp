#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#define MAX 8
using namespace std;
int n, m;
// 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치
int map[MAX][MAX];
bool visit[MAX][MAX];
bool virous[MAX][MAX]; // 바이러스 확산 여부 체크
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int min_virous = 987654;
vector<pair<int, int>>possible;

int bfs(int y, int x) {
	int cnt = 1;
	queue<pair<int, int>>q;	
	q.push({ y,x });
	virous[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny &&	ny < n && 	0 <= nx &&	nx < m && 	map[ny][nx] == 0 &&	virous[ny][nx] != true) {
				q.push({ ny,nx });
				virous[ny][nx] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int spread() {
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && virous[i][j]!=true) {
				area += bfs(i, j); // 확산을 한 바이러스의 개수
			}
		}
	}
	return area;
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true)
				map[i][j] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int tmp;
	vector<int>select;
	int wall = 0; // 벽의 개수
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 0) { //  벽을 세울 수 있는 위치
				possible.push_back({ i,j });
				select.push_back(0);
			}
			else if (tmp == 1) {
				wall++;
			}
		}
	}
	wall += 3; // 벽은 3개 더 세움
	select.pop_back();
	select.pop_back();
	select.pop_back();
	select.push_back(1);
	select.push_back(1);
	select.push_back(1);
	sort(select.begin(), select.end());
	
	int virous_area=0;
	do
	{
		for (int i = 0; i < select.size(); i++) {
			if (select[i] == 1) {// 벽을 세울 수 있는 위치는 3개 --> 모든 지점에 3? 8*=8 = 64C3 ==> 넥퍼뮤 : 4만1천
				//cout << possible[i].first << ',' << possible[i].second << ' ';
				int y = possible[i].first;
				int x = possible[i].second;
				map[y][x] = 1;
				visit[y][x] = true; // 벽이 새로 세워졌으면 체크
			}
		}
		virous_area = spread(); // 3개의 벽을 세우고 바이러스가 퍼진 뒤, 퍼진구역이 몇개 있나 확인
		min_virous = min(min_virous, virous_area);
		init();// 세웠던 벽 초기화1
		memset(visit, false, sizeof(visit)); // 세웠던 벽 초기화2
		memset(virous, false, sizeof(virous)); // 확산 바이러스 초기화
	} while (next_permutation(select.begin(), select.end()));

	int res = (n * m) - min_virous - wall; // 안전구역=전체 맵크기 - 바이러스가 최소로 퍼진 개수 - 벽의 개수
	cout << res;
}