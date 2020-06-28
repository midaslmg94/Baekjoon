#include <bits/stdc++.h>
#define endl "\n"
#define MAX 100
#define pii pair<int, int>
using namespace std;
vector<vector<int>> board;
bool visited[MAX][MAX];
int answer = 0;
int n = board.size();

int dy[2] = {0, -1};  // 옆, 아래
int dx[2] = {1, 0};

// 회전
int rotate_dy[] = {-1, 1, 0, 0};  // 'ㅡ' 블럭 위쪽 방향, 아래 방향 '|' 블럭 위쪽 방향, 아래쪽 방향
int rotate_dx[] = {0, 0, -1, 1};

bool boundary(int y, int x, int yy, int xx) {
    if (0 > y || yy > n - 1 || 0 > x || xx > n - 1) return false;  // 경계선 초과
    return true;
}
int solution(vector<vector<int>> board) {
    // 위아래왼오 다 확인
    queue<pair<pii, pii>> q;  // 앞, 뒤 좌표
    q.push({{0, 0}, {0, 1}});
    int t = 0;
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int yy = q.front().second.first;
        int xx = q.front().second.second;
        visited[y][x] = true;
        visited[yy][xx] = true;
        q.pop();
        if (yy == n - 1 && xx == n - 1) break;
        // 옆, 아래 이동
        for (int k = 0; k < 2; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            int nyy = yy + dy[k];
            int nxx = xx + dx[k];
            if (!boundary(ny, nx, nyy, nxx)) continue;
            if (visited[ny][nx] && visited[nyy][nxx]) continue;
            if (board[ny][nx] == 0 && board[nyy][nxx] == 0) {  // 이동 가능
                q.push({{ny, nx}, {nyy, nxx}});
            }
        }
        // 회전해서 이동
        if (y == yy) {  // ㅡ 모양 블럭
            for (int k = 0; k < 2; k++) {
                int ny = y + rotate_dy[k];
                int nx = x + rotate_dx[k];
                int nyy = yy + rotate_dy[k];
                int nxx = xx + rotate_dx[k];
                if (!boundary(ny, nx, nyy, nxx)) continue;
                if (visited[ny][nx] && visited[nyy][nxx]) continue;
                if (board[ny][nx] == 0 && board[nyy][nxx] == 0) {  // 이동 가능
                    if(k==0){ // 왼쪽 위로 세워짐
                        q.push({})
                    }
                    else{ // 오른쪽 위로 세워짐

                    }
                    
                }
            }

        } else {  // | 모양 블럭
            for (int k = 2; k < 4; k++) {
                int ny = y + rotate_dy[k];
                int nx = x + rotate_dx[k];
                int nyy = yy + rotate_dy[k];
                int nxx = xx + rotate_dx[k];
                if (!boundary(ny, nx, nyy, nxx)) continue;
                if (visited[ny][nx] && visited[nyy][nxx]) continue;
                if (board[ny][nx] == 0 && board[nyy][nxx] == 0) {  // 이동 가능
                    q.push({{ny, nx}, {nyy, nxx}});
                }
            }
        }
        cout << "dㅇㅇㅇ" << endl;
        answer++;
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    board = {{0, 0, 0, 1, 1},
             {0, 0, 0, 1, 0},
             {0, 1, 0, 1, 1},
             {1, 1, 0, 0, 1},
             {0, 0, 0, 0, 0}};

    int ans = solution(board);
    cout << ans;
    return 0;
}