#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n;
vector<int> v;
vector<int> lis;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    lis.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        if (lis.back() < v[i]) {  // lis의 맨 뒤 원소보다 더 큰 값이 들어오면 삽입
            lis.push_back(v[i]);
        } else {  // 작은 값이 들어오면
            int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[idx] = v[i];
        }
    }
    for(auto a:lis){
        cout<<a<<' ';
    }

    int answer = lis.size();
    cout <<endl<< answer;
    return 0;
}