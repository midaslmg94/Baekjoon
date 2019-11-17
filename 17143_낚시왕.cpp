#include<iostream>
#include<vector>
using namespace std;
const int MAX = 100;
int R, C, M = 0; //격자의 크기, 상어수
vector<pair<int, pair<int, int>>>shark[MAX][MAX]; // 크기, (이동방향, 속력)
int check[MAX][MAX]; //움직인 애인지 아닌지 확인
int sum = 0; // 물고기 잡은거

void catchShark(int cur) {
	for (int i = 0; i < R; i++) {
		if (shark[i][cur].front().first > 0) {
			sum += shark[i][cur].front().first;
			shark[i][cur].front().first = 0;
			shark[i][cur].front().second.first = 0;
			shark[i][cur].front().second.second = 0;
			break;
		}
	}
	return;
}
void moveShark() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//s와 d를 확인하여 이동방향, 거리 확인
			if (shark[i][j].front().first != 0 && check[i][j] == 0) {
				int x = i;
				int y = j;
				int size = shark[i][j].front().first; //크기
				int dir = shark[i][j].front().second.first; //이동방향
				int dist = shark[i][j].front().second.second; //이동거리
				/* 상어가 움직임
				d가 1인 경우는 위, 	2인 경우는 아래,
				3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.*/
				cout << "이동 전 크기: " << size << " 위치" << x << "," << y << " 방향" << dir << " 거리" << dist << "\n";
				for (int k = 0; k < dist; k++) {
					if (dir == 1) {//위로 감 , 벽에 부딪히면 dir = 2
						x = x - 1;
						if (x == 0) { dir = 2; }
					}
					else if (dir == 2) {//아래로 감, 벽에 부딪히면 dir = 1
						x = x + 1;
						if (x == R - 1) { dir = 1; }
					}
					else if (dir == 3) {//오른쪽으로 감, 벽에 부딪히면 dir = 4
						y = y + 1;
						if (y == C - 1) { dir = 4; }
					}
					else if (dir == 4) {//왼쪽으로 감, 벽에 부딪히면 dir = 3
						y = y - 1;
						if (y == 0) { dir = 3; }
					}
				}
				cout << "이동 후 크기: " << size << " 위치" << x << "," << y << " 방향" << dir << " 거리" << dist << "\n";
				// 같은 칸에 상어가 있으면 
				if (shark[x][y].front().first != 0) {
					if (size > shark[x][y].front().first) {// x, y에 있던 상어가 더 작음. 먹힘 
						shark[x][y].front().first = shark[i][j].front().first;
						shark[x][y].front().second.first = shark[i][j].front().second.first;
						shark[x][y].front().second.second = shark[i][j].front().second.second;
					}
				}
				// 같은 칸에 상어가 없으면
				else if (shark[x][y].front().first == 0) {
					shark[x][y].front().first = shark[i][j].front().first;
					shark[x][y].front().second.first = shark[i][j].front().second.first;
					shark[x][y].front().second.second = shark[i][j].front().second.second;
				}
				//움직이기 이전(i,j)에 있던 상어는 0으로 바꿈
				cout << "싸움 후 크기: " << size << " 위치" << x << "," << y << " 방향" << dir << " 거리" << dist << "\n";
				shark[i][j].front().first = 0;
				shark[i][j].front().second.first = 0;
				shark[i][j].front().second.second = 0;
				check[x][y] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	/*
		(r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다.
		d가 1인 경우는 위, 	2인 경우는 아래,
		3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
	*/
	cin >> R >> C >> M;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			shark[i][j].push_back(make_pair(0, make_pair(0, 0)));
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[r - 1][c - 1].front().first = z;
		shark[r - 1][c - 1].front().second.first = d;
		shark[r - 1][c - 1].front().second.second = s;
	}


	for (int j = 0; j < C; j++) {
		cout << endl;
		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				printf("%d ", shark[a][b].front().first);
			}
			cout << endl;
		}
		catchShark(j);
		moveShark();
	}
	cout << sum;
}