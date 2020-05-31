#include <bits/stdc++.h>
#define endl "\n"
#define MAX 20
#define pii pair<int, int>
using namespace std;
struct INFO {
    int y;
    int x;
    int dist;
};
int w, h;
char Map[MAX][MAX];
bool visited[MAX][MAX][1 << 11];  // 10000000000(2)   2^11  1000 = 2^3 --> 1<<3  100011
// visited[20][20][2048]   visited[3][3][3]
// 0 0 0 0  ,  0...0 1 1 0  => 3   0 ... 1 1 1 0 => 7
//       0...00110
// 1<<3       1000
//         0..1110 OR 연산
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0 - 1, 1};

int bfs(int dirty_y, int dirty_x, int robot_y, int robot_x) {
    int res = 0;
    queue<INFO> q;
    q.push({robot_y, robot_x, 0});
    visited[robot_y][robot_x][0] = true;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int dist = q.front().dist;
        if (y == dirty_y && x == dirty_x) {
            return res;
        }
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 > ny || ny > h - 1 || 0 > nx || nx > w - 1) continue;
            if(Map[ny][nx]=='x')continue;
            if (Map[ny][nx] == 'o') {
            } else if (Map[ny][nx] == '*') {
            } else {
                q.push({ny, nx, dist + 1});
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) return 0;
        vector<pii> dirty;
        queue<INFO> robot;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> Map[i][j];
                if (Map[i][j] == '*') {
                    dirty.push_back({i, j});
                } else if (Map[i][j] == 'o') {
                    robot.push({i, j, 0});  // y좌표, x좌표, 이동거리
                }
            }
        }
        // 청소할 방의 순서 고르기 -> 순열
        int answer = 1e9;
        do {
            int res = 0;
            for (int i = 0; i < dirty.size(); i++) {
                res += bfs(dirty[i].first, dirty[i].second, robot.front().y, robot.front().x);
            }
            answer = min(answer, res);
        } while (next_permutation(dirty.begin(), dirty.end()));
        if (answer == 1e9)
            cout << -1 << endl;
        else
            cout << answer << endl;
    }
    return 0;
}