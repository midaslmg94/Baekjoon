#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;
int n;
int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>n;
    map<char, int>m;
    vector<int>alpha;
    vector<string>alp;

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        alp.push_back(str);
        // 자릿수에 맞게 분리
        for(int j=0; j<str.size(); j++){
            int idx = str.size()-j;
            int cnt = pow(10,idx);
            m[str[j]]+=cnt;
        }
    }

    
	return 0;
}