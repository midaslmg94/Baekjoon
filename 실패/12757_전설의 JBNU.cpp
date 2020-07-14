#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, m, k;
map<int, int> Map;
int key, value;
int oper;
// 가장 가까운 데이터 찾기
void findKey(int start, int val) {
    bool flag_upper = false;
    bool flag_lower = false;
    if (val == -1) {  // 출력용
    
        for (int i = 1; i <= k; i++) {
            int upper = start + i;
            int lower = start - i;
            if (Map.count(upper)) {
                flag_upper = true;
            }
            if (Map.count(lower)) {
                flag_lower = true;
            }
            if (flag_upper && flag_lower) {  // 해당하는 Key가 2개이상
                cout << "?" << endl;
                return;
            }
            if (flag_upper) {
                cout << Map[upper] << endl;
                return;
            }
            if (flag_lower) {
                cout << Map[lower] << endl;
                return;
            }
        }
        cout << -1 << endl;  // 만족하는 key가 없음
        return;
    } else {  // 데이터 바꾸기 용
        for (int i = 1; i <= k; i++) {
            int upper = start + i;
            int lower = start - i;
            if (Map.count(upper)) {
                flag_upper = true;
            }
            if (Map.count(lower)) {
                flag_lower = true;
            }
            if (flag_upper && flag_lower) {  // 유일 key가 없음 -> 무시
                return;
            }
            if (flag_upper) {
                Map[upper] = val;
                return;
            }
            if (flag_lower) {
                Map[lower] = val;
                return;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> key >> value;
        Map[key] = value;
    }
    for (int i = 0; i < m; i++) {
        cin >> oper;
        if (oper == 1) {  // 새로운 데이터 추가
            int new_key, new_value;
            cin >> new_key >> new_value;
            Map[new_key] = new_value;
        } else if (oper == 2) {  // 데이터 변경
            int change_key, change_value;
            cin >> change_key >> change_value;
            if (Map.find(change_key) != Map.end()) {  // 데이터가 있음
                Map[change_key] = change_value;
            } else {
                findKey(change_key, change_value);
            }
        } else {  // 데이터 출력
            int find_key;
            cin >> find_key;
            if (Map.count(find_key)) {  // 데이터가 있음
                cout << Map[find_key] << endl;
            } else {
                findKey(find_key, -1);
            }
        }
    }

    return 0;
}