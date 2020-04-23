#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
#define pii pair<int, int>
using namespace std;
int n, m;
vector<vector<int>> board;
vector<pair<int, int>> island[MAX];  // 각 섬의 위치를 저장. 섬의 개수는 최대 6개
bool visit[MAX][MAX];
int dist[MAX][MAX];  // i번 섬에서 j번 섬으로 가는 최단 거리
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0;
int idx = 0;
bool visited[MAX];  // MST에 필요한 배열
int prim(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    visited[start] = true;
    for (int i = start; i <= idx; i++) {
        if (dist[start][i] != MAX) {  // 연결된 곳을 저장
            pq.push(make_pair(dist[start][i], i));
        }
    }
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        answer += cost;
        for (int j = 1; j <= idx; j++) {
            if (dist[cur][j] != MAX) {
                pq.push(make_pair(dist[cur][j], j));
            }
        }
    }
    return answer;
}
void masking(int y, int x, int idx) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visit[y][x] = true;
    board[y][x] = idx;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        island[idx].push_back(make_pair(y, x));  // idx번 섬의 위치를 저장
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (0 > ny || ny > n - 1 || 0 > nx || nx > m - 1) continue;
            if (visit[ny][nx] || board[ny][nx] == 0) continue;
            visit[ny][nx] = true;
            board[ny][nx] = idx;
            q.push(make_pair(ny, nx));
        }
    }
}
void connect(int idx) {
    for (int i = 0; i < island[idx].size(); i++) {
        int y = island[idx][i].first;
        int x = island[idx][i].second;
        visit[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            int cnt = 0;  // 해당 지점에서 다른 섬을 만나기 까지 걸린 시간
            while (0 <= ny && ny <= n - 1 && 0 <= nx && nx <= m - 1) {
            //cout << "idx : " << idx << " cnt :"<<cnt<<" y : " << y << " x : " << x << ' ' << " ny : " << ny << " nx : " << nx << ' ' <<endl;
                if (board[ny][nx] == idx)
                    break;                      // 같은 섬이면 진행 불가
                else if (board[ny][nx] == 0) {  // 빈 공간이면 그대로 쭉 직진
                    ny += dy[k];
                    nx += dx[k];
                    cnt++;
                } else if (board[ny][nx] != 0) {      // 다른 섬을 만났다
                    if (cnt <= 1) break;              // 거리가 1은 안된다.
                    int next_island = board[ny][nx];  // 만난 섬
                  // cout<<ny<<' '<<nx<<' '<<dist[idx][next_island]<<' '<<cnt<<endl;
                    dist[idx][next_island] = min(dist[idx][next_island], cnt);
                    //dist[next_island][idx] = min(dist[next_island][idx], cnt);
                    break;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            t.push_back(tmp);            
        }
        board.push_back(t);
    }
    
    // 섬 구분
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && board[i][j] != 0) {
                masking(i, j, ++idx);
            }
        }
    }
    for(int i=1; i<=idx; i++){
        for(int j=1; j<=idx; j++){
            dist[i][j] = MAX;  // i번 섬부터 j번 섬까지 거리 최대로 초기화
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout<<endl<<endl;
    memset(visit, false, sizeof(visit));
    // 섬의 모든 지점에서 시작하여, 다른 섬으로 가는 최단 거리를 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && board[i][j] != 0) {
                connect(board[i][j]);
            }
        }
    }
    // cout<<endl<<endl;
    // for (int i = 1; i <= idx; i++) {
    //     for (int j = 1; j <= idx; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // MST로 정답 찾기
    prim(1);
    for(int i=1; i<=idx; i++){ // 연결 안된 지점이 있음
        if(!visited[i]){
            cout<<-1;
            return 0;
        }
    }
    if (answer == 0) {
        cout << -1;
        return 0;
    }
    cout << answer;
    return 0;
}