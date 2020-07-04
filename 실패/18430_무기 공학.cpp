#include <bits/stdc++.h>
#define MAX 5
#define endl "\n"
using namespace std;
int n, m;
int Map[MAX][MAX];
bool visited[MAX][MAX];

int rightUp(int y, int x) {
    int res = 2 * Map[y][x];
    res += Map[y][x - 1] + Map[y + 1][x];
    return res;
}
int rightDown(int y, int x) {
    int res = 2 * Map[y][x];
    res += Map[y - 1][x] + Map[y][x - 1];
    return res;
}
int leftUp(int y, int x) {
    int res = 2 * Map[y][x];
    res += Map[y][x + 1] + Map[y + 1][x];
    return res;
}
int leftDown(int y, int x) {
    int res = 2 * Map[y][x];
    res += Map[y - 1][x] + Map[y][x + 1];
    return res;
}
int ans = 0;

void dfs(int y, int x, int sum) {
    if (y + 1 < n && x - 1 >= 0) {
        sum += rightUp(y, x);
        ans = max(ans, sum);
        visited[y][x] = true;
        visited[y][x - 1] = true;
        visited[y + 1][x] = true;
        dfs(y, x + 1, sum);
        sum -= rightUp(y, x);
        visited[y][x] = false;
        visited[y][x - 1] = false;
        visited[y + 1][x] = false;
    }
    if (y - 1 >= 0 && x - 1 >= 0) {
        sum += rightDown(y, x);
        ans = max(ans, sum);
        visited[y][x] = true;
        visited[y - 1][x] = true;
        visited[y][x - 1] = true;
        dfs(y, x + 1, sum);
        sum -= rightDown(y, x);
        visited[y][x] = false;
        visited[y - 1][x] = false;
        visited[y][x - 1] = false;
    }
    if (y + 1 < n && x + 1 < m) {
        sum += leftUp(y, x);
        ans = max(ans, sum);
        visited[y][x] = true;
        visited[y - 1][x] = true;
        visited[y + 1][x] = true;
        dfs(y, x + 1, sum);
        sum -= leftUp(y,x);
        visited[y][x] = false;
        visited[y - 1][x] = false;
        visited[y + 1][x] = false;
    }
    if (y - 1 >= 0 && x + 1 < m) {
        sum += leftDown(y, x);
        ans = max(ans, sum);
        visited[y][x] = true;
        visited[y - 1][x] = true;
        visited[y][x + 1] = true;
        dfs(y, x + 1, sum);
        sum -= leftDown(y,x);
        visited[y][x] = false;
        visited[y - 1][x] = false;
        visited[y][x + 1] = false;
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
            cin >> Map[i][j];
        }
    }
    // 무기를 어떻게 만들지 골라야 함
    for (int i = 0; i < n; i++)
        if (!visited[i][0]) dfs(i, 0, ans);
    cout << ans;
    return 0;
}