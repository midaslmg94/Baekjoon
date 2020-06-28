#include <bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n, k;
map<char,int>knownWord; // 내가 알고 있는 단어
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string tmp="";
        for (int j = 4; j < s.size() - 4; j++) {
            tmp.push_back(s[j]);
        }
        words.push_back(tmp); // 필수 단어를 제외하고 들어감
    }
    // a:97 ~ z:122
    vector<int>alpha;
    for(int i=0; i<=26; i++){
        alpha.push_back(i);
    }    
    knownWord['a'] = 1;
    knownWord['c'] = 1;
    knownWord['i'] = 1;
    knownWord['n'] = 1;
    knownWord['t'] = 1; 
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<words[i].size(); j++){
            if(!knownWord.count(words[i][j])){
                // 필요한 단어 들
                cout<<words[i][j]-97<<' ';
                
            }
        }
        cout<<endl;
        
    }

    return 0;
}