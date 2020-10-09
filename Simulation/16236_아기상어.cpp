#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

struct SHARK {
	int y;
	int x;
	int size;
};
struct FISH {
	int y;
	int x;
	int size; 
	int dist; // 상어와 물고기 사이의 거리
};

struct DIST {
	int y;
	int x;
	int dist;
};

int map[21][21];
bool visited[21][21];
int n, answer;
SHARK shark; // 아기 상어
vector<FISH>fish; // 물고기
int fish_count = 0; // 먹은 물고기 수


int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

bool cmp(FISH a, FISH b) { // 거리가 가장 가까운 물고기, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기 순으로 정렬
	if (a.dist == b.dist) {
		if (a.y == b.y) {
			if (a.x == b.x) {
				return a.size < b.size;
			}			
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.dist < b.dist;
}

// 상어에서 물고기 까지의 거리 계산
void bfs() {
	queue<DIST>q;
	fish.clear();
	memset(visited, false, sizeof(visited));
	q.push({ shark.y, shark.x, 0 });
	visited[shark.y][shark.x] = true;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int dist = q.front().dist;
		q.pop();

		if (map[y][x]<shark.size && map[y][x]!=0) { // 현재 먹을 수 있는 물고기를 만남				
			fish.push_back({ y,x,map[y][x],dist});
		}
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int ndist = dist + 1;
			if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1)continue;
			if (visited[ny][nx])continue; // 방문
			if (map[ny][nx] > shark.size)continue; // 크기가 더 큰 물고기는 못지나감
			q.push({ ny,nx,ndist });
			visited[ny][nx] = true;
		}
	}
	if (fish.empty())
		return;
	sort(fish.begin(), fish.end(), cmp);
	// 물고기 잡아 먹기
	shark.y = fish.front().y;
	shark.x = fish.front().x;
	fish_count++;
	if (shark.size == fish_count) { // 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
		shark.size += 1;
		fish_count = 0; // 먹은 물고기 초기화 : 이부분 때매 계속 틀렸었음
	}
	answer += fish.front().dist;
	map[fish.front().y][fish.front().x] = 0;	
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.y = i;
				shark.x = j;
				shark.size = 2;
				map[i][j] = 0;
			}
		}
	}
	
	do
	{
		bfs();
	} while (!fish.empty());
	cout << answer;
}