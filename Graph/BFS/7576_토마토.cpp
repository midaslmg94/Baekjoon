#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	정수 1은 익은 토마토, 
	정수 0은 익지 않은 토마토,
	정수 -1은 토마토가 들어있지 않은 칸

	토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
	만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
	토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int tomato[1000][1000];
queue<pair<int, int>>q;


int main() {
	int M, N; 
	int total = 0; // 토마토가 있는 칸과 토마토가 없는 칸의 합을 확인해주기 위함
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			//d[i][j] = -1;
			if (tomato[i][j] == 1) { 
				q.push({i, j}); 
			}
			else if (tomato[i][j] == -1) { // 토마토가 없음
				total++;
			}
		}
	}
	int size = 0;
	int day = 0;

	while (!q.empty()) {
		size = q.size(); // 익은 토마토의 개수
		total += size; // 토마토가 없는 칸 + 익은 토마토가 있는 칸

		if (total == N * M) { //토마토가 없는 칸 + 익은 토마토가 있는 칸의 값이 전체 창고의 크기와 같으면 끝
			cout << day;
			break;
		}
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (tomato[nx][ny] == 0) { // 주변이 익지 않은 토마토라면
						tomato[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		day++;
	}
	if (total != N * M) {
		cout << -1;
	}
	return 0;
}