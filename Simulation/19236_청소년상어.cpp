#include<iostream>
#include<algorithm>
using namespace std;
struct FISH {
	int y;
	int x;
	int dir;
};

struct SHARK {
	int y;
	int x; 
	int dir;
};
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int ret;
void solve(int board[4][4], FISH fish[16], int shark_y, int shark_x, int sum) {
	// 백트래킹
	int candi_board[4][4];
	FISH candi_fish[16];

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			candi_board[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 16; i++) {
		candi_fish[i] = fish[i];
	}*/

	memcpy(candi_board, board, sizeof(candi_board));
	memcpy(candi_fish, fish, sizeof(candi_fish));
	
	// eat : 상어한테 주금
	int fish_number = candi_board[shark_y][shark_x];
	int shark_dir = candi_fish[fish_number].dir; 
	//candi_fish[fish_number].is_alive = false;
	candi_fish[fish_number].y = -1;
	candi_fish[fish_number].x = -1;
	candi_fish[fish_number].dir = -1;
	candi_board[shark_y][shark_x] = -1;

	sum += (fish_number+1);
	ret = max(ret, sum);

	// fish move
	for (int f = 0; f < 16; f++) {
		//if (!candi_fish[f].is_alive) continue; // 이미 죽은 물고기
		if (candi_fish[f].y==-1) continue; // 이미 죽은 물고기

		int cy = candi_fish[f].y;
		int cx = candi_fish[f].x;
		int cd = candi_fish[f].dir;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd;

		while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}
		if (candi_board[ny][nx] != -1) { // 움직이려는 곳에 물고기가 있음 : 물고기랑 위치 변경
			int target = candi_board[ny][nx];
			candi_fish[target].y = cy;
			candi_fish[target].x = cx;
			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			// board에서 물고기 위치 변경
			candi_board[ny][nx] = f;
			candi_board[cy][cx] = target;
		}
		else { // 물고기가 없음 : 빈칸이므로 그곳으로 직진
			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			candi_board[ny][nx] = f;
			candi_board[cy][cx] = -1;
 		}
	}
	// shark move
	for (int step = 1; step < 4; step++) {
		int ny = shark_y + dy[shark_dir] * step; // 상어의 이동방향으로 1,2,3 칸 
		int nx = shark_x + dx[shark_dir] * step;
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) { break; } // 벽을 넘어감
		if (candi_board[ny][nx] != -1) { // 물고기가 있는 경우
			solve(candi_board, candi_fish, ny, nx, sum);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int board[4][4];
	FISH fishes[16];
	SHARK shark;
	for (int i = 0; i < 4; i++) {
		int num, dir;
		for (int j = 0; j < 4; j++) {
			cin >> num >> dir;
			num--;  dir--;
			board[i][j] = num;
			fishes[num].y = i;
			fishes[num].x = j;
			fishes[num].dir = dir;
		}
	}
	
	solve(board, fishes, 0, 0, 0);
	cout << ret << endl;
}