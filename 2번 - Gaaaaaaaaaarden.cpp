#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 50
#define pii pair<int,int>
using namespace std;
struct GROUND {//땅의 상태
	int state; // 0:호수, 1:배양액을 뿌릴수 없음, 2:배양액을 뿌릴 수 있음
	int red; // 빨간색 배양액이 뿌려진 시점
	int green; // 초록색 배양액이 뿌려진 시점
	bool flower; // 꽃이 피어나는지 확인
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, g, r;
GROUND map[MAX][MAX];
GROUND backup[MAX][MAX];
bool backup_visit[MAX][MAX];
bool dfs_visit[MAX];

vector<pii>candi_space; // 배양액 심을 수 있는 땅(최대 10개)
vector<pii>choosen_space; // 배양액 심는 땅
queue<pii>green_space; // 초록배양액 심을 땅(최대 5개)
queue<pii>red_space;  // 빨간배양액 심을 땅(최대 5개)
bool nutrients_visit[10]; // 배양액 고를 때 씀
int answer = -1;


int bfs() {
	memcpy(backup, map, sizeof(backup));
	memset(backup_visit, false, sizeof(backup_visit));
	int spread_time = 0;
	int flower_cnt = 0;		
	while (true) {
		if (green_space.empty() && red_space.empty())
			break;
		// 빨간 배양액을 뿌린다.
		int red_size = red_space.size();
		for (int i = 0; i < red_size; i++) {
			int red_y = red_space.front().first;
			int red_x = red_space.front().second;
			backup[red_y][red_x].red = spread_time;
			backup_visit[red_y][red_x] = true;
			red_space.pop();
			if (backup[red_y][red_x].flower == true)continue; // 꽃이 핀 곳이면 제외
			for (int k = 0; k < 4; k++) {
				int red_ny = red_y + dy[k];
				int red_nx = red_x + dx[k];
				if (0 > red_ny || red_ny >= n || 0 > red_nx || red_nx >= m)continue; // 범위 초과
				if (backup_visit[red_ny][red_nx])continue; // 방문지점
				if (backup[red_ny][red_nx].state == 0)continue; // 호수에는 확산 불가
				if (backup[red_ny][red_nx].flower == true)continue;// 꽃이 핀 지점에는 확산 불가
				backup[red_ny][red_nx].red = spread_time + 1;
				red_space.push({ red_ny,red_nx });
			}			
		}
		// 초록 배양액을 뿌린다.
		int green_size = green_space.size();
		for (int i = 0; i < green_size; i++) {
			int y = green_space.front().first;
			int x = green_space.front().second;
			backup[y][x].green = spread_time;
			backup_visit[y][x] = true;
			green_space.pop();
			if (backup[y][x].flower == true)continue; // 꽃이 핀 곳이면 제외
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= m)continue; // 범위 초과
				if (backup_visit[ny][nx])continue; // 방문지점
				if (backup[ny][nx].state == 0)continue; // 호수에는 확산 불가
				if (backup[ny][nx].flower == true)continue;// 꽃이 핀 지점에는 확산 불가				
				backup[ny][nx].green = spread_time + 1; 
				green_space.push({ ny,nx });
			}		
		}

		// 꽃이 피는지 확인
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (backup[i][j].state == 0)continue;
				if (backup[i][j].red == backup[i][j].green) {
					if (backup[i][j].red == -1 || backup[i][j].green==-1)continue;
					backup[i][j].flower = true;
				}
			}
		}
		spread_time++;
	}
	// 꽃의 개수 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (backup[i][j].flower == true) {
				flower_cnt++;
			}
		}
	}
	return flower_cnt;
}

void choice_color(int idx, int cnt) {
	if (cnt == g) {		
		for (int i = 0; i < choosen_space.size(); i++) {
			if (nutrients_visit[i]) { // 초록 배양액
				green_space.push({ choosen_space[i].first,choosen_space[i].second });
			}
			else {
				red_space.push({ choosen_space[i].first,choosen_space[i].second });
			}
		}
		int res = bfs();
		answer = max(res, answer);
		return;
	}
	for (int i = idx; i < choosen_space.size(); i++) {
		if (nutrients_visit[i])continue;
		nutrients_visit[i] = true;
		choice_color(i, cnt + 1);
		nutrients_visit[i] = false;
	}
}

void dfs(int idx, int cnt) {
	if (cnt == g + r) {
		choosen_space.clear();
		for (int i = 0; i < candi_space.size(); i++) {
			if (dfs_visit[i] == true) {
				int y = candi_space[i].first;
				int x = candi_space[i].second;
				choosen_space.push_back({ y,x }); // 배양액을 뿌릴 공간
			}
		}
		// 배양액을 심는 땅 중에 초록or빨강 배양액을 뿌릴 땅을 고름 --> 넥퍼뮤로 해야하나..
		choice_color(0, 0);
		//memset(nutrients_visit, false, sizeof(nutrients_visit));
		return;
	}
	for (int i = idx; i < candi_space.size(); i++) {
		if (dfs_visit[i])continue;
		dfs_visit[i] = true;
		dfs(i, cnt + 1);
		dfs_visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].state;
			map[i][j].red = -1;
			map[i][j].green = -1;
			map[i][j].flower = false;
			if (map[i][j].state == 2) {
				candi_space.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}