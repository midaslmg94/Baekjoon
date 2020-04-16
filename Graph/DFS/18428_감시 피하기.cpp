#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#define MAX 6
#define endl "\n"
using namespace std;
char map[MAX][MAX];
char backup[MAX][MAX]; // 장애물 세우느라 조작할 지도
vector<pair<int, int>>space; // 빈 공간 : 장애물이 들어갈 곳
vector<pair<int, int>>teacher; // 선생님의 위치

bool visit[MAX * MAX];
int n;
bool findStudent() {	
	bool isFind = false;  // 학생을 발견하였는지
	for (int i = 0; i < teacher.size(); i++) {
		int ty = teacher[i].first;
		int tx = teacher[i].second;
		bool findRight = true; bool findLeft = true;  // 해당 방향에 장애물이 있다면 더 탐색 X 
		bool findUp = true; bool findDown = true;
		for (int dir = 1; dir < n; dir++) {
			if (tx + dir < n && findRight) { // 오른쪽으로 확인
				if (backup[ty][tx + dir] == 'O') { // 장애물
					findRight = false;
					isFind = false;
				}
				else if (backup[ty][tx + dir] == 'S') { // 학생
					isFind = true;
					return true;
				}
				else { // 빈공간
					isFind = false;
				}
			}
			if (tx - dir >= 0 && findLeft) { // 왼쪽으로 확인
				if (backup[ty][tx - dir] == 'O') {
					findLeft = false;
					isFind = false;
				}
				else if (backup[ty][tx - dir] == 'S') {
					isFind = true;
					return true;
				}
				else {
					isFind = false;
				}
			}
			if (ty + dir < n && findDown) { // 아래쪽으로 확인
				if (backup[ty + dir][tx] == 'O') {
					findDown = false;
					isFind = false;					
				}
				else if (backup[ty + dir][tx] == 'S') {
					isFind = true;
					return true;
				}
				else {
					isFind = false;
				}
			}
			if (ty - dir >= 0 && findUp) { // 위쪽으로 확인
				if (backup[ty - dir][tx] == 'O') {
					findUp = false;
					isFind = false;
				}
				else if (backup[ty - dir][tx] == 'S') {
					isFind = true;		
					return true;
				}
				else {
					isFind = false;
				}
			}
		}
	}
	return isFind;
}

void dfs(int idx, int depth) {
	if (depth == 3) { // 3개의 장애물의 위치를 골랐음
		memcpy(backup, map, sizeof(backup));
		for (int i = 0; i < space.size(); i++) {
			if (visit[i]) {
				int y = space[i].first;
				int x = space[i].second;
				backup[y][x] = 'O';
			}
		}
		if (!findStudent()) {
			cout << "YES";
			exit(0);
		}
		return;
	}

	// 빈 공간에서 장애물이 들어갈 위치 고르기 (조합)
	for (int i = idx; i < space.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, depth + 1);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X')
				space.push_back({ i,j });
			else if (map[i][j] == 'T')
				teacher.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << "NO";
	return 0;	
}