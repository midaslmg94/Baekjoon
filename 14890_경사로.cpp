#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
using namespace std;
int map[MAX][MAX];
int rand[MAX][MAX]; // 경사로가 놓였는지 확인
int N;
int L;//경사로
int ans;
void make_land(int x, int y, int slide) {
	// 경사로를 뒤로 설치할껀지 앞으로 설치할껀지 확인
	int dist = 1;
	queue<pair<int, int>>q;
	if (slide) { // 오르막길

	}
	else { // 내리막길
		q.push({ x, y+1});
		for (int j = y + 1; j < N - 1; j++) {
			if (map[x][j] == map[x][j + 1]) {
				dist++;
				q.push({ x,j+1});
				if (dist == L) { // 경사로 설치가능

				}
			}
			else {
				break;
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//가로 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] > map[i][j + 1]) { // 내리막
				make_land(i, j, 0);
				break;
			}
			if (map[i][j] < map[i][j + 1]) { // 오르막
				make_land(i, j, 1);
				break;
			}
		}
		ans++; // 길이 같은 높이로 쭉 이어져 있다는 것
	}




	//세로 확인
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {

		}
	}

	cout << ans;
}