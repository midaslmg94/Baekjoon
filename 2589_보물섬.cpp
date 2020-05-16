#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
#define MAX 50
using namespace std;
char Map[MAX][MAX];
int Backup[MAX][MAX];
vector<pii> land;
bool visited[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m;
// 유니온 파인드로 하는 방법은 없을까..
void dfs(int y, int x, int idx) {
    Backup[y][x] = idx;
    visited[y][x] = true;
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (0 > ny || ny > n - 1 || 0 > nx || nx > m - 1) continue;
        if (visited[ny][nx]) continue;
        if (Map[ny][nx] == 'W') continue;
        dfs(ny, nx, idx);
    }
}

int bfs(int y, int x) {
    int idx = Backup[y][x];
    int dist = 0;
    queue<pair<pii, int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = true;
    while (!q.empty()) {
        y = q.front().first.first;
        x = q.front().first.second;
        dist = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 > ny || ny > n - 1 || 0 > nx || nx > m - 1) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == 'W') continue;
            visited[ny][nx] = true;
            q.push({{ny, nx}, dist + 1});
        }
    }
    return dist;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            Map[i][j] = str[j];
        }
    }
    // dfs로 구간 나누기 -> 안해도 된다 
    int gugan = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'L' && Backup[i][j] == 0) {
                //dfs(i, j, gugan++);
            }
        }
    }
    // bfs로 최단거리 탐색
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'L') {
                memset(visited, false, sizeof(visited));
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
    return 0;
}