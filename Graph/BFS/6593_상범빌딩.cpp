#include <bits/stdc++.h>
#define endl "\n"
#define MAX 31
using namespace std;
struct INFO {
    int y;
    int x;
    int f;  // 현재 몇층인지
    int t; // 여기오는데 걸리는 시간
};

int L, R, C;
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {1, -1, 0, 0, 0, 0};
int df[6] = {0, 0, 0, 0, 1, -1};
char building[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int bfs(INFO start) {
    queue<INFO> q;
    q.push(start);
    visited[start.y][start.x][start.f] = true;
    int answer = 0;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int f = q.front().f;
        int t = q.front().t;
        q.pop();
        if (building[y][x][f] == 'E') return t;
        for (int dir = 0; dir < 6; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            int nf = f + df[dir];
            if (0 > ny || ny > R - 1 || 0 > nx || nx > C - 1 || 0 > nf || nf > L - 1 || visited[ny][nx][nf]) continue;
            if (building[ny][nx][nf] == '#') continue;
            visited[ny][nx][nf] = true;
            q.push({ny, nx, nf,t+1});
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    while (true) {
        memset(visited, false, sizeof(visited));
        cin >> L >> R >> C;
        if (L == 0 && R == 0 & C == 0) break;
        INFO start, finish;
        for (int k = 0; k < L; k++) {          // 몇 층
            for (int i = 0; i < R; i++) {      // y좌표
                for (int j = 0; j < C; j++) {  // x좌표
                    cin >> building[i][j][k];
                    if (building[i][j][k] == 'S') {
                        start.y = i;
                        start.x = j;
                        start.f = k;
                        start.t = 0;
                    }
                }
            }            
        }
        int res = bfs(start);
        if (res != 0) {
            cout << "Escaped in " << res << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}