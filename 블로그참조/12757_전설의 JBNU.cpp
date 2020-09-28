#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
map<int, int> m1; // 위쪽으로 더 가까운 값 : key가 양수
map<int, int> m2; // 아래쪽으로 더 가까운 값 : key가 음수
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
        cin >> oper >> key;
        if (oper == 1) {  // 입력
            cin >> val;
            m1[key] = val;
            m2[-key] = val;
        } 
        // auto it = m1.lower_bound(key);
        // auto nit = m2.lower_bound(-key);
        // int diff = abs(it->first - key);
        // int ndiff = abs(key + nit->first);
        /*if(oper==2){
            cin>>val;
            if(diff > k && ndiff > k) continue;
            if(it->first != -nit->first && diff==ndiff)continue; // 왜지?
            if(diff>ndiff){ // 아래쪽이랑 가까움
                nit->second = val;
                m1[-(nit->first)] = val;
            }
            else if(diff<ndiff){
                it->second=val;
                m2[-(it->first)] = val;
            }
        }
        if(oper==3){
            if(diff>k && ndiff > k) cout<<"-1"<<endl;
            else if(it->first != -nit->first && diff==ndiff) cout<<"?"<<endl; // 왜지?..
            else if(diff>ndiff) cout<<nit->second<<endl; // 아래쪽
            else  cout<<it->second<<endl;
        }*/
        auto upper = m1.lower_bound(key);
        auto lower = m2.lower_bound(-key);        
        int up_diff = abs(upper->first - key);
        int low_diff = abs(key + lower->first);
        
        if (oper == 2) {  // 변경
            cin >> val; 
            if (up_diff < low_diff) {  // 위쪽이랑 더 가까움
                if (up_diff <= k) {
                    upper->second = val;
                    m2[-(upper->first)]=val;        
                }
            } 
            if(up_diff > low_diff) {  // 아래쪽이랑 더 가까움
                if (low_diff <= k) {
                    lower->second = val;
                    m1[-(lower->first)] = val;
                }
            }
        } 
        if(oper==3) {  // 출력          
            if (upper->first != -lower->first && up_diff == low_diff) {  // 중복 키
                cout << "?" << endl;
            } 
            else if(up_diff>k && low_diff>k) cout<<"-1"<<endl; // 범위 초과
            else if (up_diff < low_diff) {  // 위쪽이랑 더 가까움               
                cout << upper->second << endl;                                   
            }
            else {  // 아래쪽이랑 더 가까움               
                cout << lower->second << endl;               
            }
        }        
    }
    return 0;
}