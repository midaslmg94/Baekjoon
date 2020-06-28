#include <bits/stdc++.h>
#define endl "\n"
#define MAX 2001
using namespace std;
vector<pair<int, int>> ball[MAX];  // 볼의 크기
int answer[MAX];
int n, c, s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> s;              // 색, 크기
        ball[s].push_back({c, i});  // first:공 색깔, second: 플레이어 번호
    }
    for (int i = 0; i < MAX; i++) {
        sort(ball[i].begin(), ball[i].end());
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < ball[i].size(); j++) {
            int cur_player = ball[i][j].second;
            int cur_color = ball[i][j].first;
            int cur_score = 0;
            for (int k = 0; k < i; k++) {
                auto cnt = upper_bound(ball[i].begin(), ball[i].end(), cur_color) - lower_bound(ball[i].begin(), ball[i].end(), cur_color);
                cur_score += (ball[i].size() - cnt) * i;
            }
            answer[cur_player] = cur_score;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
    return 0;
}