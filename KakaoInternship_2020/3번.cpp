#include<bits/stdc++.h>
using namespace std;

map<string,vector<int>>m;
 map<string,int>uni_gems;
vector<int> solution(vector<string> gems) {
    vector<int> answer;   
    for(int i=0; i<gems.size(); i++){        
        m[gems[i]].push_back(i+1);  
    }
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[uni_gems[i]])
        cout<<m[uni_gems][i]<<' ';
    }

    return answer;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    vector<string> s;
    s = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int>ans = solution(s);
    //cout << ans[0]<<ans[1];
    return 0;
}