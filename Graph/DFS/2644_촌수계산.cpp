#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n, m, x, y;
int start, finish;
int Map[101][101];
bool visited[101][101];
vector<int> v[101];
bool flag;
void dfs(int start, int cnt) {
    if (start == finish) {
        cout << cnt;
        flag = true;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(Map[start][i]==0)continue;
        if(visited[start][i])continue;
        visited[start][i]=true;
        visited[i][start]=true;
        dfs(i,cnt+1);
        visited[start][i]=false;
        visited[i][start]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> start >> finish;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        Map[x][y] = 1;
        Map[y][x] = 1;
    }
    dfs(start, 0);
    if(!flag)cout<<-1;
    return 0;
}