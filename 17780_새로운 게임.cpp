#include<bits/stdc++.h>
#define endl "\n"
#define MAX 14
using namespace std;
struct CHESS { // 체스말의 정보
	int y;
	int x;
	int dir;
	bool bottom;
};
int N, K;
int turn = 0;
int board[MAX][MAX]; // 체스판의 색깔
vector<CHESS>chess;  // 0번말~ n-1번말의 정보
vector<int>v[MAX][MAX]; // 체스판의 상태 v[i][j] = {0,2}이면 [i][j]위치에 0번, 2번 말이 순서대로 있다는 의미. v[i][j][0]이 맨 밑의 말
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };
int changeDir(int n) {
	if (n == 1)return 2;
	if (n == 2)return 1;
	if (n == 3)return 4;
	if (n == 4)return 3;
}
bool isFinish() { // 한 자리에 말이 4개 이상 모여있는지 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j].size() >= 4)return true;
		}
	}
	return false;
}
void moveChess(int y, int x, int ny, int nx) {  // {y,x}에서 {ny,nx}로 말을 전부 옮김
	for (int i = 0; i < v[y][x].size(); i++) {
		v[ny][nx].push_back(v[y][x][i]);
		chess[v[y][x][i]].y = ny;
		chess[v[y][x][i]].x = nx;
	}
	int num = v[ny][nx][0]; // 맨 밑의 말만 true로 해준다
	chess[num].bottom = true;
	for (int i = 1; i < v[ny][nx].size(); i++) {
		num = v[ny][nx][i];
		chess[num].bottom = false;
	}
	v[y][x].clear(); // 이동 전 상태 비워줌
}
void moveReverse(int y, int x, int ny, int nx) {  // 순서가 바뀜 -> 맨 뒤부터 push_back(기존에 있던 말의 순서는 변하지 않음)
	for (int i = v[y][x].size() - 1; i >= 0; i--) {
		v[ny][nx].push_back(v[y][x][i]);
		chess[v[y][x][i]].y = ny;
		chess[v[y][x][i]].x = nx;
	}
	int num = v[ny][nx][0]; // 맨 밑의 말만 true로 해준다
	chess[num].bottom = true;
	for (int i = 1; i < v[ny][nx].size(); i++) {
		num = v[ny][nx][i];
		chess[num].bottom = false;
	}
	v[y][x].clear();
}

void prt() {
	for (int i = 0; i < K; i++) {
		cout << " turn:" << turn << " idx:" << i << " y:" << chess[i].y << " x:" << chess[i].x 
			<< " dir:" << chess[i].dir 
			<<" isBottom:"<<chess[i].bottom<< endl;
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		y--; x--;
		chess.push_back({ y,x,dir,true });
		v[y][x].push_back(i);
	}
	while (true) {		
		turn++;
		for (int i = 0; i < K; i++) { // 0번 말부터 진행
			int y = chess[i].y;
			int x = chess[i].x;
			int dir = chess[i].dir;
			int isBottom = chess[i].bottom;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			//prt(); cout << "-----" << endl;
			if (!isBottom)continue; // 맨 밑이 아니면 이동불가
			if (0 > ny || ny >= N || 0 > nx || nx >= N) { // 범위 초과 -> 파란색과 똑같이 진행				 
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir = ndir;
				if (0 > ny || ny >= N || 0 > nx || nx >= N) continue; // 범위 초과 -> 방향만 바뀌고 좌표는 그대로				
				if (board[ny][nx] == 0) { // 흰색 : 그냥 진행
					moveChess(y, x, ny, nx);
				}
				else if (board[ny][nx] == 1) { // 빨간색 : 말의 순서를 바꾸고 진행
					moveReverse(y, x, ny, nx);
				}
				else if (board[ny][nx] == 2)continue; // 진행하려는 방향이 또 파란색이면 방향만 바뀜				
			}
			else if (board[ny][nx] == 0) { // 흰색 : 그냥 진행
				moveChess(y, x, ny, nx);
			}
			else if (board[ny][nx] == 1) { // 빨간색 : 말의 순서를 바꾸고 진행
				moveReverse(y, x, ny, nx);
			}
			else { // 파란색 : 방향 바꾸고 1칸 전진 
				int ndir = changeDir(dir);
				ny = y + dy[ndir];
				nx = x + dx[ndir];
				chess[i].dir = ndir;
				if (0 > ny || ny >= N || 0 > nx || nx >= N) continue; // 범위 초과 -> 방향만 바뀌고 좌표는 그대로				
				if (board[ny][nx] == 0) { // 흰색 : 그냥 진행
					moveChess(y, x, ny, nx);
				}
				else if (board[ny][nx] == 1) { // 빨간색 : 말의 순서를 바꾸고 진행
					moveReverse(y, x, ny, nx);
				}
				else if (board[ny][nx] == 2)continue; // 진행하려는 방향이 또 파란색이면 방향만 바뀜				
			}

			// 한 자리에 말이 다 모여있는지 확인
			if (isFinish()) { // 말이 전부 모여있음
				cout << turn;
				return 0;
			}
		}
		
		if (turn > 1000) { // 제한시간 초과
			cout << -1;
			return 0;
		}
	}
}