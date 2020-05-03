#include <bits/stdc++.h>
#define endl "\n"
#define MAX 50
#define pii pair<int, int>
#define INF 987654231
using namespace std;
int n, m;
int MAP[MAX][MAX][2];  // 해당 지점의 상태와, 해당 지점에 바이러스가 퍼진 시간
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<pii> virous;
bool visit[MAX];         // dfs
bool visited[MAX][MAX];  // bfs
vector<int> result;
int answer = INF;
int empty_cnt = 0;
bool canGo(int y, int x) {
    if (0 > y || y > n - 1 || 0 > x || x > n - 1) return false;  // 범위 초과
    if (MAP[y][x][0] == 1) return false;                         // 벽은 진행 불가
    if (visited[y][x] || MAP[y][x][1] != -1) return false;       // 이미 방문지점 진행 불가
    return true;
}
void prt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << MAP[i][j][1] << '\t';
        }
        cout << endl;
    }
    cout << "\n================================\n";
}
int bfs(vector<int> virous_pos) {
    int spread_cnt = 0;
    queue<pii> q;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < virous_pos.size(); i++) {
        q.push(make_pair(virous[virous_pos[i]].first, virous[virous_pos[i]].second));
        MAP[virous[virous_pos[i]].first][virous[virous_pos[i]].second][1] = 0;
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        visited[y][x] = true;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (!canGo(ny, nx)) continue;     
            if(MAP[ny][nx][0]==0) spread_cnt++;   
            MAP[ny][nx][1] = MAP[y][x][1] + 1;
            q.push(make_pair(ny, nx));
        }
        if(spread_cnt==empty_cnt)break;
    }
    // 바이러스 퍼진 시간 초기화, 모든 지점에 바이러스가 퍼졌는지 확인
    //prt();
    bool flag = false;
    int res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (MAP[i][j][0] == 0 && MAP[i][j][1] == -1) flag = true;  // 빈공간인데, 시간이 -1임
            res = max(res, MAP[i][j][1]);
            MAP[i][j][1] = -1;            
        }
    }
    //cout<<"RESULT "<<res<<endl;
    if (flag) return INF;  // 안퍼진 지점이 있다
    return res;
}

void dfs(int idx, int cnt) {  // 활성 바이러스 뽑기
    if (cnt == m) {
        answer = min(answer, bfs(result));
        return;
    }
    for (int i = idx; i < virous.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            result.push_back(i);
            dfs(i + 1, cnt + 1);
            visit[i] = false;
            result.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j][0];  // 해당 지점의 상태
            MAP[i][j][1] = -1;    // 해당 지점의 바이러스가 퍼진 시간 초기화
            if (MAP[i][j][0] == 0) empty_cnt++;
            if (MAP[i][j][0] == 2) virous.push_back(make_pair(i, j));
        }
    }
    if(empty_cnt==0){
        cout<<0;
        return 0;
    }
    dfs(0, 0);
    if (answer == INF) {
        cout << -1;
        return 0;
    }
    cout << answer;
    return 0;
}