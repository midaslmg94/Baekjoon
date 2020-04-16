#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100
using namespace std;
int castle[MAX][MAX];
int visit[MAX][MAX][2]; // i,j번째 위치에서 칼이 없으면 0에, 칼이 있으면 1에 값 저장
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m, limit_time;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> limit_time;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> castle[i][j];
			visit[i][j][0] = -1;
			visit[i][j][1] = -1;			
		}
	}
	queue<pair<pair<int, int>,int>>q; // y좌표,x좌표,칼이 있는지 없는지
	q.push({ { 0,0 },0 });
	visit[0][0][0] = 0;
	int t = 0;
	int answer = 987654;
	while (t <= limit_time) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first.first;
			int x = q.front().first.second;
			int sword = q.front().second;
			q.pop();
			if (y == n - 1 && x == m - 1) { // 공주 찾음
				answer = min(answer, visit[y][x][sword]);
			}
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
				if (visit[ny][nx][sword] != -1)continue;
				if (castle[ny][nx] == 0) { // 빈 공간
					if (sword == 1) { // 현재 칼이 있음
						q.push({ { ny,nx },1 });
						visit[ny][nx][sword] = visit[y][x][sword] + 1;		
					}
					else {						
						q.push({ { ny,nx },0 }); // 현재 칼이 없음
						visit[ny][nx][sword] = visit[y][x][sword] + 1;		
					}
				}
				else if (castle[ny][nx] == 1) { // 벽
					if (sword == 1) { // 칼이 있는 경우에만 진행 가능
						q.push({ { ny,nx },1 });
						visit[ny][nx][sword] = visit[y][x][sword] + 1;
					}
				}
				else { // 칼
					q.push({ { ny,nx },1 });
					visit[ny][nx][1] = visit[y][x][sword] + 1;
				}
			}
		}
		t++;
	}
	if (answer == 987654)
		cout << "Fail";
	else
		cout << answer;
	return 0;
}