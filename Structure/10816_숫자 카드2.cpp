#include<bits/stdc++.h>
#define endl "\n"
#define MAX 10
using namespace std;

int main() {	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	int n;    
    unordered_map<int, int>num; // num:num_count
    
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp; cin>>tmp;
        if(num.count(tmp)){
            num[tmp]++;
        }
        else{
            num[tmp]=1;
        }
    }
    int m;    
    cin>>m;
    for(int i=0; i<m; i++){
        int tmp; cin>>tmp;
        cout<<num[tmp]<<' ';
    }
    return 0;
}