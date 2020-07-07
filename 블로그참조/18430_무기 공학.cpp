#include <bits/stdc++.h>
#define MAX 6
#define endl "\n"
using namespace std;
int n, m;
int Map[MAX][MAX];
bool visited[MAX][MAX];
struct boo_type {   
    pair<int, int> points[3];  // 상or하 / 가운데 / 좌or우
    int sum;
};
vector<boo_type> boomerang;
vector<boo_type> sums;
int answer = 0;

bool cmp(boo_type a, boo_type b) {  // 합계가 큰 순서로 정렬
    return a.sum > b.sum;
}
bool isChecked(int idx) {
    if (visited[boomerang[idx].points[0].first][boomerang[idx].points[0].second] ||
        visited[boomerang[idx].points[1].first][boomerang[idx].points[1].second] ||
        visited[boomerang[idx].points[2].first][boomerang[idx].points[2].second]) return true;
    return false;
}
void getAnswer() {
    int sum = 0;
    for (int i = 0; i < sums.size(); i++)
        sum += sums[i].sum;
    answer = max(answer, sum);
}
void dfs(int idx) {
    visited[boomerang[idx].points[0].first][boomerang[idx].points[0].second] = true;
    visited[boomerang[idx].points[1].first][boomerang[idx].points[1].second] = true;
    visited[boomerang[idx].points[2].first][boomerang[idx].points[2].second] = true;
    for (int i = idx + 1; i < boomerang.size(); i++) {
        if (isChecked(i)) continue;
        sums.push_back(boomerang[i]);
        visited[boomerang[i].points[0].first][boomerang[i].points[0].second] = true;
        visited[boomerang[i].points[1].first][boomerang[i].points[1].second] = true;
        visited[boomerang[i].points[2].first][boomerang[i].points[2].second] = true;
        getAnswer();
        dfs(i);
        visited[boomerang[i].points[0].first][boomerang[i].points[0].second] = false;
        visited[boomerang[i].points[1].first][boomerang[i].points[1].second] = false;
        visited[boomerang[i].points[2].first][boomerang[i].points[2].second] = false;
        sums.pop_back();
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
    if (n < 2 || m < 2) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            // 중앙 : 왼쪽 위
            // ■□
            // □
            boo_type boo;
            boo.points[0] = {i, j + 1};
            boo.points[1] = {i, j};
            boo.points[2] = {i + 1, j};
            boo.sum = Map[boo.points[0].first][boo.points[0].second] +
                      Map[boo.points[1].first][boo.points[1].second] * 2 + Map[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);

            // 중앙 : 오른쪽 위
            // □■
            //  □
            boo.points[0] = {i, j};
            boo.points[1] = {i, j + 1};
            boo.points[2] = {i + 1, j + 1};
            boo.sum = Map[boo.points[0].first][boo.points[0].second] +
                      Map[boo.points[1].first][boo.points[1].second] * 2 + Map[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);

            // 중앙 : 왼쪽 아래
            // □
            // ■□
            boo.points[0] = {i, j};
            boo.points[1] = {i + 1, j};
            boo.points[2] = {i + 1, j + 1};
            boo.sum = Map[boo.points[0].first][boo.points[0].second] +
                      Map[boo.points[1].first][boo.points[1].second] * 2 + Map[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);

            // 중앙 : 오른쪽 아래
            //  □
            // □■
            boo.points[0] = {i, j + 1};
            boo.points[1] = {i + 1, j + 1};
            boo.points[2] = {i + 1, j};
            boo.sum = Map[boo.points[0].first][boo.points[0].second] +
                      Map[boo.points[1].first][boo.points[1].second] * 2 + Map[boo.points[2].first][boo.points[2].second];
            boomerang.push_back(boo);
        }
    }
    sort(boomerang.begin(), boomerang.end(), cmp);
    for (int i = 0; i < boomerang.size(); i++) {  // 부메랑 고르기
        boo_type tmp = boomerang[i];
        sums.push_back(tmp);
        dfs(i);
        sums.clear();
        memset(visited, false, sizeof(visited));
    }
    cout << answer;
    return 0;
}