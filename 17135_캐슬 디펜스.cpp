#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 15
#define endl "\n"
#define pii pair<int,pair<int,int>> 
using namespace std;
int n, m, d;
struct INFO
{
	int state; // 0:벽, 1:적
	bool isAttacked; // 적이 화살에 맞았는지 아닌지
};
INFO map[MAX][MAX];
vector<int>archer_candi; // 궁수가 들어갈 수 있는 위치
vector<int>archer; // 궁수가 위치한 곳 
bool visit[MAX];
int result = -1;
struct ENEMY {
	int dist;
	int y;
	int x;
};
bool cmp(const ENEMY &a, const ENEMY &b ) {// 거리가 짧은 순, 거리가 같다면 가장 왼쪽에 있는 순
	return a.dist < b.dist || (a.dist == b.dist && a.x < b.x);
}
int attack(vector<int>my_archer) {
	INFO backup[MAX][MAX];
	int kill = 0;
	memcpy(backup, map, sizeof(backup));
	int turn = n;
	while (turn--) // y축의 길이만큼 게임은 진행
	{
		queue<pair<int, int>>dead_enemy; // 죽은 적의 위치
		vector<ENEMY>enemy; // 적의 위치			
		for (int t = 0; t < my_archer.size(); t++) {
			// 궁수의 위치 
			int archer_y = n;
			int archer_x = my_archer[t];
			enemy.clear();
			// 가장 가까운 거리내에 있는 적을 왼쪽에서 부터 쏜다
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < m; j++) {
					if (backup[i][j].state == 1) { // 적이라면 
						int dist = abs(archer_y - i) + abs(archer_x - j); // 적과의 거리 확인							
						if (dist <= d) { // 사거리 내의 적이라면 위치 저장
							// 가장 가까운 적을 찾고, 가장 가까운 적이 여럿이라면, 그 중 가장 왼쪽을 찾는다.
							enemy.push_back({dist,i,j});
						}
					}
				}
			}
			if (!enemy.empty()) { // 사정거리 내 적이 1명이라도 있을 경우
				sort(enemy.begin(), enemy.end(), cmp); // 맨 앞이 최단거리, 맨 왼쪽에 위치한 적
				//int enemy_dist = enemy.front().dist;
				int enemy_y = enemy.front().y;
				int enemy_x = enemy.front().x;
				if (backup[enemy_y][enemy_x].isAttacked == false) { // 아직 살아있는 적이라면  
					backup[enemy_y][enemy_x].isAttacked = true; // 죽이고
					dead_enemy.push({ enemy_y,enemy_x }); // 죽인 적의 위치를 저장
					kill++; // 죽인 적의 수 추가
				}
			}
		}
		// 죽은 적은 없앤다
		while (!dead_enemy.empty()) {
			int dead_y = dead_enemy.front().first;
			int dead_x = dead_enemy.front().second;
			backup[dead_y][dead_x].state = 0;
			backup[dead_y][dead_x].isAttacked = false;
			dead_enemy.pop();				
		}
		// 적이 아래로 한칸씩 이동
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (i == n - 1) {
					backup[i][j].state = 0;
					backup[i][j].isAttacked = 0;
				}
				else {
					backup[i + 1][j] = backup[i][j];
				}
			}
		}
		for (int j = 0; j < m; j++) {
			backup[0][j].state = 0;
			backup[0][j].isAttacked = 0;
		}
	}
	return kill;
}

void dfs(int idx, int cnt) { // 성벽에 3명의 궁수를 배치(조합으로 구현)
	if (cnt == 3) {		
		int cur = attack(archer);
		result = max(result, cur);		
		return;
	}
	for (int i = idx; i <m; i++) {
		if (visit[i]) continue;
		archer.push_back(archer_candi[i]);
		visit[i] = true;
		dfs(i, cnt + 1);
		archer.pop_back();
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].state;
			map[i][j].isAttacked = false;
		}
	}
	for (int j = 0; j < m; j++)
		archer_candi.push_back(j); // 궁수가 들어갈 수 있는 위치
	dfs(0, 0);
	cout << result;

}