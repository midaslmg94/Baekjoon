#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> str;
    int prev = 0;
    int cur = str.find(':');
    queue<string> q;
    while (cur != string::npos) {  // 문자열 끝까지 탐색
        string substring = str.substr(prev, cur - prev);
        cout << substring.size() << ' ';
        if (substring.size() == 0) {
            //continue;
        }
        q.push(substring);
        prev = cur + 1;
        cur = str.find(':', prev);
    }
    string last_str = str.substr(prev, cur - prev);
    cout << last_str.size();
    q.push(last_str);

    return 0;
}