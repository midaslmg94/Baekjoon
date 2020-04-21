#include <bits/stdc++.h>
#define endl "\n"
#define MAX 100
using namespace std;
int n, m;
int board[MAX][MAX];
int outair[MAX][MAX];
bool visit[MAX][MAX];
int cheese_cnt = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void go_out() {  // 바깥 공기는 -1로 바꿈
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visit[0][0] = true;
    outair[0][0] = -1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 > ny || ny > n - 1 || 0 > nx || nx > m - 1) continue;
            if (visit[ny][nx] || board[ny][nx] == 1) continue;  // 이미 방문 한 곳, 치즈
            visit[ny][nx] = true;
            outair[ny][nx] = -1;
            q.push(make_pair(ny, nx));
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) cheese_cnt++;
        }
    }
    int turn = 1;
    while (cheese_cnt >= 1) {
        // 바깥 공기 체크
        go_out();
        memset(visit, false, sizeof(visit));
        // 공기와 맞닿은 치즈가 녹음
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        if (outair[i + dy[k]][j + dx[k]] == -1) { //바깥 공기와 맞닿아 있다면
                            board[i][j] = 0;
                            cnt++; // 1개 녹음
                            break;
                        }
                    }
                }
            }
        }
        // 남아있던 치즈와 녹은 치즈의 개수가 같음
        if (cheese_cnt == cnt) {
            cout << turn << endl;
            cout << cheese_cnt;
            return 0;
        }
        turn++;
        cheese_cnt -= cnt;        
        memset(outair, 0, sizeof(outair));        
    }
}
