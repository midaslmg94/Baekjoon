#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int input_a, input_b, input_c, input_d;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> AB;  // a와 b 합친 것
vector<int> CD;  // c와 d 합친 것
long long answer = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input_a >> input_b >> input_c >> input_d;
        a.push_back(input_a);
        b.push_back(input_b);
        c.push_back(input_c);
        d.push_back(input_d);
    }
    for (int i = 0; i < n; i++) {  // 최대 1600만 : 여기까진 시간복잡도 Ok
        for (int j = 0; j < n; j++) {
            AB.push_back(a[i] + b[j]);
            CD.push_back(c[i] + d[j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    for (int i = 0; i < AB.size(); i++) {
        int cur = AB[i];
        auto up = upper_bound(CD.begin(), CD.end(), -cur);
        auto low = lower_bound(CD.begin(), CD.end(), -cur);
        answer += up - low;
    }
    cout << answer;
    return 0;
}