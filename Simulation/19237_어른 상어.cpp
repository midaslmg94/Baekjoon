#include<iostream>
#include<vector>
using namespace std;

int dy[4] = { -1,1,0,0 }; // 위, 아래, 왼쪽 오른쪽
int dx[4] = { 0,0,-1,1 }; 
struct INFO {
	int idx; // 해당 위치에 냄새를 뿌린 상어 번호
	int time;  // 냄새가 지속되는 시간
};

struct SHARK {
	int idx; // 상어 번호
	int y;
	int x;
	int dir; // 상어가 보고 있는 방향
};

int N, M, K;
INFO board[21][21]; // 상어의 번호, 상어가 뿌린 냄새
SHARK shark[401]; // 상어의 정보
bool life_check[401]; // 상어가 죽었는지 확인
int shark_priority[401][4][4]; // 상어의 이동 우선순위
int answer = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j].idx;
			if (board[i][j].idx != 0) {
				int num = board[i][j].idx; // 상어번호는 1번부터 시작
				shark[num].y = i;
				shark[num].x = j;
				shark[num].idx = num;				
				life_check[num] = true;
			}
		}
	}
	// 시작 시 상어가 보고있는 방향
	for (int i = 1; i <= M; i++) {		
		cin >> shark[i].dir;
		shark[i].dir--;
	}

	// 상어의 이동 우선순위
	for (int i = 1; i <= M; i++) {
		int tmp;	
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> tmp;				
				tmp--;  // 인덱스를 0부터 하기 위해
				shark_priority[i][j][k] = tmp; // i번 상어가 j의 방향을 바라볼때 우선순위 순서
			}
		}
	}
	int cnt = 0;
	int kill_shark = 0;
	while (cnt <= 1000) {
		
		if (kill_shark == M - 1) {  
			break;
		}
        // 죽은 상어를 위처럼 표시 안하고 아래처럼 하니 틀렸었다.
        // bool flag = true;
		// // 1번을 제외한 다른 상어들이 죽어있는지 확인
		// for (int i = 2; i <= M; i++) {
		// 	if (life_check[i]) { // 살아있는 상어가 있음
		// 		flag = false;
		// 		break;
		// 	}
		// }
		// if (flag) { // 1번만 살고 나머지 다 죽음
		// 	cout << cnt;
		// 	return 0;
		// }
		// 현 위치에서 냄새뿌림
		for (int i = 1; i <= M; i++) {
			if (!life_check[i]) continue; // 죽은 상어는 못뿌림
			board[shark[i].y][shark[i].x].idx = i; // i번 상어가 
			board[shark[i].y][shark[i].x].time = K; // k만큼의 시간이 지속되는 냄새 뿌림
		}
		for (int i = 1; i <= M; i++) {
			if (!life_check[i])continue; // 죽은 상어는 움직이지 않음
			// 인접 칸 중 아무 냄새가 없는 칸을 찾는다.						
			bool canGo = false;
			for (int d = 0; d < 4; d++) { // 상하좌우 중 빈 칸이 있는지 확인 -> 우선순위에 맞게 탐색
				int next_dir = shark_priority[shark[i].idx][shark[i].dir][d];
				int ny = shark[i].y + dy[next_dir];
				int nx = shark[i].x + dx[next_dir];
				if (0 > ny || ny >= N || 0 > nx || nx >= N)continue;
				if (board[ny][nx].idx == 0) { // 빈 칸이 있음
					canGo = true;
					shark[i].y = ny;
					shark[i].x = nx;
					shark[i].dir = next_dir;
					break;
				}
			}
			if (!canGo) {
				for (int d = 0; d < 4; d++) { // 빈칸이 없다면 자신의 냄새가 있는 칸의 방향을 확인 -> 우선순위에 맞게 탐색					
					int next_dir = shark_priority[shark[i].idx][shark[i].dir][d];
					int ny = shark[i].y + dy[next_dir];
					int nx = shark[i].x + dx[next_dir];
					if (0 > ny || ny >= N || 0 > nx || nx >= N )continue;
					if (board[ny][nx].idx == shark[i].idx) {
						shark[i].y = ny;
						shark[i].x = nx;
						shark[i].dir = next_dir;
						break;
					}
				}
			}
		}

		// 겹치는 상어가 있는지 확인 : 이 부분에서 계속 틀렸었다. 
        // 살아있는 애들만 비교를 해줘야 한다.  && life_check[i] && life_check[j] 를 체크해주자
		for (int i = 1; i <= M; i++) {
			for (int j = i+1; j <= M; j++) {
				if (shark[i].y == shark[j].y && shark[i].x == shark[j].x && life_check[i] && life_check[j]) {
					life_check[j] = false; // 번호가 큰 상어는 무조건 죽음
					kill_shark++;
					/*if (shark[i].idx < shark[j].idx) {
						life_check[j] = false;
					}
					else {
						life_check[i] = false;
					}*/
				}
			}
		}

		// 냄새 1씩 감소
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j].time > 0) { // 죽은 상어의 냄새도 지속된다
					board[i][j].time--;
				}
				if (board[i][j].time == 0) { // 냄새가 없어지면 번호 초기화
					board[i][j].idx = 0;  
				}
			}
		}
		cnt++;
	}

	if (cnt <= 1000) {
		answer = cnt;
	}
	cout << answer; // 1000초가 넘음
	return 0;
}