#include<bits/stdc++.h>
#define endl "\n"
#define MAX 40
using namespace std;
int n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int sticky[10][10];
int r, c; // 스티커의 가로 세로길이

void rotate() { // 90도 회전 --> 이 부분은 공식같은게 있을 거 같은데..
	// 가로 세로의 길이가 서로 바뀐다
	int sticky_rotate[10][10];
	memcpy(sticky_rotate, sticky, sizeof(sticky));
	for(int )

}
bool canAttach() { // 스티커를 붙일 수 있는지 확인

}
void attach() {
	// 좌상단부터 스티커가 들어갈 위치 확인

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	while(k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticky[i][j];
			}
		}
		attach();
	}





	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1)
				answer++;
		}
	}
	cout << answer;
	return 0;
}