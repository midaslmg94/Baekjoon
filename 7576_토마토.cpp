#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
	만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
	토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
*/
struct Point {
	int x;
	int y;
	int apple;
};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<Point>v(1001);
queue<Point>q;
void bfs() {
	
}

int main() {
	int M, N; 
	cin >> M >> N;
	int day = 0;
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> n;
			v[i].x= j;
			v[i].y = i;
			v[i].apple = n;
			if (n == 1) {
				q.push(v[i]); // 익은 토마토의 위치를 집어넣음
			}
		}
	}
	bfs();
}