#include<iostream>
#include<string.h>
#include<vector>
#define MAX 101
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int sum; // 잡은상어의 총 크기
struct INFO {
	int speed;
	int dir;
	int size;
};
INFO shark[MAX][MAX];
vector<bool>visit[MAX][MAX];
int R, C, M;// 세로, 가로, 상어 수

void catchShark(int pos) { //  낚시왕이 상어를 잡음
	for (int i = 1; i <= R; i++) {
		if (shark[i][pos].size) {// 상어가 있으면
			sum += shark[i][pos].size;
			shark[i][pos] = { 0,0,0 };
			return;
		}
	}
}
void moveShark() { // 상어가 움직임, 움직인 상어를 체크
	// 같은 공간에 2마리 이상의 상어가 있을 때 처리
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (shark[i][j].size) {//상어가 있으면
				// 경계선에 있는 상어일 경우, 반대쪽으로 방향을 돌려줌

				// 상어가 움직임
				int cur_dir = shark[i][j].dir;
				int cur_speed = shark[i][j].speed;
				if (cur_dir == 1) { // R과 연관
					
				}
				else if(cur_dir == 2) { // R과 연관

				}
				else if (cur_dir == 3) { // C와 연관

				}
				else { // C와 연관

				}
			}

		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);

	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z; // d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
		shark[r][c].speed = s;
		shark[r][c].dir = d;
		shark[r][c].size = z;		
	}
	for (int i = 1; i <= C; i++) {
		int pos = i; // 낚시왕의 위치
		catchShark(pos);
		moveShark();
		memset(visit, false, sizeof(visit));
		
	}


	cout << sum;
}