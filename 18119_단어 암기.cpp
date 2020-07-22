#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, m;
int o;
char x;
string word;
vector<string> words;
bitset<27> alpha;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
    }
    alpha.set();  // 모든 단어는 우선 기억을 하고 있음
    for (int i = 0; i < m; i++) {
        cin >> o >> x;
        x = x - 97;
        if (o == 1) {  // 단어를 잊는다 -> bit를 0으로
            alpha.reset(x);
        } else {  // 단어를 기억한다 -> bit를 1로
            alpha.set(x);
        }
		
    }
    return 0;
}