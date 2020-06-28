#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int k, n;
vector<int> num;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> k >> n; // n장 중 k개를 선택
    for (int i = 0; i < k; i++) {
        int inp;
        cin >> inp;
        num.push_back(inp);
    }
    

    return 0;
}