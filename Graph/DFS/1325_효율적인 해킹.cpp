#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10000 + 1
using namespace std;
vector<int> arr[MAX];
bool visited[MAX];
int n, m;
int a, b;
int idx = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int dfs(int start) {
    visited[start]=true;
    for (int i = 0; i < arr[start].size(); i++) {
        int nx = arr[start][i];
        if (!visited[nx]) {            
            idx++;
            dfs(arr[start][i]);
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b].push_back(a);  // b는 a를 해킹할 수 있다
    }

    vector<pair<int, int>> ans; // 깊이, 컴퓨터 번호
    for (int i = 1; i <= n; i++) {
        if (arr[i].size() == 0) continue;        
        ans.push_back({dfs(i), i});
        memset(visited, false, sizeof(visited));
        idx = 0;
    }

    sort(ans.begin(), ans.end(), cmp);
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << ans[i].first << ' ' << ans[i].second << endl;
    // }
    int tmp = ans[0].first;
    for (int i = 0; i < n; i++) {
        if (tmp == ans[i].first) {
            cout << ans[i].second << ' ';
        } else {
            break;
        }
    }
    return 0;
}