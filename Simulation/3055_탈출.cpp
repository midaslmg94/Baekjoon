#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
/*
비어있는 곳은 '.'로 표시되어 있고, 
물이 차있는 지역은 '*', 
돌은 'X'로 표시되어 있다. 
비버의 굴은 'D'로, 
고슴도치의 위치는 'S'로 나타내어져 있다.
고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간
*/
struct INFO {
    char state;
    bool isWater;
    bool isBeaver;
};

INFO Map[51][51];
int r, c;
int startY, startX;
int endY, endX;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<pair<int, int>> water;
int answer = 0;
void bfs(int y, int x) {
    queue<pair<int, int>> beaver;
    beaver.push({y, x});
    while (!beaver.empty()) {
        answer++;
        for (int dir = 0; dir < 4; dir++) { // 고슴도치 밑에 있으면 끝
            int ndy = endY + dy[dir];
            int ndx = endX + dx[dir];
            if (0 > ndy || ndy > r - 1 || 0 > ndx || ndx > c - 1) continue;
            if (Map[ndy][ndx].isBeaver) {
                cout << answer;
                return;
            }
        }

        // 고슴도치 이동

        int beaver_spread = beaver.size();
        for (int i = 0; i < beaver_spread; i++) {
            int by = beaver.front().first;
            int bx = beaver.front().second;            
            //visited[by][bx] = true;
            beaver.pop();
            if (Map[by][bx].isBeaver == false) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nby = by + dy[dir];
                int nbx = bx + dx[dir];
                if (0 > nby || nby > r - 1 || 0 > nbx || nbx > c - 1 || Map[nby][nbx].isBeaver) continue;
                if (Map[nby][nbx].state == 'X' || Map[nby][nbx].state == '*') continue;
                if (Map[nby][nbx].state == 'D') {
                    cout << answer;
                    return;
                }
                beaver.push({nby, nbx});
                Map[nby][nbx].isBeaver = true;
                Map[nby][nbx].state = 'S';
                //visited[nby][nbx] = true;
            }
            // for (int a = 0; a < r; a++) {
            //     for (int b = 0; b < c; b++) {
            //         cout << Map[a][b].state << ' ';
            //     }
            //     cout << endl;
            // }
            // cout << "\n******************************\n";
        }
        // 물이 먼저 확산
        int water_spread = water.size();
        for (int i = 0; i < water_spread; i++) {
            int wy = water.front().first;
            int wx = water.front().second;
            Map[wy][wx].isWater = true;
            Map[wy][wx].state = '*';
            water.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nwy = wy + dy[dir];
                int nwx = wx + dx[dir];
                if (0 > nwy || nwy > r - 1 || 0 > nwx || nwx > c - 1) continue;
                if (Map[nwy][nwx].state == 'X' || Map[nwy][nwx].state == 'D' || Map[nwy][nwx].isWater) continue;
                water.push({nwy, nwx});
                Map[nwy][nwx].state = '*';
                Map[nwy][nwx].isWater = true;
                if (Map[nwy][nwx].isBeaver) {
                    Map[nwy][nwx].isBeaver = false;
                }
            }
        }
    }
    cout << "KAKTUS";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> Map[i][j].state;
            if (Map[i][j].state == 'S') {
                startY = i;
                startX = j;
                Map[i][j].isBeaver = true;
            } else if (Map[i][j].state == '*') {
                Map[i][j].isWater = true;
                water.push({i, j});
            } else if (Map[i][j].state == 'D') {
                endY = i;
                endX = j;
            }
        }
    }
    bfs(startY, startX);
    return 0;
}