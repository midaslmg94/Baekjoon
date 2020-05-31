#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, m, k;
map<int, int> Map;
int key, value;
int oper;
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
            if (Map.count(change_key)) {  // 해당 key가 있으므로 값 변경
                Map[change_key] = change_value;
            } else {  // 해당 key가 없으므로 근접한 key를 찾아야 한다
                auto large_key = Map.lower_bound(change_key)->first;
                auto small_key = Map.lower_bound(change_key)->first;
                for (int j = change_key - 1; j > 0; j--) {
                    small_key = Map.lower_bound(j)->first;
                    if (large_key != small_key) {  // 찾으려는 key 보다 더 작은 key를 찾았음
                        break;
                    }
                }
                int large_diff = large_key - change_key;
                int small_diff = change_key - small_key;
                if (large_diff == small_diff)
                    break;  // 만족하는 key가 2개 -> 유일하지 않으므로 무시
                else if (large_diff < small_diff) {
                    if (large_diff <= k) {  // key의 차이가 K를 넘어가는 지 확인
                        Map[large_key] = change_value;                        
                    }
                }
                else {
                    if (small_diff<=k) {  // key의 차이가 K를 넘어가는 지 확인
                        Map[small_key] = change_value;                        
                    }
                }
            }
        } else {  // 데이터 출력
            int find_key;
            bool flag = true;
            cin >> find_key;
            if (Map.count(find_key)) {  // key가 있는 경우
                cout << Map[find_key] << endl;
            } else {  // key가 없는 경우 -> 조건 따지기
                auto large_key = Map.lower_bound(find_key)->first; // 만약 현재 맵에 있는 값보다 큰 값을 찾으려고 하면 key 값은 map.size()+1 이고 value는 0인 값이 들어간다
                auto small_key = Map.lower_bound(find_key)->first;
                for (int j = find_key - 1; j > 0; j--) {
                    small_key = Map.lower_bound(j)->first;
                    if (large_key != small_key) {  //
                        break;
                    }
                }
                int large_diff = large_key - find_key;
                int small_diff = find_key - small_key;

                //cout<<" large diff : "<<large_diff << " small diff : "<<small_diff<< ' ';

                if (large_diff == small_diff) {
                    cout << '?' << endl;
                } else if (large_diff < small_diff) {
                    if (large_diff > k) {  // key의 차이가 K를 넘어가는 지 확인
                        break;
                    }
                    flag = false;
                    cout << Map[large_key] << endl;
                } else {
                    if (small_diff > k) {  // key의 차이가 K를 넘어가는 지 확인
                        break;
                    }
                    flag = false;
                    cout << Map[small_key] << endl;
                }
            }
            if (flag) {  // 조건에 만족하는 key가 없음
                cout << -1 << endl;
            }
        //cout << ' ' << i << ' ' << "\n========\n";
        }
    }
        for (auto a : Map) {
           cout << a.first << ' ' << a.second << endl;
        }

    return 0;
}