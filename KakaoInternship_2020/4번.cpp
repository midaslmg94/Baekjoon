#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
int MAP[25][25][5];  // 진행중인 방향
bool visited[25][25];
int dy[4] = {-1, 1, 0, 0};  // 상하좌우
int dx[4] = {0, 0, -1, 1};
//직선 도로 하나를 만들 때는 100원이 소요되며, 코너를 하나 만들 때는 500
int solution(vector<vector<int>> board) {
    int answer = INF;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                MAP[i][j][k] = INF;
            }
        }
    }
    for (int k = 0; k < 4; k++) {
        MAP[0][0][k] = 0;
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        visited[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            int ndir = k;
            if (0 > ny || ny > n - 1 || 0 > nx || nx > n - 1) continue;
            if (board[ny][nx] == 1) continue;  // 벽은 진행 불가          
            if (dir == ndir) {  // 그대로 전진
                if (MAP[ny][nx][ndir] > MAP[y][x][dir] + 100) {
                    MAP[ny][nx][ndir] = MAP[y][x][dir] + 100;
                    q.push({{ny, nx}, ndir});
                }                
            } else {  // 방향이 바뀜
                if (MAP[ny][nx][ndir] > MAP[y][x][dir] + 600) {
                    MAP[ny][nx][ndir] = MAP[y][x][dir] + 600;
                    q.push({{ny, nx}, ndir});
                } 
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = min(answer, MAP[n - 1][n - 1][i]);
    }
    return answer-500;
}
int main() {
    ios::sync_with_stdio(false);
    vector<vector<int>> b = {
        /*{0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}*/
        {0,0,0},
        {0,0,0},
        {0,0,0}      

    };
    int ans = solution(b);
    cout << ans;
    return 0;

    /*
    테스트 1 〉	통과 (0.00ms, 3.78MB)
테스트 2 〉	통과 (0.01ms, 3.76MB)
테스트 3 〉	통과 (0.00ms, 3.83MB)
테스트 4 〉	통과 (0.01ms, 3.8MB)
테스트 5 〉	통과 (0.01ms, 3.81MB)
테스트 6 〉	통과 (0.04ms, 3.91MB)
테스트 7 〉	통과 (0.03ms, 3.92MB)
테스트 8 〉	통과 (0.02ms, 3.76MB)
테스트 9 〉	통과 (0.03ms, 3.76MB)
테스트 10 〉	통과 (0.03ms, 3.8MB)
테스트 11 〉	통과 (0.17ms, 3.77MB)
테스트 12 〉	통과 (0.07ms, 3.77MB)
테스트 13 〉	통과 (0.02ms, 3.73MB)
테스트 14 〉	통과 (0.01ms, 3.88MB)
테스트 15 〉	통과 (0.04ms, 3.77MB)
테스트 16 〉	통과 (0.06ms, 3.94MB)
테스트 17 〉	통과 (0.07ms, 3.87MB)
테스트 18 〉	통과 (0.09ms, 3.93MB)
테스트 19 〉	통과 (0.07ms, 3.87MB)
테스트 20 〉	통과 (0.05ms, 3.83MB)
테스트 21 〉	통과 (0.03ms, 3.95MB)
테스트 22 〉	통과 (0.01ms, 3.87MB)
테스트 23 〉	통과 (0.01ms, 3.85MB)
    
    */
}