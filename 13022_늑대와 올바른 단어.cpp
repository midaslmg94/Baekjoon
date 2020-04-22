#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    vector<int> W;
    vector<int> O;
    vector<int> L;
    vector<int> F;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'w') {
            W.push_back(i);
        } else if (str[i] == 'o') {
            O.push_back(i);
        } else if (str[i] == 'l') {
            L.push_back(i);
        } else if (str[i] == 'f') {
            F.push_back(i);
        }
    }
    if (W.size() == O.size() && O.size() == L.size() && L.size() == F.size()) {  // 사용된 단어의 개수가 같아야 함
        for (int i = 0; i < W.size(); i++) {
            int dist = O[i] - W[i];
            if (dist < 0 || L[i] - O[i] != dist || F[i] - L[i] != dist) { // dist<0 인 경우는 flow 처럼 순서가 안맞는 경우
                cout << 0;
                return 0;
            }
        }
    } else {  // 사용된 단어의 개수가 다름 -> 무조건 틀림
        cout << 0;
        return 0;
    }
    cout << 1;
    return 0;
}