#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
map<int, int> m1;
map<int, int> m2;
int n, m, k;
int key, val;
int oper;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        m1[key] = val;
        m2[-key] = val;
    }
    for (int i = 0; i < m; i++) {
        cin >> oper;
        if (oper == 1) {  // 입력
            cin >> key >> val;
            m1[key] = val;
            m2[-key] = val;
        } else if (oper == 2) {  // 변경
            cin >> key >> val;
            auto upper = m1.lower_bound(key);
            auto lower = m2.lower_bound(-key);
            int up_key = upper->first;
            int low_key = -lower->first;
            if (up_key - key <= key - low_key) {  // 위쪽이랑 더 가까움
                if (up_key - key <= k) {
                    m1[up_key] = val;
                    m2[-up_key] = val;
                }
            } else {  // 아래쪽이랑 더 가까움
                if (key - low_key <= k) {
                    m1[low_key] = val;
                    m2[-low_key] = val;
                }
            }
        } else {  // 출력
            cin >> key;
            auto upper = m1.lower_bound(key);
            auto lower = m2.lower_bound(-key);
            int up_key = upper->first;
            int low_key = -lower->first;
            if (up_key == low_key) {  // 중복 키
                cout << "?" << endl;
            } else if (up_key - key < key - low_key) {  // 위쪽이랑 더 가까움
                if (up_key - key <= k) {
                    cout << upper->second << endl;
                } else {
                    cout << -1 << endl;
                }
            } else if (up_key - key > key - low_key) {  // 아래쪽이랑 더 가까움
                if (key - low_key <= k) {
                    cout << lower->second << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}