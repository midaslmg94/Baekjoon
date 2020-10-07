#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct TAXI { // 택시의 상태
	int y;
	int x;
	int gas; // 남은 가스
};

struct PEOPLE { // 손님의 상태
	int y;
	int x;
	int dist; // 현재 택시로부터 거리
	int idx;
};

struct TARGET { // 각 손님의 목적지	
	int y;
	int x;
};
bool cmp(PEOPLE a, PEOPLE b) { // 다음 손님 정렬 : 내림차순으로 정렬해서 pop_back()로 가장 가까운 승객을 없애주자
	if (a.dist == b.dist) { 
		if (a.y == b.y) { 	// 그런 승객이 여러 명이면 그중 행 번호가 가장 작은 승객을, 그런 승객도 여러 명이면 그중 열 번호가 가장 작은 승객을 고른다.
			if (a.x == b.x) {
				return a.idx > b.idx;
			}
			return a.x > b.x;
		}
		return a.y > b.y;
	}
	return a.dist > b.dist; 
}



int n, m;
TAXI taxi;
TARGET target[401]; // i번째 손님의 목적지
vector<PEOPLE> peo;
int map[21][21]; // 인덱스 1부터 시작
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
bool visited[21][21];

int check_dist(int ry, int rx) {	
	queue<pair<int, pair<int, int>>>q;
	memset(visited, false, sizeof(visited));
	q.push({ 0,{ taxi.y, taxi.x } });
	while (!q.empty()){
		int y = q.front().second.first;
		int x = q.front().second.second;
		int d = q.front().first;
		if (y == ry && x == rx) return d; // 목적지까지 거리 구함
		visited[y][x] = true;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (1 > ny || ny > n || 1 > nx || nx > n || visited[ny][nx])continue;
			if (map[ny][nx] == 1) continue;
			int nd = d + 1;
			q.push({ nd, { ny,nx } });
			visited[ny][nx] = true; // 방문체크 여기서 해주자..
		}
	}	
	return -1; // 해당 위치까지 택시 못감
}

bool go_taxi(int ry, int rx, bool flag) { // 택시가 움직인다. 도중에 연료 떨어지면 false 리턴
	// flag : true => 택시가 손님을 태우고 움직임. 최종목적지 도달시 연료 2배 충전
	int use_gas = 0; // 이동하는 데 든 연료
	queue<pair<pair<int,int>, pair<int, int>>>q;
	memset(visited, false, sizeof(visited));
	q.push({ {taxi.gas, use_gas}, { taxi.y, taxi.x } });
	while (!q.empty()) {
		int g = q.front().first.first;
		int u = q.front().first.second;
		int y = q.front().second.first;
		int x = q.front().second.second;
		//cout << "taxi : " << taxi.y << ' ' << taxi.x << ' ' << taxi.gas << endl;

		if (g < 0) { // 연료 다 떨어짐
			return false;
		}
		if (y == ry && x == rx) { // 손님한테 도착 or 목적지에 도착
			if (flag) { // 목적지 도착 : 연료 2배충전
				taxi.gas += u * 2;
			}
			taxi.y = y; 
			taxi.x = x;
			taxi.gas -= u;
			return true;
		}
		visited[y][x] = true;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int ng = g - 1;
			int nu = u + 1;
			if (1 > ny || ny > n || 1 > nx || nx > n || visited[ny][nx])continue;
			if (map[ny][nx] == 1) continue;
			q.push({ {ng, nu}, {ny,nx} });
			visited[ny][nx] = true; // 방문체크 여기서 해주자..
			
		}
	}
	return false; // 해당 위치까지 택시 못감	
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> taxi.gas;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}	
	cin >> taxi.y >> taxi.x; 
	for (int i = 1; i <= m; i++) {
		int y, x, d_y, d_x;
		cin >> y >> x >> d_y >> d_x;
		peo.push_back({ y,x,0,i }); // 현재 손님의 위치
		target[i]={ d_y, d_x }; // 현재 손님의 목적지
	}	

	// 태울 승객을 고를 때는 현재 위치에서 최단거리가 가장 짧은 승객을 고른다. 	
	while (!peo.empty())
	{		
		for (int i = 0; i < peo.size(); i++) {
			peo[i].dist = check_dist(peo[i].y, peo[i].x);
			if (peo[i].dist == -1) { // 해당 손님한테 못감
				cout << -1;
				return 0;
			}
		}
		sort(peo.begin(), peo.end(), cmp);
		/*for (auto a : peo) {
			cout << a.y << ' ' << a.x << ' ' << a.dist << endl;
		}
		cout << endl;*/
		// 가장 가까운 손님에게 택시 이동		
		if (!go_taxi(peo.back().y, peo.back().x, false)) {
			cout << -1;
			return 0;
		}
		// 손님을 목적지로 이동 : 
		if (!go_taxi(target[peo.back().idx].y, target[peo.back().idx].x, true)) {
			cout << -1;
			return 0;
		}
		//cout << "taxi : " << taxi.y << ' ' << taxi.x << ' ' << taxi.gas << endl;

		// 이동 완료 시 손님 삭제
		peo.pop_back();
	}
	cout << taxi.gas;
}