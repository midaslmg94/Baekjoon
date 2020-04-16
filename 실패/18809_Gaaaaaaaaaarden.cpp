#include <bits/stdc++.h>
#define endl "\n"
#define MAX 50
#define pii pair<int,int>
using namespace std;
struct GROUND {//땅의 상태
	int state; // 0:호수, 1:배양액을 뿌릴수 없음, 2:배양액을 뿌릴 수 있음
	int red; // 빨간색 배양액이 뿌려진 시점
	int green; // 초록색 배양액이 뿌려진 시점
	bool flower; // 꽃이 피어나는지 확인
};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, g, r;
GROUND ground[MAX][MAX];
vector<pii>candi_space; // 배양액 심을 수 있는 땅(최대 10개)
int answer = -1;


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j].state;
			ground[i][j].red = -1;
			ground[i][j].green = -1;
			ground[i][j].flower = false;
			if (ground[i][j].state == 2) {
				candi_space.push_back({ i,j });
			}
		}
	}
	

	cout << answer;
	return 0;
}