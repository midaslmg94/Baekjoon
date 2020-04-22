#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int input_a, input_b, input_c, input_d;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> AB;  // a�� b ��ģ ��
vector<int> CD;  // c�� d ��ģ ��
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
    for (int i = 0; i < n; i++) {  // �ִ� 1600�� : ������� �ð����⵵ Ok
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